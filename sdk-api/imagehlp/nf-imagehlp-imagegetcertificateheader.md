# ImageGetCertificateHeader function

## Description

Retrieves the header of the specified certificate, up to, but not including, the section offset array.

## Parameters

### `FileHandle` [in]

A handle to the image file. This handle must be opened for FILE_READ_DATA access.

### `CertificateIndex` [in]

The index of the certificate whose header is to be returned.

### `Certificateheader` [in, out]

A pointer to the **WIN_CERTIFICATE** structure that receives the certificate header.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)