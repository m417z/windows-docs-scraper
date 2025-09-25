# ImageRvaToVa function

## Description

Locates a relative virtual address (RVA) within the image header of a file that is mapped as a file and returns the virtual address of the corresponding byte in the file.

## Parameters

### `NtHeaders` [in]

A pointer to an
[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32) structure. This structure can be obtained by calling the
[ImageNtHeader](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagentheader) function.

### `Base` [in]

The base address of an image that is mapped into memory through a call to the
[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) function.

### `Rva` [in]

The relative virtual address to be located.

### `LastRvaSection` [in, optional]

A pointer to an
[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header) structure that specifies the last RVA section. This is an optional parameter. When specified, it points to a variable that contains the last section value used for the specified image to translate an RVA to a VA.

## Return value

If the function succeeds, the return value is the virtual address in the mapped file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**ImageRvaToVa** function locates an RVA within the image header of a file that is mapped as a file and returns the virtual address of the corresponding byte in the file.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32)

[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header)

[ImageNtHeader](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagentheader)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)