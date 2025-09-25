# MapDebugInformation function

## Description

Obtains access to the debugging information for an image.

**Note** This function is provided only for backward compatibility. It does not return reliable information. New applications should use the
[SymGetModuleInfo64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetmoduleinfo) and
[SymLoadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmodule) functions.

## Parameters

### `FileHandle` [in, optional]

A handle to an open executable image or **NULL**.

### `FileName` [in]

The name of an executable image file or **NULL**.

### `SymbolPath` [in, optional]

The path where symbol files are located. The path can be multiple paths separated by semicolons. To retrieve the symbol path, use the
[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath) function.

### `ImageBase` [in]

The base address for the image or zero.

## Return value

If the function succeeds, the return value is a pointer to an
[IMAGE_DEBUG_INFORMATION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-image_debug_information) structure.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**MapDebugInformation** function is used to obtain access to an image's debugging information. The debugging information is extracted from the image or the symbol file and placed into the
[IMAGE_DEBUG_INFORMATION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-image_debug_information) structure. This structure is allocated by the library and must be deallocated by using the
[UnmapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-unmapdebuginformation) function. The memory for the structure is not in the process's default heap, so attempts to free it with a memory deallocation routine will fail.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGE_DEBUG_INFORMATION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-image_debug_information)

[SymGetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsearchpath)

[UnmapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-unmapdebuginformation)