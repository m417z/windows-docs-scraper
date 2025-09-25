# ImagehlpApiVersionEx function

## Description

Modifies the version information of the library used by the application.

## Parameters

### `AppVersion` [in]

A pointer to an
[API_VERSION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-api_version) structure that contains valid version information for your application.

## Return value

The return value is a pointer to an
[API_VERSION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-api_version) structure.

## Remarks

Use the
**ImagehlpApiVersionEx** function to indicate the version of the library with which the application was built. The library uses this information to ensure compatibility. For example, consider walking through kernel-mode callback stack frames (User and GDI exist in kernel mode). If you call
**ImagehlpApiVersionEx** to set the **Revision** member to version 4 or later, the
[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk) function will continue through a callback stack frame. Otherwise, if you set **Revision** to a version earlier than 4,
**StackWalk64** will stop at the kernel transition.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[API_VERSION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-api_version)

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[ImagehlpApiVersion](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagehlpapiversion)