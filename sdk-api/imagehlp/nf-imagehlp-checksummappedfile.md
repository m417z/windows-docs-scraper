# CheckSumMappedFile function

## Description

Computes the checksum of the specified image file.

## Parameters

### `BaseAddress` [in]

The base address of the mapped file. This value is obtained by calling the
[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) function.

### `FileLength` [in]

The size of the file, in bytes.

### `HeaderSum` [out]

A pointer to a variable that receives the original checksum from the image file, or zero if there is an error.

### `CheckSum` [out]

A pointer to the variable that receives the computed checksum.

## Return value

If the function succeeds, the return value is a pointer to the
[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32) structure contained in the mapped image.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**CheckSumMappedFile** function computes a new checksum for the file and returns it in the *CheckSum* parameter. This function is used by any application that creates or modifies an executable image. Checksums are required for kernel-mode drivers and some system DLLs. The linker computes the original checksum at link time, if you use the appropriate linker switch. For more details, see your linker documentation.

It is recommended that all images have valid checksums. It is the caller's responsibility to place the newly computed checksum into the mapped image and update the on-disk image of the file.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[MapFileAndCheckSum](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-mapfileandchecksuma)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)