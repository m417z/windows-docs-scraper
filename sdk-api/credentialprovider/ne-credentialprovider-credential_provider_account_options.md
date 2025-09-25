# CREDENTIAL_PROVIDER_ACCOUNT_OPTIONS enumeration

## Description

Indicates the type of credential that a credential provider should return to associate with the "Other user" tile. Used by [ICredentialProviderUserArray_GetAccountOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruserarray-getaccountoptions).

## Constants

### `CPAO_NONE:0`

Default. Do not return a credential to associate with the "Other user" tile.

### `CPAO_EMPTY_LOCAL:0x1`

Return a credential to associate with the "Other user" tile. This credential can only be used for a local account.

### `CPAO_EMPTY_CONNECTED:0x2`

Return a credential to associate with the "Other user" tile. This credential can only be used for a Microsoft account.

## See also

[ICredentialProviderUserArray_GetAccountOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruserarray-getaccountoptions)