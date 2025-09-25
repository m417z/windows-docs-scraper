# OCSP_REQUEST_INFO structure

## Description

The **OCSP_REQUEST_INFO** structure contains information for an [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) request as specified by [RFC 2560](https://www.ietf.org/rfc/rfc2560.txt). The RFC specifies that a single request can contain a sequence of certificates for which statuses are required. The **rgRequestEntry** member of this structure contains an [OCSP_REQUEST_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_entry) structure for each certificate in a sequence.

## Members

### `dwVersion`

A value that indicates the protocol version of the OCSP request.

#### OCSP_REQUEST_V1 (0)

### `pRequestorName`

A pointer to a [CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry) structure that contains the name bound to the certificate [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the requester.

### `cRequestEntry`

The number of elements in the **rgRequestEntry** array.

### `rgRequestEntry`

An array of pointers to [OCSP_REQUEST_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_entry) structures.

### `cExtension`

The number of elements in the **rgExtension** array.

### `rgExtension`

An array of pointers to [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures, each of which contains information about the request.

## See also

[CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry)

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[OCSP_REQUEST_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_entry)

[RFC 2560 Online Certificate Status Protocol](https://www.ietf.org/rfc/rfc2560.txt)