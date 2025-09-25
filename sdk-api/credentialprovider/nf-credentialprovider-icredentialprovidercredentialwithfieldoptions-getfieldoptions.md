# ICredentialProviderCredentialWithFieldOptions::GetFieldOptions

## Description

Retrieves the current option set for a specified field in a logon or credential UI. Called by the credential provider framework.

## Parameters

### `fieldID` [in]

The ID of the field in the logon or credential UI.

### `options` [out]

A pointer to an [CREDENTIAL_PROVIDER_CREDENTIAL_FIELD_OPTIONS](https://learn.microsoft.com/windows/desktop/api/credentialprovider/ne-credentialprovider-credential_provider_credential_field_options) value that, when this method returns successfully, receives one or more flags that specify the current options for the field.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICredentialProviderCredentialEvents2::SetFieldOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-setfieldoptions)

[ICredentialProviderCredentialWithFieldOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialwithfieldoptions)