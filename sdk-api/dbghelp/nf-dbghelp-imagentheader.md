# ImageNtHeader function

## Description

Locates the
[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32) structure in a PE image and returns a pointer to the data.

## Parameters

### `Base` [in]

The base address of an image that is mapped into memory by a call to the
[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) function.

## Return value

If the function succeeds, the return value is a pointer to an
[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32) structure.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)