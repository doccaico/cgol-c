#ifndef UTILS_H
#define UTILS_H

#if defined(PLATFORM_WEB)
# define NODEFAULT {}
#else

#ifdef DEBUG
// This code is supposed to be unreachable, so assert
// https://learn.microsoft.com/ja-jp/cpp/intrinsics/assume?view=msvc-170
# define NODEFAULT assert(0)
#else
# define NODEFAULT __assume(0)
#endif

#endif

#endif // UTILS_H
