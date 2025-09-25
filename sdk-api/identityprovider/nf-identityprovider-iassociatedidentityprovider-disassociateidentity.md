# IAssociatedIdentityProvider::DisassociateIdentity

## Description

The **DisassociateIdentity** method disassociates the specified identity from a local user account.

## Parameters

### `hwndParent` [in]

A handle to the parent of the window used to collect account credentials.

### `lpszUniqueID` [in]

The identity to disassociate.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IAssociatedIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iassociatedidentityprovider)