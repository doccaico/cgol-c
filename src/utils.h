#ifndef UTILS_H
#define UTILS_H

#if !defined(PLATFORM_WEB)

#ifdef DEBUG
// This code is supposed to be unreachable, so assert
// https://learn.microsoft.com/ja-jp/cpp/intrinsics/assume?view=msvc-170
# define NODEFAULT assert(0)
#else
# define NODEFAULT __assume(0)
#endif

#else

# define NODEFAULT {}

#endif

#endif // UTILS_H
