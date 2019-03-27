
//如果是windows platform
#ifdef WIN32
//Typical pattern: <target-name>_EXPORTS
#ifdef MathFunctions_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
//其他platform
#else
#define EXPORT
#endif

// STATIC lib 无需以上声明及EXPORT
EXPORT double mysqrt(double x);
