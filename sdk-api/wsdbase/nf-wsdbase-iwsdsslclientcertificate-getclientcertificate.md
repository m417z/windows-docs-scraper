# IWSDSSLClientCertificate::GetClientCertificate

## Description

Gets the client certificate.

## Parameters

### `ppCertContext` [in, out]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the client SSL certificate. Upon completion, the caller should free this memory by calling [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext).

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTFOUND** | A certificate is not available. |

## See also

[IWSDSSLClientCertificate](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdsslclientcertificate)