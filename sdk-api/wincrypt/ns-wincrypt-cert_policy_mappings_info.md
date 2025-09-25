# CERT_POLICY_MAPPINGS_INFO structure

## Description

The **CERT_POLICY_MAPPINGS_INFO** structure provides mapping between the policy OIDs of two domains.

## Members

### `cPolicyMapping`

Count of the number of elements in the **rgPolicyMapping** array.

### `rgPolicyMapping`

Array of
[CERT_POLICY_MAPPING](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policy_mapping) structures. Each element of this array provides pair of OIDs mapping the identifies of one domain to identifiers in the other domain.