# IIdentityProvider::Import

## Description

The **Import** method imports an identity to the system.

## Parameters

### `pPropertyStore` [in]

A pointer to the **IPropertyStore** interface that specifies all information required to create the new identity on the system.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider)