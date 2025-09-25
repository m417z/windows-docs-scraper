# IIdentityStore::GetAt

## Description

The **GetAt** method retrieves an [IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider) interface pointer for the specified identity provider.

## Parameters

### `dwProvider` [in]

The index of the identity provider to retrieve.

### `pProvGuid` [in, out]

On output, this parameter receives a pointer to the GUID of the identity provider that this function retrieves.

### `ppIdentityProvider` [out]

A pointer to the [IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider) interface pointer that this method retrieves.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityStore](https://learn.microsoft.com/windows/desktop/api/identitystore/nn-identitystore-iidentitystore)