# RasSetCredentialsW function

## Description

The **RasSetCredentials** function sets the
user credentials associated with a specified RAS phone-book entry.

## Parameters

### `unnamedParam1` [in]

A pointer to a null-terminated string that specifies the full path and file name of a phone-book
(PBK) file. If this parameter is **NULL**, the function uses the current
default phone-book file. The default phone-book file is the one selected by the user in the
**User Preferences** property sheet of the
**Dial-Up Networking** dialog box.

### `unnamedParam2` [in]

A pointer to a null-terminated string that specifies the name of a phone-book entry.

### `unnamedParam3` [in]

A pointer to a [RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)) structure that
specifies the user credentials to set for the specified phone-book entry. Before calling
**RasSetCredentials**, set the
**dwSize** member of the structure to
`sizeof(RASCREDENTIALS)` and set the **dwMask**
member to indicate the credential information to be set.

### `unnamedParam4` [in]

A value that specifies whether
**RasSetCredentials** clears existing credentials by
setting them to the empty string, "". If this flag is **TRUE**, the
**dwMask** member of the
[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)) structure indicates which
credentials that the function sets to the empty string. If this flag is **FALSE**, the
function sets the indicated credentials according to the contents of their corresponding
**RASCREDENTIALS** members.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from
[Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes)
or WinError.h.

| Value | Meaning |
| --- | --- |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The specified phone book cannot be found. |
| **ERROR_INVALID_PARAMETER** | The *lpCredentials* parameter was **NULL**, or the specified entry does not exist in the phone book. |
| **ERROR_ACCESS_DENIED** | One of the following conditions occurred:<br><br>* The calling application attempted to set default credentials for a per-user connection. Default   credentials can be set only for an all-user connection.<br>* The user does not have the correct privileges to set pre-shared keys or credentials for all users in   case of all-user connectoids. Only administrators can complete these tasks. |

## Remarks

The **RasSetCredentials** function sets the user
credentials associated with a specified RAS phone-book entry. The credentials stored with a phone-book entry are
the credentials of the last user to successfully connect by using the specified phone-book entry, or the
credentials subsequently specified in a call to the
**RasSetCredentials** or
[RasSetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrydialparamsa) function for the
phone-book entry.

The **RasSetCredentials** function is the preferred
way of securely storing credentials with a phone-book entry.
**RasSetCredentials** supersedes the
[RasSetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrydialparamsa) function, which may not be
supported in future releases of the Windows operating system.

A password handle is "****************" (16 asterisks). If you call
[RasGetCredentials](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetcredentialsa) and receive 16 *s back in the
password field, you have a stored password and, for security reasons, it will not be given back to you in plain
text. If the **szPassword** member of the
[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)) structure contains the password handle
(16 *s) returned by **RasGetCredentials** or
[RasGetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrydialparamsa), the next call to
**RasSetCredentials** will not change the saved
password.

To set the default credentials for an all-user connection, set the
**RASCM_DefaultCreds** flag in the **dwMask** member of the
[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)) structure pointed to by
the *lpCredentials* parameter. If you attempt to set default credentials for a per-user
connection, **RasSetCredentials** returns
**ERROR_ACCESS_DENIED**.

When setting credentials for an all-users connection, if
the calling application specifies a non-NULL value for the phone-book parameter,
*lpszPhonebook*, the phone-book file must be located in the phone-book directory beneath
the all-users application data path. To obtain the correct location for the phone-book file, first call
[SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha) with a
[CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value of **CSIDL_COMMON_APPDATA**.
**SHGetFolderPath** returns the all-users
application data path. Append the following string to this path:

Microsoft\Network\Connections\Pbk

The combined path is the correct location for the phone-book file.

**Note** Specifying a non-NULL value for the *lpszPhonebook* parameter may not be supported in
later versions of the Windows operating system.

To set a pre-shared key, use the **RASCM_PreSharedKey** flag in the
[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)).**dwMask**
field.

> [!NOTE]
> The ras.h header defines RasSetCredentials as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85))

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasGetCredentials](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetcredentialsa)

[RasSetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrydialparamsa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)