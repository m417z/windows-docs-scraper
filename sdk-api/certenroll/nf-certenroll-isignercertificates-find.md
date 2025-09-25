# ISignerCertificates::Find

## Description

The **Find** method retrieves the index number of an [ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate) object.

## Parameters

### `pSignerCert` [in]

Pointer to the [ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate) interface.

### `piSignerCert` [out]

Pointer to a **LONG** variable that receives the index number.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)

[ISignerCertificates](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificates)