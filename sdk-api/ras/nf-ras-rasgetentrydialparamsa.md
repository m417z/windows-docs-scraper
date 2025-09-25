# RasGetEntryDialParamsA function

## Description

The
**RasGetEntryDialParams** function retrieves the connection information saved by the last successful call to the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasSetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrydialparamsa) function for a specified phone-book entry.

## Parameters

### `unnamedParam1` [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the *Dial-Up Networking* dialog box.

**Windows Me/98/95:** This parameter should always be **NULL**. Dial-up networking stores phone-book entries in the registry rather than in a phone-book file.

### `unnamedParam2` [in, out]

Pointer to a
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure.

On input, the **dwSize** member specifies the size of the
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure, and the **szEntryName** member specifies a valid phone-book entry.

On output, the structure receives the connection parameters associated with the specified phone-book entry.

Note that the **szPhoneNumber** member of the structure does not receive the phone number associated with the phone-book entry. To get the phone number associated with a phone-book entry, call the
[RasGetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrypropertiesa) function. If **szPhoneNumber** is an empty string in the
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure passed to
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala),
**RasDial** uses the phone number stored in the phone-book entry.

The **szPassword** member of the [RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure does not return the actual password. Instead, **szPassword** contains a handle to the saved password. Substitute this handle for the saved password in subsequent calls to
[RasSetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrydialparamsa) and
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala). When presented with this handle,
**RasDial** retrieves and uses the saved password. The value of this handle may change in future versions of the operating system; do not develop code that depends on the contents or format of this value.

**Windows NT and Windows Me/98/95:** Secure password feature not supported.

### `unnamedParam3` [out]

Pointer to a flag that indicates whether the function retrieved the password associated with the user name for the phone-book entry. The *lpfPassword* parameter is **TRUE** if the system has saved a password for the specified entry. If the system has no password saved for this entry, *lpfPassword* is **FALSE**.

**Windows NT and Windows Me/98/95:** The function sets this flag to **TRUE** if the user's password was returned in the **szPassword** member of the
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure pointed to by *lprasdialparams*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Description |
| --- | --- |
| **ERROR_BUFFER_INVALID** | The *lprasdialparams* or *lpfPassword* pointer is invalid, or the *lprasdialparams* buffer is invalid. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The phone book is corrupted or missing components. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The phone-book entry does not exist. |

## See also

[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85))

[RasCreatePhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rascreatephonebookentrya)

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasEditPhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-raseditphonebookentrya)

[RasSetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrydialparamsa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)

## Remarks

> [!NOTE]
> The ras.h header defines RasGetEntryDialParams as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).