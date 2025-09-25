# CertFindRDNAttr function

## Description

The **CertFindRDNAttr** function finds the first [RDN](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) attribute identified by its [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) in a list of the *Relative Distinguished Names* (RDN).

## Parameters

### `pszObjId` [in]

A pointer to the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) to use In the search.

### `pName` [in]

A pointer to a
[CERT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_name_info) structure containing the list of the [Relative Distinguished Names](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) to be searched.

## Return value

Returns a pointer to the attribute, if one is found. Otherwise, **NULL** is returned.

## See also

[CertFindAttribute](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindattribute)

[CertFindExtension](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindextension)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)