# CERT_OR_CRL_BLOB structure

## Description

The **CERT_OR_CRL_BLOB** structure encapsulates certificates for use with Internet Key Exchange messages.

## Members

### `dwChoice`

A **DWORD** value that specifies the content type of the buffer pointed to by the **pbEncoded** member.

| Value | Meaning |
| --- | --- |
| **CERT_BUNDLE_CERTIFICATE**<br><br>0 | The **pbEncoded** member points to an encoded certificate. |
| **CERT_BUNDLE_CRL**<br><br>1 | The **pbEncoded** member points to a certificate list. |

### `cbEncoded`

The size, in bytes, of the buffer pointed to by the **pbEncoded** member.

### `pbEncoded`

A pointer to a buffer that contains a certificate or a [CERT_OR_CRL_BUNDLE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_or_crl_bundle) structure that contains an array of certificates as specified by the **dwChoice** member.