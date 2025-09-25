# CertFindExtension function

## Description

The **CertFindExtension** function finds the first extension in the
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) array, as identified by its [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). This function can be used in the processing of a decoded certificate. A
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure is derived from a decoded certificate. The **CERT_INFO** structure's **rgExtension** member is passed to **CertFindExtension** in the *rgExtensions* parameter. This function determines whether a particular extension is in the array, and if so, returns a pointer to it

## Parameters

### `pszObjId` [in]

A pointer to the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) to use in the search.

### `cExtensions` [in]

Number of extensions in the *rgExtensions* array.

### `rgExtensions` [in]

Array of
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures.

## Return value

Returns a pointer to the extension, if one is found. Otherwise, **NULL** is returned.

## See also

[CertFindAttribute](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindattribute)

[CertFindRDNAttr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindrdnattr)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)