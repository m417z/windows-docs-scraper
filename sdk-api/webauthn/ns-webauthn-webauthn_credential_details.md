## Description

The structure containing the credential data.

## Syntax

```cpp
typedef struct _WEBAUTHN_CREDENTIAL_DETAILS {
  DWORD                             dwVersion;
  DWORD                             cbCredentialID;
  PBYTE                             pbCredentialID;
  PWEBAUTHN_RP_ENTITY_INFORMATION   pRpInformation;
  PWEBAUTHN_USER_ENTITY_INFORMATION pUserInformation;
  BOOL                              bRemovable;
  BOOL                              bBackedUp;
} WEBAUTHN_CREDENTIAL_DETAILS, *PWEBAUTHN_CREDENTIAL_DETAILS;
```

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `cbCredentialID`

The size of pbCredentialID.

### `pbCredentialID`

The credential Id.

### `pRpInformation`

The relying party information.

### `pUserInformation`

The user information.

### `bRemovable`

Indicates if the credential is removable or not.

### `bBackedUp`

Indicates if the credential is backed up or not.

## Remarks

## See also

[WEBAUTHN_CREDENTIAL](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_credential)

[WEBAUTHN_CREDENTIAL_DETAILS_LIST](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_credential_details_list)