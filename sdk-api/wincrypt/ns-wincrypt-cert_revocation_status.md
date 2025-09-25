# CERT_REVOCATION_STATUS structure

## Description

The **CERT_REVOCATION_STATUS** structure contains information on the revocation status of the certificate. It is passed to and returned by
[CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation). On return from the function, it specifies the status of a revoked or unchecked context.

## Members

### `cbSize`

Size of this structure in bytes.

Upon input to
**CERT_REVOCATION_STATUS**, **cbSize** must be set to a size greater than or equal to the size of a **CERT_REVOCATION_STATUS** structure. Otherwise, **CERT_REVOCATION_STATUS** returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns E_INVALIDARG.

### `dwIndex`

Specifies an index value for the *rgpvContext* array passed to
[CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation). It is the index of the first [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) in that array that was revoked or that could not be checked for revocation. For information about the contexts that were not checked, **CertVerifyRevocation** is called again, specifying a *rgpvContext* array that contains the unchecked contexts from the original list.

### `dwError`

Specifies the returned error status. This value matches the return value of [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) on return from the call to [CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation). For the list of these error values, see the table in the Return Values section of
**CertVerifyRevocation**.

### `dwReason`

Specifies the cause of the error. This member is set only if **dwError** is CRYPT_E_REVOKED. It contains a code that indicates why the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) was revoked. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRL_REASON_UNSPECIFIED** | No reason was specified for revocation. |
| **CRL_REASON_KEY_COMPROMISE** | It is known or suspected that the subject's private key or other aspects of the subject validated in the certificate are compromised. |
| **CRL_REASON_CA_COMPROMISE** | It is known or suspected that the CA's private key or other aspects of the CA validated in the certificate are compromised. |
| **CRL_REASON_AFFILIATION_CHANGED** | The subject's name or other information in the certificate has been modified but there is no cause to suspect that the private key has been compromised. |
| **CRL_REASON_SUPERSEDED** | The certificate has been superseded, but there is no cause to suspect that the private key has been compromised. |
| **CRL_REASON_CESSATION_OF_OPERATION** | The certificate is no longer needed for the purpose for which it was issued, but there is no cause to suspect that the private key has been compromised. |
| **CRL_REASON_CERTIFICATE_HOLD** | The certificate has been placed on hold. |

### `fHasFreshnessTime`

Depending on **cbSize**, this structure can contain this member. If this member is **TRUE**, the revocation freshness time returned by **dwFreshnessTime** is valid.

### `dwFreshnessTime`

Depending on **cbSize**, this structure can contain this member. If present, this member gives the time in seconds between the current time and when the CRL was published.

## See also

[CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation)