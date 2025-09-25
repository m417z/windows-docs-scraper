# ICredentialProviderCredentialEvents2::BeginFieldUpdates

## Description

Starts a batch update to fields in the logon or credential UI.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A call to this method must be made at the beginning of the code that updates the credential's UI fields.

## See also

[ICredentialProviderCredential2](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential2)

[ICredentialProviderCredential2::EndFieldUpdates](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-endfieldupdates)

[ICredentialProviderCredential2::SetFieldOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-setfieldoptions)

[ICredentialProviderCredentialEvents2](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents2)