# WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0 structure

## Description

The **WLX_CONSOLESWITCH_CREDENTIALS_INFO_V1_0** structure contains the client credentials returned by a call to
[WlxGetConsoleSwitchCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxgetconsoleswitchcredentials).

This allows credentials to be transparently transferred to a target session.

## Members

### `dwType`

Identifies the type of credentials structure being allocated. Credential types are defined with the prefix WLX_CONSOLESWITCHCREDENTIAL_TYPE allowing Winlogon to typecast the structure so the remainder of the structure may be referenced.

### `UserToken`

Handle of the users token.

### `LogonId`

Unique logon identifier.

### `Quotas`

QUOTA_LIMITS structure containing information on the amount of system resources available to a user.

### `UserName`

User's name as a string.

### `Domain`

User's domain as a string.

### `LogonTime`

Exact logon time.

### `SmartCardLogon`

**TRUE** if the logon was done by SmartCard.

### `ProfileLength`

Length of the user's profile in bytes.

### `MessageType`

[MSV1_0_PROFILE_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_profile_buffer_type) value identifying the type of profile data being returned. This member must be set to **MsV1_0InteractiveProfile**.

### `LogonCount`

Number of times the user is currently logged on.

**Note** This value is not guaranteed to be accurate because the domain controller is not notified of all logons and logoffs.

### `BadPasswordCount`

Number of times a password that is not valid was applied to the account since the last successful logon.

### `ProfileLogonTime`

Time when the user last logged on. This is an absolute-format Windows standard time value.

### `LogoffTime`

Time when user should log off. This is an absolute-format Windows standard time value.

### `KickOffTime`

Time when system should force the user to log off. This is an absolute-format Windows standard time value. Note that Windows users are not forced to log off interactively; however, their network connections may be closed.

### `PasswordLastSet`

Time and date the password was last changed. This is an absolute format Windows standard time value.

### `PasswordCanChange`

Time and date when the user should be reminded to change passwords. This is an absolute-format Windows standard time value. This member is used by the [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to display the prompt asking whether the user wants to change the current password.

### `PasswordMustChange`

Time and date when the user must change the password. If the user can never change the password, this member is undefined. This is an absolute-format, Windows, standard time value.

### `LogonScript`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the relative path to the account's logon script.

### `HomeDirectory`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the home directory for the user.

### `FullName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the full name of the user.

### `ProfilePath`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) specifying the path to the user's roaming profile if the user has a roaming profile. For example: \\SomeServer\SomeShare\MyUserName

### `HomeDirectoryDrive`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the drive letter (for example, C:\ or D:\) of the home directory.

### `LogonServer`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the server that processed the logon request.

### `UserFlags`

Specifies how this user established the session. This can be the following flag.

| Value | Meaning |
| --- | --- |
| **LOGON_EXTRA_SIDS** | The user logged on using extra [SIDs](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |

### `PrivateDataLen`

Length in bytes of any GINA-specific data. Set to zero if there is no GINA specific data.

### `PrivateData`

Buffer containing any GINA-specific data.