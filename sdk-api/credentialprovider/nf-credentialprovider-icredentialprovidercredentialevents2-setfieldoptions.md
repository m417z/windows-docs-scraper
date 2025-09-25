# ICredentialProviderCredentialEvents2::SetFieldOptions

## Description

Specifies whether a specified field in the logon or credential UI should display a "password reveal" glyph or is expected to receive an e-mail address.

## Parameters

### `credential` [in]

An [ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential) interface pointer to the credential object.

### `fieldID` [in]

The ID of the field in the logon or credential UI for which this option applies.

### `options` [in]

One or more of the [CREDENTIAL_PROVIDER_CREDENTIAL_FIELD_OPTIONS](https://learn.microsoft.com/windows/desktop/api/credentialprovider/ne-credentialprovider-credential_provider_credential_field_options) values, which specify the field options.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICredentialProviderCredential2::BeginFieldUpdates](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-beginfieldupdates)

[ICredentialProviderCredential2::EndFieldUpdates](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-endfieldupdates)

[ICredentialProviderCredentialEvents2](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents2)

[ICredentialProviderCredentialWithFieldOptions::GetFieldOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialwithfieldoptions-getfieldoptions)