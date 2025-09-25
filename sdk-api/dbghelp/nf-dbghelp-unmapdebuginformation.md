# UnmapDebugInformation function

## Description

Deallocates the memory and resources allocated by a call to the
[MapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-mapdebuginformation) function.

**Note** This function is provided only for backward compatibility. New applications should use the
[SymUnloadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symunloadmodule) function.

## Parameters

### `DebugInfo` [in]

A pointer to an
[IMAGE_DEBUG_INFORMATION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-image_debug_information) structure that is returned from a call to
[MapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-mapdebuginformation).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**UnmapDebugInformation** function is the counterpart to the
[MapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-mapdebuginformation) function and must be used to deallocate the memory and resources allocated by a call to the
[MapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-mapdebuginformation) function.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGE_DEBUG_INFORMATION](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-image_debug_information)

[MapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-mapdebuginformation)