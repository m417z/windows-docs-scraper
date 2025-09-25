# IIdentityProvider::GetProviderPropertyStore

## Description

The **GetProviderPropertyStore** method retrieves a pointer to the **IPropertyStore** interface associated with the identity provider.

## Parameters

### `ppPropertyStore` [out]

A pointer to the global **IPropertyStore** interface associated with this identity provider.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider)