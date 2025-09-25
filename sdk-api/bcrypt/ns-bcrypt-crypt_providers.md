# CRYPT_PROVIDERS structure

## Description

The **CRYPT_PROVIDERS** structure contains information about the registered CNG providers.

## Members

### `cProviders`

Contains the number of elements in the **rgpszProviders** array.

### `rgpszProviders`

An array of null-terminated Unicode strings that contains the names of the registered providers.

## See also

[BCryptEnumRegisteredProviders](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptenumregisteredproviders)