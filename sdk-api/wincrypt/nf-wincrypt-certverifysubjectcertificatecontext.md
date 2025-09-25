# CertVerifySubjectCertificateContext function

## Description

The **CertVerifySubjectCertificateContext** function performs the enabled verification checks on a certificate by checking the validity of the certificate's issuer. The new
[Certificate Chain Verification Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) are recommended instead of this function.

## Parameters

### `pSubject` [in]

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure containing the subject's certificate.

### `pIssuer` [in, optional]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) containing the issuer's certificate. When checking just CERT_STORE_TIME_VALIDITY_FLAG, *pIssuer* can be **NULL**.

### `pdwFlags` [in, out]

A pointer to a **DWORD** value contain verification check flags. The following flags can be set to enable verification checks on the subject certificate. They can be combined using a bitwise-**OR** operation to enable multiple verifications.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_REVOCATION_FLAG** | Checks whether the subject certificate is on the issuer's revocation list. |
| **CERT_STORE_SIGNATURE_FLAG** | Uses the public key in the issuer's certificate to verify the signature on the subject certificate. |
| **CERT_STORE_TIME_VALIDITY_FLAG** | Gets the current time and verifies that it is within the subject certificate's validity period. |

If an enabled verification check succeeds, its flag is set to zero. If it fails, then its flag is set upon return.

If CERT_STORE_REVOCATION_FLAG was enabled and the issuer does not have a CRL in the store, then CERT_STORE_NO_CRL_FLAG is set in addition to CERT_STORE_REVOCATION_FLAG.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

For a verification check failure, **TRUE** is still returned. **FALSE** is returned only when a bad parameter is passed in.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | An unsupported bit was set in *pdwFlags*. Any combination of CERT_STORE_SIGNATURE_FLAG, CERT_STORE_TIME_VALIDITY_FLAG, and CERT_STORE_REVOCATION_FLAG can be set. If *pIssuer* is **NULL**, only CERT_STORE_TIME_VALIDITY_FLAG can be set. |

## Remarks

The hexadecimal value of the flags can be combined using bitwise-**OR** operations to enable multiple verifications. For example, to enable both signature and time validity, the value

``` syntax
CERT_STORE_SIGNATURE_FLAG | CERT_STORE_TIME_VALIDITY_FLAG

```

is placed in the *pdwFlags* **DWORD** value as an input parameter. If CERT_STORE_SIGNATURE_FLAG verification succeeds, but CERT_STORE_TIME_VALIDITY_FLAG verification fails, *pdwFlags* is set to CERT_STORE_TIME_VALIDITY_FLAG when the function returns.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CertGetIssuerCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetissuercertificatefromstore)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)