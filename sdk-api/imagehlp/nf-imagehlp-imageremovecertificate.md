# ImageRemoveCertificate function

## Description

Removes the specified certificate from the given file.

## Parameters

### `FileHandle` [in]

A handle to the image file to be modified. This handle must be opened for FILE_READ_DATA and FILE_WRITE_DATA access.

### `Index` [in]

The index of the certificate to be removed.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageAddCertificate](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageaddcertificate)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)