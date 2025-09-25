# IIdentityProvider::Create

## Description

The **Create** method creates a new identity associated with the specified user name.

## Parameters

### `lpszUserName` [in]

The user name with which to associate the new identity.

### `ppPropertyStore` [out]

A pointer to the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface that represents the property store associated with the new identity.

### `pKeywordsToAdd` [in, optional]

The properties to associate with the new identity.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider)