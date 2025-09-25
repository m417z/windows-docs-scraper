# CryptFindOIDInfo function

## Description

The **CryptFindOIDInfo** function retrieves the first predefined or registered
[CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) structure that matches a specified key type and key. The search can be limited to [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) within a specified OID group.

Use
[CryptEnumOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumoidinfo) to list all or selected subsets of [CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) structures. New **CRYPT_OID_INFO** structures can be registered by using
[CryptRegisterOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisteroidinfo). User-registered OIDs can be removed from the list of registered OIDs by using
[CryptUnregisterOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptunregisteroidinfo).

New OIDs can be placed in the list of registered OIDs either before or after the predefined entries. Because **CryptFindOIDInfo** returns the first key on the list that matches the search criteria, a newly registered OID placed before a predefined OID entry with the same key overrides a predefined entry.

## Parameters

### `dwKeyType` [in]

Specifies the key type to use when finding OID information.

This parameter can be one of the following key types.

#### CRYPT_OID_INFO_OID_KEY

*pvKey* is the address of a null-terminated ANSI string that contains the OID string to find.

#### CRYPT_OID_INFO_NAME_KEY

*pvKey* is the address of a null-terminated Unicode string that contains the name to find.

#### CRYPT_OID_INFO_ALGID_KEY

*pvKey* is the address of an
[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) variable. The following **ALG_ID**s are supported:

Hash Algorithms:

Symmetric Encryption Algorithms:

Public Key Algorithms:

Algorithms that are not listed are supported by using [Cryptography API: Next Generation](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) (CNG) only; instead, use **CRYPT_OID_INFO_CNG_ALGID_KEY**.

#### CRYPT_OID_INFO_SIGN_KEY

*pvKey* is the address of an array of two [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)s where the first element contains the hash algorithm identifier and the second element contains the public key algorithm identifier.

The following **ALG_ID** combinations are supported.

| Signature algorithm identifier | Hash algorithm identifier |
| --- | --- |
| CALG_RSA_SIGN | CALG_SHA1<br><br>CALG_MD5<br><br>CALG_MD4<br><br>CALG_MD2 |
| CALG_DSS_SIGN | CALG_SHA1 |
| CALG_NO_SIGN | CALG_SHA1<br><br>CALG_NO_SIGN |

Algorithms that are not listed are supported through CNG only; instead, use **CRYPT_OID_INFO_CNG_SIGN_KEY**.

#### CRYPT_OID_INFO_CNG_ALGID_KEY

*pvKey* is the address of a null-terminated Unicode string that contains the CNG algorithm identifier to find. This can be one of the predefined [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) or another registered algorithm identifier.

**Windows Server 2003 R2
Windows Server 2003
:** This key type is not supported.

#### CRYPT_OID_INFO_CNG_SIGN_KEY

*pvKey* is the address of an array of two null-terminated Unicode string pointers where the first string contains the hash CNG algorithm identifier and the second string contains the public key CNG algorithm identifier. These can be from the predefined [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) or another registered algorithm identifier.

**Windows Server 2003 R2
Windows Server 2003
:** This key type is not supported.

Optionally, the following key types can be specified in the *dwKeyType* parameter by using the logical **OR** operator (|).

| Value | Meaning |
| --- | --- |
| **CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG** | Skips public keys in the CRYPT_PUBKEY_ALG_OID_GROUP_ID group that are explicitly flagged with the CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG flag. |
| **CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG** | Skips public keys in the CRYPT_PUBKEY_ALG_OID_GROUP_ID group that are explicitly flagged with the CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG flag. |

### `pvKey` [in]

The address of a buffer that contains additional search information. This parameter depends on the value of the *dwKeyType* parameter. For more information, see the table under *dwKeyType*.

### `dwGroupId` [in]

The group identifier to use when finding OID information. Setting this parameter to zero searches all groups according to the *dwKeyType* parameter. Otherwise, only the indicated *dwGroupId* is searched.

For information about code that lists the OID information by group identifier, see
[CryptEnumOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumoidinfo).

Optionally, the following flag can be specified in the *dwGroupId* parameter by using the logical **OR** operator (|).

| Value | Meaning |
| --- | --- |
| **CRYPT_OID_DISABLE_SEARCH_DS_FLAG** | Disables searching the directory server. |

The bit length shifted left 16 bits can be specified in the *dwGroupId* parameter by using the logical **OR** operator (|). For more information, see Remarks.

## Return value

Returns a pointer to a constant structure of type [CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info). The returned pointer must not be freed. When the specified key and group is not found, **NULL** is returned.

## Remarks

The **CryptFindOIDInfo** function performs a lookup in the active directory to retrieve the friendly names of OIDs under the following conditions:

* The key type in the *dwKeyType* parameter is set to **CRYPT_OID_INFO_OID_KEY** or **CRYPT_OID_INFO_NAME_KEY**.
* No group identifier is specified in the *dwGroupId* parameter or the GroupID refers to EKU OIDs, policy OIDs or template OIDs.

Network retrieval of the friendly name can be suppressed by calling the function with the **CRYPT_OID_DISABLE_SEARCH_DS_FLAG** flag.

The bit length shifted left 16 bits can be specified in the *dwGroupId* parameter by using the logical **OR** operator (|). This is only applicable to the **CRYPT_ENCRYPT_ALG_OID_GROUP_ID** group entries that have a bit length specified in the **ExtraInfo** member of the [CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) structure. Currently, only the AES encryption algorithms have this. The constant **CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT** can be used for doing the shift. For example, to find the OID information for **BCRYPT_AES_ALGORITHM** with bit length equal to 192, call **CryptFindOIDInfo** as follows.

```cpp

DWORD dwBitLen = 192;

PCCRYPT_OID_INFO pOIDInfo = CryptFindOIDInfo(
     CRYPT_OID_INFO_CNG_ALGID_KEY,
     (void *) BCRYPT_AES_ALGORITHM,
     CRYPT_ENCRYPT_ALG_OID_GROUP_ID |
         (dwBitLen << CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT)
     );

```

## See also

[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info)

[CryptRegisterOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisteroidinfo)

[CryptUnregisterOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptunregisteroidinfo)

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)