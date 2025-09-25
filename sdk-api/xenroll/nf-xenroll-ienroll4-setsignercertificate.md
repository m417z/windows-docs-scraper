# IEnroll4::SetSignerCertificate

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **SetSignerCertificate** method specifies the signer's certificate. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `pSignerCert` [in]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that represents the signer's certificate.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)