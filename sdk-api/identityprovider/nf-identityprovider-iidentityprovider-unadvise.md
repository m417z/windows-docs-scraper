# IIdentityProvider::UnAdvise

## Description

The **UnAdvise** method deletes a connection created by calling the [Advise](https://learn.microsoft.com/windows/desktop/api/identityprovider/nf-identityprovider-iidentityprovider-advise) method.

## Parameters

### `dwCookie` [in]

A value that identifies the connection to delete.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[Advise](https://learn.microsoft.com/windows/desktop/api/identityprovider/nf-identityprovider-iidentityprovider-advise)

[IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider)