# KERB_INTERACTIVE_PROFILE structure

## Description

The **KERB_INTERACTIVE_PROFILE** structure contains information about an interactive logon profile.

This structure is used by the [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function.

## Members

### `MessageType`

[KERB_PROFILE_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_profile_buffer_type) value identifying the type of logon request being made. This member can be set to **KerbInteractiveProfile**.

### `LogonCount`

Number of times the user is currently logged on.

### `BadPasswordCount`

Number of times a bad password was applied to the account since the last successful logon.

### `LogonTime`

Time when the user last logged on. This is an absolute-format standard time value.

### `LogoffTime`

Time when user should log off. This is an absolute-format standard time value.

### `KickOffTime`

Time when system should force user logoff. This is an absolute-format standard time value.

### `PasswordLastSet`

Time and date the password was last set. This is an absolute-format standard time value.

### `PasswordCanChange`

Time and date when the user can change the password. This is an absolute-format standard time value. To prevent a password from ever changing, set this member to a date very far into the future.

### `PasswordMustChange`

Time and date when the user must change the password. If the user can never change the password, this member is undefined. This is an absolute-format standard time value.

### `LogonScript`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the relative path to the account's logon script.

### `HomeDirectory`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the user's home directory.

### `FullName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the user's full name.

### `ProfilePath`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the path to a user's roaming profile. This is used only if the user has a roaming profile.

### `HomeDirectoryDrive`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the drive containing the user's home directory.

### `LogonServer`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the server that processed the logon request.

### `UserFlags`

Specifies how this user established the session. This can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **LOGON_EXTRA_SIDS** | The user logged on using extra [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs). |
| **LOGON_RESOURCE_GROUPS** | The user logged on using a domain local group. |