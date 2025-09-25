# ImagehlpApiVersion function

## Description

Retrieves the version information of the DbgHelp library installed on the system.

To indicate the version of the library with which the application was built, use the
[ImagehlpApiVersionEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagehlpapiversionex) function.

## Return value

The return value is a pointer to an
[API_VERSION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-api_version) structure.

## Remarks

Use the information in the
[API_VERSION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-api_version) structure to determine whether the version of the library installed on the system is compatible with the version of the library used by the application. Although the library functions are backward compatible, functions introduced in one version are obviously not available in earlier versions.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[API_VERSION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-api_version)

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[ImagehlpApiVersionEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagehlpapiversionex)