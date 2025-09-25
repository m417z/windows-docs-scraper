# NCryptKeyName structure

## Description

The **NCryptKeyName** structure is used to contain information about a CNG key.

## Members

### `pszName`

A pointer to a null-terminated Unicode string that contains the name of the key.

### `pszAlgid`

A pointer to a null-terminated Unicode string that contains the identifier of the cryptographic algorithm that the key was created with. This can be one of the standard [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) or the identifier for another registered algorithm.

### `dwLegacyKeySpec`

A legacy identifier that specifies the type of key. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | The key is a key exchange key. |
| **AT_SIGNATURE** | The key is a signature key. |
| 0 | The key is none of the above types. |

### `dwFlags`

A set of flags that provide more information about the key. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **NCRYPT_MACHINE_KEY_FLAG** | The key applies to the local computer. If this flag is not present, the key applies to the current user. |

## See also

[NCryptEnumKeys](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptenumkeys)