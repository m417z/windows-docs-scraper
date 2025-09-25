# CERT_REVOCATION_INFO structure

## Description

The **CERT_REVOCATION_INFO** structure indicates the revocation status of a certificate in a CERT_CHAIN_ELEMENT.

## Members

### `cbSize`

Size of this structure in bytes.

### `dwRevocationResult`

Currently defined values are:

* CERT_TRUST_IS_REVOKED
* CERT_TRUST_REVOCATION_STATUS_IS_UNKNOWN

### `pszRevocationOid`

Not currently used and is set to **NULL**.

### `pvOidSpecificInfo`

Not currently used and is set to **NULL**.

### `fHasFreshnessTime`

BOOL set to **TRUE** if dwFreshnessTime has been updated.

### `dwFreshnessTime`

If **fHasFreshnessTime** is **TRUE**, holds the CurrentTime minus the [certificate revocation list's](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL's). This time is in seconds.

### `pCrlInfo`

For CRL base revocation checking, a non-**NULL** pointer to a CERT_REVOCATION_CRL_INFO structure.

## See also

[CERT_CHAIN_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_element)