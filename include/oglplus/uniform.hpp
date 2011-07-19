/**
 *  @file oglplus/uniform.hpp
 *  @brief Uniform wrappers
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2011 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef OGLPLUS_UNIFORM_1107121519_HPP
#define OGLPLUS_UNIFORM_1107121519_HPP

#include <oglplus/error.hpp>
#include <oglplus/friend_of.hpp>
#include <oglplus/program.hpp>
#include <oglplus/auxiliary/shader_data.hpp>

#include <string>

namespace oglplus {

class UniformOps
 : public FriendOf<Program>
{
protected:
	GLint _index;

	friend class FriendOf<UniformOps>;

	UniformOps(const Program& program, const GLchar* identifier)
	 : _index(
		::glGetUniformLocation(
			FriendOf<Program>::GetName(program),
			identifier
		)
	)
	{
		ThrowOnError(OGLPLUS_ERROR_INFO());
		assert(_index != GLint(-1));
	}
public:
};

namespace aux {

class UniformSetters
{
protected:
	OGLPLUS_AUX_VARPARA_FNS(Uniform, f, t, GLfloat)
	OGLPLUS_AUX_VARPARA_FNS(Uniform, d, t, GLdouble)

	OGLPLUS_AUX_VARPARA_FNS(Uniform, fv, v, GLfloat)
	OGLPLUS_AUX_VARPARA_FNS(Uniform, dv, v, GLdouble)
};

class UniformMatrixSetters
{
protected:
	OGLPLUS_AUX_VARPARA_MAT_FNS(UniformMatrix, fv, v, GLfloat)
	OGLPLUS_AUX_VARPARA_MAT_FNS(UniformMatrix, dv, v, GLdouble)
};

} // namespace aux

class Uniform
 : public UniformOps
 , public aux::ShaderDataSetOps<aux::UniformSetters, 4>
 , public aux::ShaderMatrixSetOps<aux::UniformMatrixSetters>
{
public:
	Uniform(const Program& program, const GLchar* identifier)
	 : UniformOps(program, identifier)
	{ }

	template <typename ... T>
	void Set(T ... v) const
	{
		this->_do_set(_index, v...);
	}

	template <size_t N, typename T>
	void Set(const T* v) const
	{
		this->_do_set<N>(_index, v);
	}

	template <size_t Cols, typename ... T>
	void SetMatrix(T ... v) const
	{
		this->_do_set_mat<Cols>(_index, false, v...);
	}

	template <size_t Cols, size_t Rows, typename T>
	void SetMatrix(size_t count, const T* v) const
	{
		this->_do_set_mat<Cols, Rows>(_index, false, count, v);
	}
};

} // namespace oglplus

#endif // include guard
