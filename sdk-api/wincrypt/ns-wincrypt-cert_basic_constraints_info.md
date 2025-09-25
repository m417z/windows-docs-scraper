# CERT_BASIC_CONSTRAINTS_INFO structure

## Description

The **CERT_BASIC_CONSTRAINTS_INFO** structure contains information that indicates whether the certified subject can act as a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA), an end entity, or both. If the subject can act as a CA, a certification path-length constraint can also be specified, as can a set of subtrees that must contain all subject names of subsequent certificates in a certification chain. This extension is used in validating certificates used to sign other certificates.

The [CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) function creates an instance of this structure when performed on a
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure's **Value** member with its structure's **pszObjId** member set to szOID_BASIC_CONSTRAINTS.

## Members

### `SubjectType`

A
[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob) value can contain one of the following:

* A CERT_CA_SUBJECT_FLAG that, when set, indicates that the certificate's subject can act as a CA.
* A CERT_END_ENTITY_SUBJECT_FLAG that, when set, indicates that the certificate's subject can act as an end entity.
* Both of the above, combined using a bitwise-**OR** operation.

### `fPathLenConstraint`

A Boolean value that indicates whether the **dwPathLenConstraint** field sets the maximum length of the certification path.

### `dwPathLenConstraint`

The maximum number of CA certificates that can follow this certificate in a certification validation path. A value of zero indicates that the subject of this certificate can issue certificates only to end entities and not to CAs.

### `cSubtreesConstraint`

The number of elements in the **rgSubtreesConstraint** array.

### `rgSubtreesConstraint`

An array of
[CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structures that establish subtree constraints.

## See also

[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))