# CryptRegisterOIDInfo function

## Description

The **CryptRegisterOIDInfo** function registers the OID information specified in the
[CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) structure, persisting it to the registry.

Crypt32.dll contains predefined information for the commonly known OIDs. This function allows applications to augment the predefined OID information. During
**CryptRegisterOIDInfo**'s first call, the registered OID information is installed.

When expanding the tables using **CryptRegisterOIDInfo**, the new entries can be placed either before or after predefined entries, controlled by *dwFlags*. The placement of registered OID information affects the result of [CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo) because the tables are searched in order. First registered entries placed before the predefined entries are checked, then the predefined entries are checked, and finally, registered entries placed after the predefined entries are checked. The first match found is returned. A newly registered entry placed before the predefined entries can override one of the predefined entries.

## Parameters

### `pInfo` [in]

A pointer to a
[CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) structure with the OID information to register. Specify the group that the OID information is to be registered for by setting the **dwGroupId** member of the structure.

**Note**

When registering OID information for [Suite B](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) algorithms implemented with [Cryptography API: Next Generation](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) (CNG), you must set the **Algid** member of the [CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) structure to **CALG_OID_INFO_CNG_ONLY** (0xFFFFFFFF).

### `dwFlags` [in]

By default, the registered OID information is installed after Crypt32.dll's OID entries. If CRYPT_INSTALL_OID_INFO_BEFORE_FLAG is set, new OID information is install before Crypt32.dll's entries.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE).

## Remarks

When you have finished using the OID information, unregister it by calling the [CryptUnregisterOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptunregisteroidinfo) function.

## See also

[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info)

[CryptEnumOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumoidinfo)

[CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo)

[CryptUnregisterOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptunregisteroidinfo)

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)