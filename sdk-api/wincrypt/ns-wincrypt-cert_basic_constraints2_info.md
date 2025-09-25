# CERT_BASIC_CONSTRAINTS2_INFO structure

## Description

The **CERT_BASIC_CONSTRAINTS2_INFO** structure contains information indicating whether the certified subject can act as a CA or an end entity. If the subject can act as a CA, a certification path length constraint can also be specified.

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) creates an instance of this structure when performed on a
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure's **Value** member with the structure's **pszObjId** member set to szOID_BASIC_CONSTRAINTS2.

An instance of this structure can be used as input to [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) to create an appropriate [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension).

## Members

### `fCA`

Boolean indicating whether the certificate subject can act as a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) or not.

### `fPathLenConstraint`

Boolean indicating whether the **dwPathLenConstraint** field limits the maximum length of the certification path. Used only if **fCA** is **TRUE**.

### `dwPathLenConstraint`

Maximum number of CA certificates that can follow this certificate in a certification path. A value of zero indicates that the subject of this certificate can issue certificates only to end entities and not to other CAs. Used only if both **fCA** and **fPathLenConstraint** are **TRUE**.