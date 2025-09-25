# CERT_POLICY_QUALIFIER_INFO structure

## Description

The **CERT_POLICY_QUALIFIER_INFO** structure contains an object identifier (OID) specifying the qualifier and qualifier-specific supplemental information.

The **CERT_POLICY_QUALIFIER_INFO** structure is a component of
[CERT_POLICY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policy_info).

## Members

### `pszPolicyQualifierId`

OID specifying the qualifier.

### `Qualifier`

A [CRYPT_OBJID_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains qualifier specific supplemental information.

## See also

[CERT_POLICY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policy_info)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))