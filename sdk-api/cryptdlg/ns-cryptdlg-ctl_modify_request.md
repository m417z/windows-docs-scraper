# CTL_MODIFY_REQUEST structure

## Description

The **CTL_MODIFY_REQUEST** structure contains a request to modify a certificate trust list (CTL). This structure is used in the [CertModifyCertificatesToTrust](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certmodifycertificatestotrust) function.

## Members

### `pccert`

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the certificate to change the trust on.

### `dwOperation`

The operation to be performed. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CTL_MODIFY_REQUEST_ADD_TRUSTED** | Add the certificate to the CTL. The certificate is explicitly trusted. |
| **CTL_MODIFY_REQUEST_ADD_NOT_TRUSTED** | Add the certificate to the Untrusted Certificates certificate store. The certificate is explicitly not trusted. |
| **CTL_MODIFY_REQUEST_REMOVE** | Remove the certificate from the CTL. The certificate is neither explicitly trusted nor untrusted. To be trusted, the certificate must have a trusted root certificate at the root of its certificate chain. |

### `dwError`

The error code generated for this operation.

## See also

[CertModifyCertificatesToTrust](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certmodifycertificatestotrust)