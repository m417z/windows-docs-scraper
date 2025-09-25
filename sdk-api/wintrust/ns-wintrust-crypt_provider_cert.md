# CRYPT_PROVIDER_CERT structure

## Description

[The **CRYPT_PROVIDER_CERT** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_PROVIDER_CERT** structure provides information about a provider certificate.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `pCert`

A pointer to the certificate context.

### `fCommercial`

Boolean value that indicates whether the certificate is a commercial certificate.

### `fTrustedRoot`

Boolean value that indicates whether the certificate is a trusted root certificate.

### `fSelfSigned`

Boolean value that indicates whether the certificate is self-signed.

### `fTestCert`

Boolean value that indicates whether the certificate is a test certificate.

### `dwRevokedReason`

Value that specifies the revocation reason, if applicable.

### `dwConfidence`

Bitwise combination of zero or more of the following confidence values.

| Value | Meaning |
| --- | --- |
| **CERT_CONFIDENCE_SIG**<br><br>0x10000000 | The signature of the certificate is valid. |
| **CERT_CONFIDENCE_TIME**<br><br>0x01000000 | The time of the certificate issuer is valid. |
| **CERT_CONFIDENCE_TIMENEST**<br><br>0x00100000 | The time of the certificate is valid. |
| **CERT_CONFIDENCE_AUTHIDEXT**<br><br>0x00010000 | The authority ID extension is valid. |
| **CERT_CONFIDENCE_HYGIENE**<br><br>0x00001000 | At a minimum, the signature of the certificate and authority ID extension are valid. |
| **CERT_CONFIDENCE_HIGHEST**<br><br>0x11111000 | Combination of all of the other confidence values. |

### `dwError`

A pointer to a **DWORD** variable that contains the error value for this certificate, if applicable.

### `pTrustListContext`

A pointer to the [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) that represents the certificate trust list (CTL).

### `fTrustListSignerCert`

Boolean value that specifies whether the certificate is a trust list signer certificate.

### `pCtlContext`

A pointer to the [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) that represents a CTL that contains a self-signed certificate, if applicable.

### `dwCtlError`

A pointer to a **DWORD** variable that contains the error value for a CTL that contains a self-signed certificate, if applicable.

### `fIsCyclic`

Boolean value that indicates whether the certificate trust is cyclical.

### `pChainElement`

A pointer to the [CERT_CHAIN_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_element) that represents the status of the certificate within a chain.