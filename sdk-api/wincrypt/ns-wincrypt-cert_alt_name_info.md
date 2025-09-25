# CERT_ALT_NAME_INFO structure

## Description

The **CERT_ALT_NAME_INFO** structure is used in encoding and decoding extensions for subject or issuer [certificates](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [Certificate Revocation Lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs), and [Certificate Trust Lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTLs).

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) creates an instance of this structure when performed on a
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure's **Value** member with its structure's **pszObjId** member set to szOID_SUBJECT_ALT_NAME or szOID_ISSUER_ALT_NAME.

An instance of this structure can be used as input to [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) to create an appropriate [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension).

## Members

### `cAltEntry`

Number of elements in the **rgAltEntry** array.

### `rgAltEntry`

Array of
[CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry) structures.

## See also

[CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry)