# ICredentialProviderCredential2::GetUserSid

## Description

Retrieves the security identifier (SID) of the user that is associated with this credential.

## Parameters

### `sid` [out]

The address of a pointer to a buffer that, when this method returns successfully, receives the user's SID.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Logon UI will use the returned SID from this method to associate the credential tile with a user tile. To associate the credential with the "Other user" user tile in the Logon UI, this method should return **S_FALSE** and a null SID. The "Other user" tile is normally only valid when the PC is joined to a domain.

#### Examples

The following example shows a sample implementation of this method. It retrieves the user's SID that corresponds to the credential.

The *_pszUserSid* variable used here is assumed to be a private member of the class, defined outside of this method and set to the user's SID.

The resource pointed to by *ppszSid* will be freed by the logon UI, so it does not need to be freed here.

If the user's SID is not available, the method returns **S_FALSE** with a null SID, which associates the credential with an anonymous user tile. This will cause the tile to appear when the "Other user" tile is selected on a domain-joined PC.

```cpp

// Gets the SID of the user corresponding to the credential.
HRESULT CSampleCredential::GetUserSid(__deref_out PWSTR *ppszSid)
{
    *ppszSid = nullptr;
    HRESULT hr = E_UNEXPECTED;

    // _pszUserSid is a private member of CSampleCredential
    if (_pszUserSid != nullptr)
    {
        // ppszSid will be freed by Logon UI
        hr = SHStrDupW(_pszUserSid, ppszSid);
    }
    // Return S_FALSE with a null SID in ppszSid for the
    // credential to be associated with an anonymous user tile.
    else if (_fIsOtherUserTile)
    {
        hr = S_FALSE;
    }

    return hr;
}

```

## See also

[ICredentialProviderCredential2](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential2)

[ICredentialProviderUser::GetSid](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getsid)