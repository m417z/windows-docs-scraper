# USER_ALL_INFORMATION structure

## Description

The **USER_ALL_INFORMATION** structure contains information on the session user.

It is used with subauthentication functions.

## Members

### `LastLogon`

Indicates the date and time of the last logon.

### `LastLogoff`

Indicates the date and time of the last logoff.

### `PasswordLastSet`

Indicates the date and time when the password was set or last changed.

### `AccountExpires`

Indicates the date and time when the account will expire.

### `PasswordCanChange`

Indicates the date and time when the password can be changed.

### `PasswordMustChange`

Indicates the date and time when the password must change.

### `UserName`

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the user account.

### `FullName`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the full name of the user or account.

### `HomeDirectory`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the home directory of the user.

### `HomeDirectoryDrive`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the home drive name.

### `ScriptPath`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the path to any logon script.

### `ProfilePath`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the path to the user's profile.

### `AdminComment`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing a comment associated with the user account. This string can be a null string, or it can have any number of characters before the terminating null character.

### `WorkStations`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the workstation in use by the account.

### `UserComment`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing a user comment. This string can be a null string, or it can have any number of characters before the terminating null character.

### `Parameters`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) reserved for use by applications. This string can be a null string, or it can have any number of characters before the terminating null character. Microsoft products use this member to store user configuration information. Do not modify this information.

### `LmPassword`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the user's local machine password.

### `NtPassword`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing a hash of the user's Windows domain password.

### `PrivateData`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing supplemental private data associated with the user account. If **PrivateDataSensitive** is **TRUE**, this data is encrypted.

### `SecurityDescriptor`

[SR_SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-sr_security_descriptor) indicating the security [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the account.

### `UserId`

Contains the user ID from the account relative identifier (RID). This ID is used by the posix subsystem.

### `PrimaryGroupId`

Indicates the account's primary group. This ID is used by the posix subsystem.

### `UserAccountControl`

Contains flags defined in Subauth.h.

### `WhichFields`

Contains flags defined in Subauth.h.

### `LogonHours`

Indicates the hours when the user can logon.

### `BadPasswordCount`

Indicates the number of times the user tried to log on to this account using an incorrect password.

### `LogonCount`

Indicates the number of logons by the user.

### `CountryCode`

Used for localization. If not equal to zero, value is the country/region code for the user's language of choice.

### `CodePage`

Used for localization. If not equal to zero, the value is the code page for the user's language of choice.

### `LmPasswordPresent`

Indicates whether there is a local machine password.

### `NtPasswordPresent`

Indicates whether there is a Windows domain password.

### `PasswordExpired`

Indicates whether the password has expired.

### `PrivateDataSensitive`

When set to **TRUE**, indicates that the **PrivateData** member is encrypted. A value of **FALSE** indicates that the **PrivateData** is in [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).