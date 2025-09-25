# UpdateDebugInfoFile function

## Description

Uses the specified information to update the corresponding fields in the symbol file.

**Note** This function works with .dbg files, not .pdb files.

This function has been superseded by the
[UpdateDebugInfoFileEx](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-updatedebuginfofileex) function. Use
**UpdateDebugInfoFileEx** to verify the checksum value.

## Parameters

### `ImageFileName` [in]

The name of the image that is now out of date with respect to its symbol file.

### `SymbolPath` [in]

The path in which to look for the symbol file.

### `DebugFilePath` [out]

A pointer to a buffer that receives the name of the symbol file that was updated.

### `NtHeaders` [in]

A pointer to an
[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32) structure that specifies the new header information.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**UpdateDebugInfoFile** function takes the information stored in the
[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32) structure and updates the corresponding fields in the symbol file. Any time an image file is modified, this function should be called to keep the numbers in sync. Specifically, whenever an image checksum changes, the symbol file should be updated to match.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[UpdateDebugInfoFileEx](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-updatedebuginfofileex)