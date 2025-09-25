# IX509CertificateRequestPkcs7V2::CheckCertificateSignature

## Description

The **CheckCertificateSignature** method verifies the certificate signature.

## Parameters

### `ValidateCertificateChain` [in]

A Boolean value that specifies whether to also verify the certificate chain. This parameter can be **NULL**.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | A signer certificate cannot be found. |

## Remarks

A PKCS #7 request has exactly one certificate-based signature.

## See also

[IX509CertificateRequestPkcs7V2](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7v2)