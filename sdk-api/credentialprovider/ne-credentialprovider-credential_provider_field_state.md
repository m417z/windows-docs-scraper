# CREDENTIAL_PROVIDER_FIELD_STATE enumeration

## Description

Specifies the state of a single field in the Credential UI. Used by [CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_field_descriptor) and [ICredentialProviderCredentialEvents::SetFieldState](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents-setfieldstate). The behavior of fields may vary depending on the current field state.

## Constants

### `CPFS_HIDDEN:0`

Do not show the field in any state. One example of this would be a password edit control that should not be displayed until the user authenticates a thumb print. Until the thumb print has been authenticated, the state of the password field would be **CPFS_HIDDEN**.

### `CPFS_DISPLAY_IN_SELECTED_TILE`

Show the field when in the selected state.

### `CPFS_DISPLAY_IN_DESELECTED_TILE`

Show the field when in the deselected state. This value is only valid for a [CREDENTIAL_PROVIDER_USAGE_SCENARIO](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario) is set to **CPUS_CREDUI**.

### `CPFS_DISPLAY_IN_BOTH`

Show the field both when the credential tile is selected and when it is not selected.