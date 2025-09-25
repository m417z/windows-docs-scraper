# IAssociatedIdentityProvider::ChangeCredential

## Description

The **ChangeCredential** method changes the credentials associated with the specified identity.

## Parameters

### `hwndParent` [in]

A handle to the parent of the window used to collect account credentials.

### `lpszUniqueID` [in]

The identity for which to change the credentials.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method should call [CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) to collect account credentials.

## See also

[IAssociatedIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iassociatedidentityprovider)