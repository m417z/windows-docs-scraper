# ICredentialProviderCredentialEvents2::EndFieldUpdates

## Description

Finishes and commits the batch updates started by [BeginFieldUpdates](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-beginfieldupdates).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A call to this method must be made at the end of the code that updates the credential's UI fields.

## See also

[ICredentialProviderCredential2::BeginFieldUpdates](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-beginfieldupdates)

[ICredentialProviderCredential2::SetFieldOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-setfieldoptions)

[ICredentialProviderCredentialEvents2](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents2)