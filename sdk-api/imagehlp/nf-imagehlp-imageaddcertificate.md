# ImageAddCertificate function

## Description

Adds a certificate to the specified file.

## Parameters

### `FileHandle` [in]

A handle to the image file to be modified. This handle must be opened for FILE_READ_DATA and FILE_WRITE_DATA access.

### `Certificate` [in]

A pointer to a **WIN_CERTIFICATE** header and all associated sections. The **Length** member in the certificate header will be used to determine the length of this buffer.

### `Index` [out]

A pointer to a variable that receives the index of the newly added certificate.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The certificate is added at the end of the existing list of certificates and is assigned an index.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[ImageRemoveCertificate](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageremovecertificate)