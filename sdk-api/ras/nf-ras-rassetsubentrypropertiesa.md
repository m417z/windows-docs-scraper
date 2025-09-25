# RasSetSubEntryPropertiesA function

## Description

The
**RasSetSubEntryProperties** function creates a new subentry or modifies an existing subentry of a specified phone-book entry.

## Parameters

### `unnamedParam1` [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

**Windows Me/98/95:** This parameter should always be **NULL**. Dial-up networking stores phone-book entries in the registry rather than in a phone-book file.

### `unnamedParam2` [in]

Pointer to a **null**-terminated string that specifies the name of an existing entry in the phone book.

### `unnamedParam3` [in]

Specifies the one-based index of the subentry. If the index matches an existing subentry index, the function changes the properties of that subentry. If the index does not match an existing index, the function creates a new subentry.

### `unnamedParam4` [in]

Pointer to the
[RASSUBENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377839(v=vs.85)) structure that specifies the data for the subentry.

The structure might be followed by an array of **null**-terminated alternate phone number strings. The last string is terminated by two consecutive **null** characters. The **dwAlternateOffset** member of the
[RASSUBENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377839(v=vs.85)) structure contains the offset to the first string.

### `unnamedParam5` [in]

Specifies the size, in bytes, of the *lpRasSubEntry* buffer.

### `unnamedParam6` [in]

Pointer to a TAPI device configuration block. This parameter is currently unused. The caller should pass **NULL** for this parameter. For more information about TAPI device configuration blocks, see the function
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig).

### `unnamedParam7` [in]

Specifies the size of the TAPI device configuration block. This parameter is currently unused. The caller should pass zero for this parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_INVALID** | The address or buffer specified by *lpRasEntry* is invalid. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The phone-book entry does not exist. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The phone book is corrupted or missing components. |
| **ERROR_INVALID_PARAMETER** | The function was called with an invalid parameter. |

## Remarks

A RAS phone-book entry can have zero or more subentries, each minimally consisting of a device and a phone number. A phone-book entry with multiple subentries can be configured to dial either the first available subentry or all subentries when the entry is dialed.

Use the
[RasGetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrypropertiesa) function to retrieve the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure containing information about the subentries of a phone-book entry. The **dwSubEntries** member indicates the number of subentries and the **dwDialMode** member indicates the dialing configuration.

> [!NOTE]
> The ras.h header defines RasSetSubEntryProperties as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RASSUBENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377839(v=vs.85))

[RasGetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrypropertiesa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)