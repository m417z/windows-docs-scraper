# CERT_CHAIN_ELEMENT structure

## Description

The **CERT_CHAIN_ELEMENT** structure is a single element in a simple certificate chain. Each element has a pointer to a [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), a pointer to a structure that indicates the error status and information status of the certificate, and a pointer to a structure that indicates the revocation status of the certificate.

## Members

### `cbSize`

Size of this structure in bytes.

### `pCertContext`

A pointer to a certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `TrustStatus`

Structure indicating the status of the certificate. The structure includes an error status code and an information status code. For information about status code values, see CERT_TRUST_STATUS.

### `pRevocationInfo`

A pointer to a CERT_REVOCATION_INFO structure with information on the revocation status of the certificate. If revocation checking was not enabled, **pRevocationInfo** is **NULL**.

### `pIssuanceUsage`

A pointer to a CERT_ENHKEY_USAGE structure. If **NULL**, any issuance policy is acceptable.

### `pApplicationUsage`

A pointer to a CERT_ENHKEY_USAGE structure. If **NULL**, any enhanced key usage is acceptable.

### `pwszExtendedErrorInfo`

A pointer to a **null**-terminated wide character string that contains extended error information. If **NULL**, there is no extended error information.

## See also

[CERT_REVOCATION_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_info)

[CERT_SIMPLE_CHAIN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_simple_chain)

[CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status)