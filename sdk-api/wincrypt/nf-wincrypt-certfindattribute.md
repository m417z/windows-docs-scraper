# CertFindAttribute function

## Description

The **CertFindAttribute** function finds the first attribute in the
[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) array, as identified by its [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). This function can be used in the processing of a decoded [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). A
[CERT_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_request_info) structure is derived from a decoded certificate request. The **rgAttribute** array is retrieved from that structure and passed to this function in the *rgAttr* parameter. This function determines whether a particular attribute is in the array, and if so, returns a pointer to it.

## Parameters

### `pszObjId` [in]

A pointer to the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) to use in the search.

### `cAttr` [in]

Number of attributes in the *rgAttr* array.

### `rgAttr` [in]

Array of
[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures.

## Return value

Returns a pointer to the attribute, if one is found. Otherwise, **NULL** is returned.

## See also

[CertFindExtension](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindextension)

[CertFindRDNAttr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindrdnattr)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)