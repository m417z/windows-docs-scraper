# ImageRvaToSection function

## Description

Locates a relative virtual address (RVA) within the image header of a file that is mapped as a file and returns a pointer to the section table entry for that RVA.

## Parameters

### `NtHeaders` [in]

A pointer to an
[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32) structure. This structure can be obtained by calling the
[ImageNtHeader](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagentheader) function.

### `Base` [in]

This parameter is reserved.

### `Rva` [in]

The relative virtual address to be located.

## Return value

If the function succeeds, the return value is a pointer to an
[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header) structure.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32)

[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header)

[ImageNtHeader](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagentheader)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)