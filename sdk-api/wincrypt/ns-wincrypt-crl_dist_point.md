# CRL_DIST_POINT structure

## Description

The **CRL_DIST_POINT** structure identifies a single [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) distribution point that a certificate user can reference to determine whether certificates have been revoked. A certificate user can obtain a CRL from an applicable distribution point or can obtain a current complete CRL from the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) directory entry.

The **CRL_DIST_POINT** structures are the elements in the array member of a
[CRL_DIST_POINTS_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_dist_points_info) structure.

## Members

### `DistPointName`

A
[CRL_DIST_POINT_NAME](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_dist_point_name) structure that identifies the location of a CRL source. If **NULL**, the distribution point name defaults to the **CRLIssuer** name.

### `ReasonFlags`

A [CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob) that contains a byte that indicates the revocation reasons covered by the CRL.

If **NULL**, the indicated CRL distribution point distributes a CRL that will contain an entry for this certificate if this certificate has been revoked, regardless of the revocation reason.

The following are currently defined **ReasonFlags** values. For revocations of several reasons, combine these **ReasonFlags** by using a bitwise-**OR** operation.

* CRL_REASON_UNUSED_FLAG
* CRL_REASON_KEY_COMPROMISE_FLAG
* CRL_REASON_CA_COMPROMISE_FLAG
* CRL_REASON_AFFILIATION_CHANGED_FLAG
* CRL_REASON_SUPERSEDED_FLAG
* CRL_REASON_CESSATION_OF_OPERATION_FLAG
* CRL_REASON_CERTIFICATE_HOLD_FLAG

### `CRLIssuer`

A
[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) that identifies the authority that issued and signed the CRL. If **NULL**, the issuer name defaults to the issuer name of the certificate.

## See also

[CRL_DIST_POINTS_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_dist_points_info)

[CRL_DIST_POINT_NAME](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_dist_point_name)