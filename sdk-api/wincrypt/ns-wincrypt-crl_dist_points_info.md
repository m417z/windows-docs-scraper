# CRL_DIST_POINTS_INFO structure

## Description

The **CRL_DIST_POINTS_INFO** structure contains a list of [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) distribution points a certificate user can reference to determine whether the certificate has been revoked.

## Members

### `cDistPoint`

Number of elements in the **rgDistPoint** member array.

### `rgDistPoint`

Array of
[CRL_DIST_POINT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_dist_point) structures.

## See also

[CRL_DIST_POINT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_dist_point)