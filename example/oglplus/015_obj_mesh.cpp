/**
 *  @example oglplus/015_obj_mesh.cpp
 *  @brief Shows how to use the obj file mesh loader
 *
 *  @oglplus_screenshot{015_obj_mesh}
 *
 *  Copyright 2008-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 *  @oglplus_example_uses_gl{GL_VERSION_3_0}
 *  @oglplus_example_uses_model{suzanne}
 */
#include <oglplus/gl.hpp>
#include <oglplus/all.hpp>
#include <oglplus/shapes/obj_mesh.hpp>
#include <oglplus/opt/resources.hpp>

#include <cmath>

#include "example.hpp"

namespace oglplus {

struct MeshInputFile
{
	std::ifstream stream;

	MeshInputFile(void)
	{
		OpenResourceFile(stream, "models", "suzanne", ".obj");
	}
};

class MeshExample : public Example
{
private:
	MeshInputFile mesh_input;
	shapes::ObjMesh load_mesh;
	shapes::DrawingInstructions mesh_instr;
	shapes::ObjMesh::IndexArray mesh_indices;

	Context gl;

	Program prog;

	LazyUniform<Mat4f> camera_matrix;

	VertexArray mesh;
	Vec4f mesh_bs;

	Buffer positions;
	Buffer normals;
	Buffer texcoords;
public:
	MeshExample(void)
	 : load_mesh(mesh_input.stream)
	 , mesh_instr(load_mesh.Instructions())
	 , mesh_indices(load_mesh.Indices())
	 , camera_matrix(prog, "CameraMatrix")
	{
		load_mesh.BoundingSphere(mesh_bs);

		VertexShader vs;
		vs.Source(
			"#version 330\n"
			"uniform mat4 ProjectionMatrix, CameraMatrix;"
			"in vec4 Position;"
			"in vec3 Normal;"

			"out vec3 vertNormal;"
			"void main(void)"
			"{"
			"	vertNormal = Normal;"
			"	gl_Position = "
			"		ProjectionMatrix *"
			"		CameraMatrix *"
			"		Position;"
			"}"
		).Compile();

		FragmentShader fs;
		fs.Source(
			"#version 330\n"
			"in vec3 vertNormal;"
			"out vec3 fragColor;"
			"void main(void)"
			"{"
			"	vec3 c = normalize(vec3(1, 1, 1) - vertNormal);"
			"	fragColor = c;"
			"}"
		).Compile();

		prog.AttachShader(vs).AttachShader(fs);
		prog.Link().Use();

		mesh.Bind();

		positions.Bind(Buffer::Target::Array);
		{
			std::vector<GLfloat> data;
			GLuint n_per_vertex = load_mesh.Positions(data);
			Buffer::Data(Buffer::Target::Array, data);
			(prog|"Position").Setup<GLfloat>(n_per_vertex).Enable();
		}

		normals.Bind(Buffer::Target::Array);
		{
			std::vector<GLfloat> data;
			GLuint n_per_vertex = load_mesh.Normals(data);
			Buffer::Data(Buffer::Target::Array, data);
			(prog|"Normal").Setup<GLfloat>(n_per_vertex).Enable();
		}

		//
		gl.ClearColor(0.8f, 0.8f, 0.7f, 0.0f);
		gl.ClearDepth(1.0f);
		gl.Enable(Capability::DepthTest);
	}

	void Reshape(GLuint width, GLuint height)
	{
		gl.Viewport(width, height);
		prog.Use();
		Uniform<Mat4f>(prog, "ProjectionMatrix").Set(
			CamMatrixf::PerspectiveX(
				Degrees(70),
				double(width)/height,
				1, 20
			)
		);
	}

	void Render(double time)
	{
		gl.Clear().ColorBuffer().DepthBuffer();
		//
		camera_matrix.Set(
			CamMatrixf::Orbiting(
				mesh_bs.xyz(),
				mesh_bs.w()*1.4+1.0,
				FullCircles(time / 13.0),
				Degrees(SineWave(time / 17.0) * 90)
			)
		);

		mesh_instr.Draw(mesh_indices);
	}

	bool Continue(double time)
	{
		return time < 30.0;
	}
};

void setupExample(ExampleParams& /*params*/){ }

std::unique_ptr<ExampleThread> makeExampleThread(
	Example& /*example*/,
	unsigned /*thread_id*/,
	const ExampleParams& /*params*/
){ return std::unique_ptr<ExampleThread>(); }

std::unique_ptr<Example> makeExample(const ExampleParams& /*params*/)
{
	return std::unique_ptr<Example>(new MeshExample);
}

} // namespace oglplus
