# IX509SCEPEnrollment::Initialize

## Description

Initialize the instance in preparation for a new request.

## Parameters

### `pRequest` [in]

An instance of a request that has already been initialized.

### `strThumbprint` [in]

The CA certificate thumbprint.

### `ThumprintEncoding` [in]

The encoding of the CA certificate thumbprint.

### `strServerCertificates` [in]

A PKCS7 request with CA and SCEP RA certificates.

### `Encoding` [in]

The encoding type of the request.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method expects an SCEP server signature EA certificate and an SCEP server encryption EA certificate, both signed by the CA certificate.

This method fails if any of the expected certificates is missing, or if the thumbprint doesn't match the CA certificate.

## See also

[IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment)