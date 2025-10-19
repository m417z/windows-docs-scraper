# RasSetEntryDialParamsA function

## Description

The
**RasSetEntryDialParams** function changes the connection information saved by the last successful call to the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
**RasSetEntryDialParams** function for a specified phone-book entry.

## Parameters

### `unnamedParam1` [in]

Pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

**Windows Me/98/95:** This parameter should always be **NULL**. Dial-up networking stores phone-book entries in the registry rather than in a phone-book file.

### `unnamedParam2` [in]

Pointer to the
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure that specifies the connection parameters to be associated with the phone-book entry.
**RasSetEntryDialParams** uses the structure's members as follows.

| Member | Meaning |
| --- | --- |
| **dwSize** | Must specify the size of ([RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85))) to identify the version of the structure. |
| **szEntryName** | A null-terminated string that identifies the phone-book entry to set parameters for. |
| **szPhoneNumber** | Not used. Set to **NULL**. |
| **szCallbackNumber** | A null-terminated string that contains the callback phone number. If **szCallbackNumber** is an empty string ( "" ), the callback number is not changed. |
| **szUserName** | A null-terminated string that contains the logon name of the user associated with this entry. If **szUserName** is an empty string, the user name is not changed. |
| **szPassword** | A null-terminated string that contains the password for the user specified by **szUserName**. If **szUserName** is an empty string, the password is not changed. If **szPassword** is an empty string and *fRemovePassword* is **FALSE**, the password is set to the empty string. If *fRemovePassword* is **TRUE**, the password stored in this phone-book entry for the user specified by **szUserName** is removed regardless of the contents of the **szPassword** string. <br><br>**Windows NT 4.0:** The password is changed to the string specified by **szPassword** regardless of whether **szUserName** is an empty string.<br><br>**Windows XP/2000:** If **szPassword** contains the password handle returned by [RasGetCredentials](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetcredentialsa) or [RasGetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrydialparamsa), **RasSetEntryDialParams** returns successfully without changing any currently saved password. |
| **szDomain** | A null-terminated string that contains the name of the domain on which to log on. If **szDomain** is an empty string, the domain name is not changed. |
| **dwSubEntry** | Specifies the (one-based) index of the initial subentry to dial when establishing the connection. |
| **dwCallbackId** | Specifies an application-defined value that RAS passes to the [RasDialFunc2](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc2) callback function. |

### `unnamedParam3` [in]

Specifies whether to remove the phone-book entry's stored password for the user indicated by *lprasdialparams*->**szUserName**. If *fRemovePassword* is **TRUE**, the password is removed. Setting fRemovePassword to **TRUE** is equivalent to checking the "Unsave Password" check box in Dial-Up Networking. When setting the password or other properties of a phone book entry, set *fRemovePassword* to **FALSE**.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Description |
| --- | --- |
| **ERROR_BUFFER_INVALID** | The address or buffer specified by *lprasdialparams* is invalid. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The phone book is corrupted or missing components. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The phone-book entry does not exist. |

## Remarks

To create a new phone-book entry, use the
[RasSetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrypropertiesa) function.

**Windows XP or later:** Do not use the
**RasSetEntryDialParams** function. To set the credentials for a phone-book entry, use the
[RasSetCredentials](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetcredentialsa) function. Set the non-credential members of
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) (for example **szCallbackNumber**, **dwSubEntry**, or **dwCallbackId**) directly in the
**RASDIALPARAMS** structure passed as a parameter to the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function.

> [!NOTE]
> The ras.h header defines RasSetEntryDialParams as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85))

[RasCreatePhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rascreatephonebookentrya)

[RasEditPhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-raseditphonebookentrya)

[RasGetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrydialparamsa)

[RasSetCredentials](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetcredentialsa)

[RasSetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrypropertiesa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)