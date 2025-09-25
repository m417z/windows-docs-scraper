# CRYPT_IMAGE_REG structure

## Description

The **CRYPT_IMAGE_REG** structure contains image registration information about a CNG provider.

## Members

### `pszImage`

A pointer to a null-terminated Unicode string that contains only the file name of the provider module.

### `cInterfaces`

Contains the number of elements in the **rgpInterfaces** array.

### `rgpInterfaces`

A pointer to an array of [CRYPT_INTERFACE_REG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_interface_reg) structure pointers that specify the types of cryptographic interfaces that are supported by the provider. For example, if the provider supports both a cipher interface (**BCRYPT_CIPHER_INTERFACE**) and a hash interface (**BCRYPT_HASH_INTERFACE**), this array would contain two **CRYPT_INTERFACE_REG** structure pointers, one for the cipher interface and one for the hash interface.

## See also

[CRYPT_PROVIDER_REG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_provider_reg)