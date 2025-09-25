# CryptUnregisterOIDInfo function

## Description

The **CryptUnregisterOIDInfo** function removes the registration of a specified
[CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) OID information structure. The structure to be unregistered is identified by the structure's **pszOID** and **dwGroupId** members.

## Parameters

### `pInfo` [in]

Specifies the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) information for which the registration is to be removed. The group that the registration is removed for is specified by the **dwGroupId** member in the *pInfo*.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE).

## See also

[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info)

[CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo)

[CryptRegisterOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisteroidinfo)

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)