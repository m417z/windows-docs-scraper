# IX509SCEPEnrollment::CreateRetrieveCertificateMessage

## Description

Retrieve a previously issued certificate.

## Parameters

### `Context` [in]

### `strIssuer` [in]

ASN.1 encoded issuer name.

### `IssuerEncoding` [in]

### `strSerialNumber` [in]

### `SerialNumberEncoding` [in]

### `Encoding` [in]

### `pValue` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must call the [InitializeForPending](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-initializeforpending) method before calling this method.

## See also

[IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment)