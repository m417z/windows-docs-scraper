# IIdentityProvider::FindByUniqueID

## Description

The **FindByUniqueID** method retrieves a pointer to the **IPropertyStore** interface instance associated with the specified identity.

## Parameters

### `lpszUniqueID` [in]

The unique identity to find.

### `ppPropertyStore` [out]

A pointer to the instance of the **IPropertyStore** interface associated with the specified identity.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider)