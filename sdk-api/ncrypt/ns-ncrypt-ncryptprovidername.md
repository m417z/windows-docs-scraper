# NCryptProviderName structure

## Description

The **NCryptProviderName** structure is used to contain the name of a CNG key storage provider. This structure is used with the [NCryptEnumStorageProviders](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptenumstorageproviders) function to return the names of the registered CNG key storage providers.

## Members

### `pszName`

A pointer to a null-terminated Unicode string that contains the name of the provider.

### `pszComment`

A pointer to a null-terminated Unicode string that contains optional text for the provider.

## See also

[NCryptEnumStorageProviders](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptenumstorageproviders)