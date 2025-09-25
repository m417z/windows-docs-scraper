# CERT_SIMPLE_CHAIN structure

## Description

The **CERT_SIMPLE_CHAIN** structure contains an array of chain elements and a summary trust status for the chain that the array represents.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `TrustStatus`

A structure that indicates the trust status of the whole chain. The structure includes an error status code and an information status code. For information about status code values, see [CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status).

### `cElement`

The number of [CERT_CHAIN_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_element) structures in the array.

### `rgpElement`

An array of pointers to [CERT_CHAIN_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_element) structures. **rgpElement**[0] is the end certificate chain element. **rgpElement**[**cElement**–1] is the self-signed "root" certificate element.

### `pTrustListInfo`

A pointer to a [CERT_TRUST_LIST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_list_info) structure that contains a pointer to a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) connecting this chain to a next certificate chain. If the current chain is the final chain, **pTrustListInfo** is **NULL**.

### `fHasRevocationFreshnessTime`

BOOL. If **TRUE**, **dwRevocationFreshnessTime** has been calculated.

### `dwRevocationFreshnessTime`

The age of a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)
(CRL) in seconds, calculated as the CurrentTime minus the CRL's ThisUpdate time. This values is the largest time across all elements checked.

## See also

[CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context)

[CERT_CHAIN_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_element)

[CERT_TRUST_LIST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_list_info)

[CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status)