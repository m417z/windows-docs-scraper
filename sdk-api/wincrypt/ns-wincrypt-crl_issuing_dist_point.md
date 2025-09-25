# CRL_ISSUING_DIST_POINT structure

## Description

The **CRL_ISSUING_DIST_POINT** structure contains information about the kinds of certificates listed in a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL).

## Members

### `DistPointName`

Optional
[CRL_DIST_POINT_NAME](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_dist_point_name) member.

### `fOnlyContainsUserCerts`

**BOOL** flag. **TRUE** if only user certificates are contained in the CRL.

### `fOnlyContainsCACerts`

**BOOL** flag. **TRUE** if only CA certificates are contained in the CRL.

### `OnlySomeReasonFlags`

Optional
[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob) with bits indicating some reasons for certificate revocation.

### `fIndirectCRL`

**BOOL** flag. **TRUE** if this is an indirect CRL.