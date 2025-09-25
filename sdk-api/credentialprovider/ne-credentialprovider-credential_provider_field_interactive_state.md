# CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE enumeration

## Description

Describes the state of a field and how it a user can interact with it. Fields can be displayed by a credential provider in a variety of different interactive states. Used by [ICredentialProviderCredential::GetFieldState](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-getfieldstate) and [ICredentialProviderCredentialEvents::SetFieldInteractiveState](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents-setfieldinteractivestate).

## Constants

### `CPFIS_NONE:0`

The field can be edited if the field type supports editing. It also contains none of the other available interactive states.

### `CPFIS_READONLY`

Reserved and not used.

### `CPFIS_DISABLED`

The field is disabled. The user can see it but not interact with it. This support was added starting with Windows 10.

### `CPFIS_FOCUSED`

Credential providers use this field interactive state to indicate that the field should receive initial keyboard focus. This interactive state may not be specified for field types that the user cannot edit. If several editable fields specify this state, the last of them based on *dwIndex* order receives focus. On systems before Windows 10, it was the first of editable fields based on *dwIndex* order. This field interactive state is obeyed only during initial enumeration.

## Remarks

Starting with Windows 10, field interactive states are set during the initial rendering of the Credential UI and when the credential provider fires interactive state change events. An example of this event would be when the user enters digits in the first field and the credential provider automatically moves the cursor to the second field. Be careful when you fire interactive state change events because it could interrupt users entering credential data.