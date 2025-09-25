# ImageEnumerateCertificates function

## Description

Retrieves information about the certificates currently contained in an image file.

## Parameters

### `FileHandle` [in]

A handle to the image file to be examined. This handle must be opened for FILE_READ_DATA access.

### `TypeFilter` [in]

The certificate section type to be used as a filter when returning certificate information. CERT_SECTION_TYPE_ANY should be passed for information on all section types present in the image.

### `CertificateCount` [out]

A pointer to a variable that receives the number of certificates in the image containing sections of the type specified by the *TypeFilter* parameter. If none are found, this parameter is zero.

### `Indices` [in, out]

Optionally provides a buffer to use to return an array of indices to the certificates containing sections of the specified type. No ordering should be assumed for the index values, nor are they guaranteed to be contiguous when CERT_SECTION_TYPE_ANY is queried.

### `IndexCount` [in, optional]

The size of the *Indices* buffer, in **DWORDs**. This parameter will be examined whenever *Indices* is present. If *CertificateCount* is greater than *IndexCount*, *Indices* will be filled in with the first *IndexCount* sections found in the image; any others will not be returned.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**ImageEnumerateCertificates** function returns information about the certificates currently contained in an image file. It has filtering capabilities which allow certificates containing sections of any single type (or of any type) to be returned.

After the indices of interesting certificates are discovered, they can be passed to the
[ImageGetCertificateData](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imagegetcertificatedata) function to obtain the actual bodies of the certificates.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageGetCertificateData](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imagegetcertificatedata)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)