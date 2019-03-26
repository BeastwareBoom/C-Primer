
//#ifdef WIN32

#ifdef MathFunctions_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

//#endif

// STATIC lib 无需以上声明及EXPORT
EXPORT double mysqrt(double x);
