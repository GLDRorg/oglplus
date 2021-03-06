/*
 *  .file eglplus/enums/opengl_rns_def.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/eglplus/opengl_rns.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifdef EGLPLUS_LIST_NEEDS_COMMA
# undef EGLPLUS_LIST_NEEDS_COMMA
#endif

#if defined EGL_NO_RESET_NOTIFICATION_KHR
# if EGLPLUS_LIST_NEEDS_COMMA
   EGLPLUS_ENUM_CLASS_COMMA
# endif
# if defined NoResetNotification
#  pragma push_macro("NoResetNotification")
#  undef NoResetNotification
   EGLPLUS_ENUM_CLASS_VALUE(NoResetNotification, EGL_NO_RESET_NOTIFICATION_KHR)
#  pragma pop_macro("NoResetNotification")
# else
   EGLPLUS_ENUM_CLASS_VALUE(NoResetNotification, EGL_NO_RESET_NOTIFICATION_KHR)
# endif
# ifndef EGLPLUS_LIST_NEEDS_COMMA
#  define EGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#if defined EGL_LOSE_CONTEXT_ON_RESET_KHR
# if EGLPLUS_LIST_NEEDS_COMMA
   EGLPLUS_ENUM_CLASS_COMMA
# endif
# if defined LoseContextOnReset
#  pragma push_macro("LoseContextOnReset")
#  undef LoseContextOnReset
   EGLPLUS_ENUM_CLASS_VALUE(LoseContextOnReset, EGL_LOSE_CONTEXT_ON_RESET_KHR)
#  pragma pop_macro("LoseContextOnReset")
# else
   EGLPLUS_ENUM_CLASS_VALUE(LoseContextOnReset, EGL_LOSE_CONTEXT_ON_RESET_KHR)
# endif
# ifndef EGLPLUS_LIST_NEEDS_COMMA
#  define EGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#ifdef EGLPLUS_LIST_NEEDS_COMMA
# undef EGLPLUS_LIST_NEEDS_COMMA
#endif

