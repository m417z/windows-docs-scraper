# RasSetEntryPropertiesA function

## Description

The **RasSetEntryProperties** function changes the
connection information for an entry in the phone book or creates a new phone-book entry.

## Parameters

### `unnamedParam1` [in]

Pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file.
If this parameter is **NULL**, the function uses the current default phone-book file.
The default phone-book file is the one selected by the user in the **User Preferences**
property sheet of the **Dial-Up Networking** dialog box.

### `unnamedParam2` [in]

Pointer to a null-terminated string that specifies an entry name.

If the entry name matches an existing entry,
**RasSetEntryProperties** modifies the properties
of that entry.

If the entry name does not match an existing entry,
**RasSetEntryProperties** creates a new
phone-book entry. For new entries, call the
[RasValidateEntryName](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasvalidateentrynamea) function to validate the
entry name before calling
**RasSetEntryProperties**.

### `unnamedParam3` [in]

Pointer to the [RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure that specifies the
new connection data to be associated with the phone-book entry indicated by the
*lpszEntry* parameter.

The caller must provide values for the following members in the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure.

* **dwSize**
* **szLocalPhoneNumber**
* **szDeviceName**
* **szDeviceType**
* **dwFramingProtocol**
* **dwfOptions**
* **dwType**

**Windows XP or later:** **dwType** is supported.

If values are not provided for these members,
**RasSetEntryProperties** fails with
**ERROR_INVALID_PARAMETER**.

The structure might be followed by an array of null-terminated alternate phone number strings. The last
string is terminated by two consecutive null characters. The **dwAlternateOffset**
member of the [RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure contains the offset to
the first string.

### `unnamedParam4` [in]

Specifies the size, in bytes, of the buffer identified by the *lpRasEntry*
parameter.

### `unnamedParam5` [in]

Pointer to a buffer that specifies device-specific configuration information. This is opaque TAPI device
configuration information. For more information about TAPI device configuration, see the
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) function in
[Telephony Application Programming Interfaces (TAPI)](https://learn.microsoft.com/windows/desktop/Tapi/telephony-application-programming-interfaces)
in the Platform SDK.

**Windows XP:** This parameter is unused. The calling function should set this parameter to
**NULL**.

### `unnamedParam6` [in]

Specifies the size, in bytes, of the *lpbDeviceInfo* buffer.

**Windows XP:** This parameter is unused. The calling function should set this parameter to zero.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from
[Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes)
or WinError.h.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have the correct privileges. Only an administrator can complete this task. |
| **ERROR_BUFFER_INVALID** | The address or buffer specified by *lpRasEntry* is invalid. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The phone book is corrupted or missing components. |
| **ERROR_INVALID_PARAMETER** | The [RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure pointed to by the *lpRasEntry* parameter does not contain adequate information, or the specified entry does not exist in the phone book. See the description for *lpRasEntry* to see what information is required. |

## Remarks

When setting properties for an all-users connection, if the calling application specifies a
non-**NULL** value for the phone-book parameter, *lpszPhonebook*,
the phone-book file must be located in the phone-book directory beneath the all-users application data path. To
obtain the correct location for the phone-book file, first call
[SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha) with a
[CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value of **CSIDL_COMMON_APPDATA**.
**SHGetFolderPath** returns the all-users
application data path. Append the following string to this path:

Microsoft\Network\Connections\Pbk

The combined path is the correct location for the phone-book file.

**Note** Specifying a non-**NULL** value for the *lpszPhonebook*
parameter may not be supported in versions of Windows later than Windows XP.

> [!NOTE]
> The ras.h header defines RasSetEntryProperties as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RasCreatePhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rascreatephonebookentrya)

[RasGetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrypropertiesa)

[RasValidateEntryName](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasvalidateentrynamea)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)