# OCSP_REQUEST_ENTRY structure

## Description

The **OCSP_REQUEST_ENTRY** structure contains information about a single certificate in an [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) request. This structure populates the [OCSP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_info) **rgRequestEntry** member.

## Members

### `CertId`

An [OCSP_CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_cert_id) structure that specifies the target certificate.

### `cExtension`

The number of elements in the **rgExtension** array.

### `rgExtension`

An array of pointers to [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures, each of which contains information about the **CertId** certificate.

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[OCSP_CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_cert_id)

[OCSP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_info)

[RFC 2560 Online Certificate Status Protocol](https://www.ietf.org/rfc/rfc2560.txt)