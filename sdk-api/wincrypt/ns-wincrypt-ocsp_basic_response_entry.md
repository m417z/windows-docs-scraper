# OCSP_BASIC_RESPONSE_ENTRY structure

## Description

The **OCSP_BASIC_RESPONSE_ENTRY** structure contains the current certificate status for a single certificate. This structure populates the [OCSP_BASIC_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_info) **rgResponseEntry** member.

## Members

### `CertId`

An [OCSP_CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_cert_id) structure that specifies the target certificate of the [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) response.

### `dwCertStatus`

A value that indicates the target certificate revocation status.

[RFC 2560](https://www.ietf.org/rfc/rfc2560.txt) defines the following possible values for certificate status.

| Value | Meaning |
| --- | --- |
| **OCSP_BASIC_GOOD_CERT_STATUS**<br><br>0 | The certificate is not revoked. |
| **OCSP_BASIC_REVOKED_CERT_STATUS**<br><br>1 | The certificate is revoked either permanently or temporarily. |
| **OCSP_BASIC_UNKNOWN_CERT_STATUS**<br><br>2 | The responder has no information for the target certificate. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.pRevokedInfo`

A pointer to an [OCSP_BASIC_REVOKED_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_revoked_info) structure that specifies the reason the target certificate was revoked.

### `ThisUpdate`

The date and time at which the response indicated by *dwCertStatus* is known to be correct.

### `NextUpdate`

The date and time on or before which newer information will be available for the certificate status. A value of zero indicates that the certificate status never expires.

### `cExtension`

The number of elements in the **rgExtension** array.

### `rgExtension`

An array of pointers to [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures, each of which contains additional information about the response.

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[OCSP_BASIC_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_info)

[OCSP_BASIC_REVOKED_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_revoked_info)

[OCSP_CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_cert_id)

[RFC 2560 Online Certificate Status Protocol](https://www.ietf.org/rfc/rfc2560.txt)