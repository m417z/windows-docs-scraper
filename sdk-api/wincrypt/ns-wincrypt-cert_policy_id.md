# CERT_POLICY_ID structure

## Description

The **CERT_POLICY_ID** structure contains a list of certificate policies that the certificate expressly supports, together with optional qualifier information pertaining to these policies.

**CERT_POLICY_ID** is a component of
[CERT_KEY_USAGE_RESTRICTION_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_usage_restriction_info).

## Members

### `cCertPolicyElementId`

Number of elements in the **rgpszCertPolicyElementId** array.

### `rgpszCertPolicyElementId`

Array of pointers to policy element identifier strings.

## See also

[CERT_KEY_USAGE_RESTRICTION_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_usage_restriction_info)