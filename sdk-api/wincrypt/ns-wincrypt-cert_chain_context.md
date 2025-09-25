# CERT_CHAIN_CONTEXT structure

## Description

The **CERT_CHAIN_CONTEXT** structure contains an array of simple certificate chains and a trust status structure that indicates summary validity data on all of the connected simple chains.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `TrustStatus`

A structure that indicates the combined trust status of the simple chains array. The structure includes an error status code and an information status code. For information about status code values, see
[CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status).

### `cChain`

The number of simple chains in the array.

### `rgpChain`

An array of pointers to simple chain structures. **rgpChain**[0] is the end certificate simple chain, and **rgpChain**[**cChain**–1] is the final chain. If the end certificate is to be considered valid, the final chain must begin with a certificate contained in the root store or an otherwise trusted, self-signed certificate. If the original chain begins with a trusted certificate, there will be only a single simple chain in the array.

### `cLowerQualityChainContext`

The number of chains in the **rgpLowerQualityChainContext** array.

### `rgpLowerQualityChainContext`

An array of pointers to CERT_CHAIN_CONTEXT structures. Returned when CERT_CHAIN_RETURN_LOWER_QUALITY_CONTEXTS is set in dwFlags.

### `fHasRevocationFreshnessTime`

A Boolean value set to **TRUE** if **dwRevocationFreshnessTime** is available.

### `dwRevocationFreshnessTime`

The largest CurrentTime, in seconds, minus the [certificate revocation list's](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL's) ThisUpdate of all elements checked.

### `dwCreateFlags`

### `ChainId`

## Remarks

When a **CERT_CHAIN_CONTEXT** is built, the first simple chain begins with an end certificate and ends with a self-signed certificate. If that self-signed certificate is not a [root](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) or otherwise trusted certificate, an attempt is made to build a new chain. [CTLs](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) are used to create the new chain beginning with the self-signed certificate from the original chain as the end certificate of the new chain. This process continues building additional simple chains until the first self-signed certificate is a trusted certificate or until an additional simple chain cannot be built.

## See also

[CERT_SIMPLE_CHAIN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_simple_chain)

[CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status)

[CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain)