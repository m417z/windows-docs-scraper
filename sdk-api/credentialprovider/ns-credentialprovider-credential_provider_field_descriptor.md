# CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR structure

## Description

Describes a single field in a credential. For example, a string or a user image.

## Members

### `dwFieldID`

Type: **DWORD**

The unique ID of the field. Fields should have a unique identifier compared to all other fields on a given credential provider. This is true regardless of whether the fields are displayed or hidden.

### `cpft`

Type: **[CREDENTIAL_PROVIDER_FIELD_TYPE](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_field_type)**

The field type.

### `pszLabel`

Type: **LPWSTR**

A pointer to a buffer containing the friendly name of the field as a null-terminated Unicode string. This is used for accessibility and queuing purposes. For example, some standard fields would have friend names of "Username", "Password", and "Log On To".

### `guidFieldType`

Type: **GUID**

A GUID that uniquely identifies a type of field. This member enables you to wrap functionality provided by existing credential providers in their own providers. Wrapping credential providers is not recommended as it can lead to unexpected behavior that disables in-box credential providers.

The following table lists the *guidFieldType* values supported by Windows. These are defined in Shlguid.h.

| Value | Meaning |
| --- | --- |
| **CPFG_LOGON_USERNAME**<br><br>da15bbe8-954sd-4fd3-b0f4-1fb5b90b174b | The user name entered into a text box. |
| **CPFG_LOGON_PASSWORD**<br><br>60624cfa-a477-47b1-8a8e-3a4a19981827 | The password entered into a text box. |
| **CPFG_SMARTCARD_USERNAME**<br><br>3e1ecf69-568c-4d96-9d59-46444174e2d6 | The user name obtained from an inserted smart card. |
| **CPFG_SMARTCARD_PIN**<br><br>4fe5263b-9181-46c1-b0a4-9dedd4db7dea | The PIN obtained from an inserted smart card. |
| **CPFG_CREDENTIAL_PROVIDER_LOGO**<br><br>2d837775-f6cd-464e-a745-482fd0b47493 | **Introduced in Windows 8**: The image used to represent a credential provider on the logon page. |
| **CPFG_CREDENTIAL_PROVIDER_LABEL**<br><br>286BBFF3-BAD4-438F-B007-79B7267C3D48 | **Introduced in Windows 8**: The label associated with a credential provider on the logon page. |

## Remarks

Each UI element presented to the user on a tile is defined by the credential provider as a field. The **CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR** is how the credential provider identifies the fields. Once a field has been defined for a particular usage scenario, it can not be added to or subtracted from. Credential providers need to fully define all of their fields before enumerating tiles. If fields are going to appear or disappear as part of the credential acquisition process, those fields still not to be defined ahead of time. Use [CREDENTIAL_PROVIDER_FIELD_STATE](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_field_state) to hide or display the fields as necessary.