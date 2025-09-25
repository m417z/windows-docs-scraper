# IIdentityProvider::Delete

## Description

The **Delete** method removes the specified identity from the identity store or the specified properties from the identity.

## Parameters

### `lpszUniqueID` [in]

The unique name associated with the identity.

### `pKeywordsToDelete` [in, optional]

The names of properties to delete. If the value of this parameter is **NULL**, the identity is deleted.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider)