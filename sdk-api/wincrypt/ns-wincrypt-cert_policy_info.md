# CERT_POLICY_INFO structure

## Description

The **CERT_POLICY_INFO** structure contains an object identifier (OID) specifying a policy and an optional array of policy qualifiers.

The **CERT_POLICY_INFO** structure is a component of
[CERT_POLICIES_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policies_info).

## Members

### `pszPolicyIdentifier`

Object identifier (OID) string specifying the policy.

### `cPolicyQualifier`

Number of elements in the **rgPolicyQualifier** array.

### `rgPolicyQualifier`

Array of
[CERT_POLICY_QUALIFIER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policy_qualifier_info) structures.

## See also

[CERT_POLICIES_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policies_info)

[CERT_POLICY_QUALIFIER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policy_qualifier_info)