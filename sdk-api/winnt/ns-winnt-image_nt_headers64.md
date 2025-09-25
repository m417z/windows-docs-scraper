# IMAGE_NT_HEADERS64 structure

## Description

Represents the PE header format.

## Members

### `Signature`

A 4-byte signature identifying the file as a PE image. The bytes are "PE\0\0".

### `FileHeader`

An
[IMAGE_FILE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_file_header) structure that specifies the file header.

### `OptionalHeader`

An
[IMAGE_OPTIONAL_HEADER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_optional_header32) structure that specifies the optional file header.

## Remarks

The actual structure in WinNT.h is named **IMAGE_NT_HEADERS32** and **IMAGE_NT_HEADERS** is defined as **IMAGE_NT_HEADERS32**. However, if _WIN64 is defined, then **IMAGE_NT_HEADERS** is defined as **IMAGE_NT_HEADERS64**.

```cpp
typedef struct _IMAGE_NT_HEADERS64 {
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;
```

## See also

[CheckSumMappedFile](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-checksummappedfile)

[IMAGE_FILE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_file_header)

[IMAGE_OPTIONAL_HEADER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_optional_header32)

[ImageHlp Structures](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-structures)

[ImageNtHeader](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagentheader)

[ImageRvaToSection](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagervatosection)

[ImageRvaToVa](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagervatova)

[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image)

[UpdateDebugInfoFile](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-updatedebuginfofile)