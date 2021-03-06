/*
 *  .file eglplus/enums/texture_target_range.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/eglplus/texture_target.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

namespace enums {
EGLPLUS_LIB_FUNC aux::CastIterRange<
	const EGLenum*,
	TextureTarget
> _ValueRange(TextureTarget*)
#if (!EGLPLUS_LINK_LIBRARY || defined(EGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(EGLPLUS_IMPL_EVR_TEXTURETARGET)
#define EGLPLUS_IMPL_EVR_TEXTURETARGET
{
static const EGLenum _values[] = {
#if defined EGL_NO_TEXTURE
EGL_NO_TEXTURE,
#endif
#if defined EGL_TEXTURE_2D
EGL_TEXTURE_2D,
#endif
0
};
return aux::CastIterRange<
	const EGLenum*,
	TextureTarget
>(_values, _values+sizeof(_values)/sizeof(_values[0])-1);
}
#else
;
#endif
} // namespace enums

