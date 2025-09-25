# CERT_KEY_CONTEXT structure

## Description

The **CERT_KEY_CONTEXT** structure contains data associated with a CERT_KEY_CONTEXT_PROP_ID property.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hCryptProv`

A [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) handle. This member is used when the **dwKeySpec** member contains **AT_KEYEXCHANGE** or **AT_SIGNATURE**.

### `DUMMYUNIONNAME.hNCryptKey`

A CNG CSP handle. This member is used when the **dwKeySpec** member contains **CERT_NCRYPT_KEY_SPEC**.

**Windows Server 2003 and Windows XP:** This member is not available.

### `dwKeySpec`

The specification of the private key to retrieve.

The following **dwKeySpec** values are defined for the default provider.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | Keys used to encrypt/decrypt session keys. The handle to the CSP is contained in the **hCryptProv** member. |
| **AT_SIGNATURE** | Keys used to create and verify digital signatures. The handle to the CSP is contained in the **hCryptProv** member. |
| **CERT_NCRYPT_KEY_SPEC** | Keys associated with a CNG CSP. The handle to the CNG CSP is set in the **hNCryptProv** member.<br><br>**Windows Server 2003 and Windows XP:** This value is not used. |

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty)

[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty)