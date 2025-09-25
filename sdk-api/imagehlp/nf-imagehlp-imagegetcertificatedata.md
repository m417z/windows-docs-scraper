# ImageGetCertificateData function

## Description

Retrieves a complete certificate from a file.

## Parameters

### `FileHandle` [in]

A handle to the image file. This handle must be opened for **FILE_READ_DATA** access.

### `CertificateIndex` [in]

The index of the certificate to be returned.

### `Certificate` [out]

A pointer to a **WIN_CERTIFICATE** structure that receives the certificate data. If the buffer is not large enough to contain the structure, the function fails and the last error code is set to **ERROR_INSUFFICIENT_BUFFER**.

### `RequiredLength` [in, out]

On input, this parameter specifies the length of the *Certificate* buffer in bytes. On success, it receives the length of the certificate.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **WIN_CERTIFICATE** structure is defined as follows:

```cpp
typedef struct _WIN_CERTIFICATE {
    DWORD       dwLength;
    WORD        wRevision;
    WORD        wCertificateType;   // WIN_CERT_TYPE_xxx
    BYTE        bCertificate[ANYSIZE_ARRAY];
} WIN_CERTIFICATE, *LPWIN_CERTIFICATE;
```

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)