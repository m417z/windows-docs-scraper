# CRYPT_INTERFACE_REG structure

## Description

The **CRYPT_INTERFACE_REG** structure is used to contain information about the type of interface supported by a CNG provider.

## Members

### `dwInterface`

Contains the identifier of the interface type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE** | The provider supports the asymmetric encryption interface. |
| **BCRYPT_CIPHER_INTERFACE** | The provider supports the cipher interface. |
| **BCRYPT_HASH_INTERFACE** | The provider supports the hash interface. |
| **NCRYPT_KEY_STORAGE_INTERFACE** | The provider supports the key storage interface. |
| **BCRYPT_RNG_INTERFACE** | The provider supports the random number generator interface. |
| **NCRYPT_SCHANNEL_INTERFACE** | The provider supports the Schannel interface. |
| **BCRYPT_SECRET_AGREEMENT_INTERFACE** | The provider supports the secret agreement interface. |
| **BCRYPT_SIGNATURE_INTERFACE** | The provider supports the signature interface. |

### `dwFlags`

Contains flags that modify the behavior of the interface. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_DOMAIN** | This value is not available for use. |
| **CRYPT_LOCAL** | The interface is registered in the local configuration table. |

### `cFunctions`

Contains the number of elements in the **rgpszFunctions** array.

### `rgpszFunctions`

An array of null-terminated Unicode strings that contains the identifiers of the algorithms that are supported by this interface. These identifiers can be the standard [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) or the identifiers for other registered algorithms.

## See also

[CRYPT_IMAGE_REG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_image_reg)