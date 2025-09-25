# CertGetIssuerCertificateFromStore function

## Description

The **CertGetIssuerCertificateFromStore** function retrieves the certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for the first or next issuer of the specified subject certificate. The new
[Certificate Chain Verification Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) are recommended instead of the use of this function.

## Parameters

### `hCertStore` [in]

Handle of a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `pSubjectContext` [in]

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the subject information. This parameter can be obtained from any certificate store or can be created by the calling application using the
[CertCreateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatecontext) function.

### `pPrevIssuerContext` [in, optional]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the issuer information. An issuer can have multiple certificates, especially when a validity period is about to change. This parameter must be **NULL** on the call to get the first issuer certificate. To get the next certificate for the issuer, set *pPrevIssuerContext* to the **CERT_CONTEXT** structure returned by the previous call.

This function frees the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) referenced by non-**NULL** values of this parameter.

### `pdwFlags` [in, out]

The following flags enable verification checks on the returned certificate. They can be combined using a bitwise-**OR** operation to enable multiple verifications.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_NO_CRL_FLAG** | Indicates no matching CRL was found. |
| **CERT_STORE_NO_ISSUER_FLAG** | Indicates no issuer certificate was found. |
| **CERT_STORE_REVOCATION_FLAG** | Checks whether the subject certificate is on the issuer's revocation list. |
| **CERT_STORE_SIGNATURE_FLAG** | Uses the public key in the issuer's certificate to verify the signature on the subject certificate. |
| **CERT_STORE_TIME_VALIDITY_FLAG** | Gets the current time and verifies that it is within the subject certificate's validity period. |

If a verification check of an enabled type succeeds, its flag is set to zero. If it fails, its flag remains set upon return. For CERT_STORE_REVOCATION_FLAG, the verification succeeds if the function does not find a CRL related to the subject certificate.

If CERT_STORE_REVOCATION_FLAG is set and the issuer does not have a CRL in the store, CERT_STORE_NO_CRL_FLAG is set and CERT_STORE_REVOCATION_FLAG remains set.

If CERT_STORE_SIGNATURE_FLAG or CERT_STORE_REVOCATION_FLAG is set, CERT_STORE_NO_ISSUER_FLAG is set if the function does not find an issuer certificate in the store. For more details, see Remarks.

In the case of a verification check failure, a pointer to the issuer's
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) is still returned and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is not updated.

## Return value

If the function succeeds, the return value is a pointer to a read-only issuer [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context).

If the function fails and the first or next issuer certificate is not found, the return value is **NULL**.

Only the last returned [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure must be freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext). When the returned **CERT_CONTEXT** from one call to the function is supplied as the *pPrevIssuerContext* parameter on a subsequent call, the context is freed as part of the action of the function.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NOT_FOUND** | No issuer was found for the subject certificate. |
| **CRYPT_E_SELF_SIGNED** | The issuer certificate is the same as the subject certificate. It is a self-signed [root certificate](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). |
| **E_INVALIDARG** | The handle in the *hCertStore* parameter is not the same as that of the certificate context pointed to by the *pPrevIssuerContext* parameter, or an unsupported flag was set in *pdwFlags*. |

## Remarks

The returned pointer is freed when passed as the *pPrevIssuerContext* parameter on a subsequent call to the function. Otherwise, the pointer must be explicitly freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext). A *pPrevIssuerContext* that is not **NULL** is always freed by **CertGetIssuerCertificateFromStore** using a call to **CertFreeCertificateContext**, even if there is an error in the function.

[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext) can be called to make a duplicate of the issuer certificate.

The hexadecimal values for *dwFlags* can be combined using a bitwise-**OR** operation to enable multiple verifications. For example, to enable both signature and time validity, the value 0x00000003 is passed in *dwFlags* on input. In this case, if CERT_STORE_SIGNATURE_FLAG verification succeeds but CERT_STORE_TIME_VALIDITY_FLAG verification fails, *dwFlags* returns as 0x00000002 on output.

## See also

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)