# RasGetSubEntryPropertiesA function

## Description

The
**RasGetSubEntryProperties** function retrieves information about a subentry for a specified phone-book entry.

## Parameters

### `unnamedParam1` [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

**Windows Me/98/95:** This parameter should always be **NULL**. Dial-up networking stores phone-book entries in the registry rather than in a phone-book file.

### `unnamedParam2` [in]

Pointer to a **null**-terminated string that specifies the name of an existing entry in the phone book.

### `unnamedParam3` [in]

Specifies the one-based index of the subentry.

### `unnamedParam4` [in, out]

Pointer to the
[RASSUBENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377839(v=vs.85)) structure followed by additional bytes for the alternate phone number list, if there is one.

On output, the structure receives information about the specified subentry.

On input, the **dwSize** member specifies the size of the structure. The size identifies the version of the structure. Obtain this size using sizeof([RASSUBENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377839(v=vs.85))).

This parameter can be **NULL**.

### `unnamedParam5` [in, out]

Pointer to a variable that specifies, on input, the size, in bytes, of the *lpRasSubEntry* buffer.

On output, the variable receives the number of bytes returned, or the number of bytes required if the buffer is too small.

This parameter can be **NULL** if *lpRasSubEntry* is **NULL**.

### `unnamedParam6` [in]

Pointer to a TAPI device configuration block. This parameter is currently unused. The caller should pass **NULL** for this parameter. For more information about TAPI device configuration blocks, see the function
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig).

### `unnamedParam7` [in]

Pointer to a **DWORD** that specifies the size of the TAPI device configuration block. This parameter is currently unused. The caller should pass **NULL** for this parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The function was called with an invalid parameter. |
| **ERROR_BUFFER_INVALID** | The address or buffer specified by *lpRasSubEntry* is invalid. |
| **ERROR_BUFFER_TOO_SMALL** | The *lpRasSubEntry* buffer is too small. The *lpdwcb* variable receives the required buffer size. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The phone book is corrupted or is missing components. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The phone-book entry does not exist. |

## Remarks

A RAS phone-book entry can have zero or more subentries, each minimally consisting of a device and a phone number. A phone-book entry with multiple subentries can be configured to dial the first available or all subentries when the entry is dialed.

Use the
[RasGetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrypropertiesa) function to retrieve a
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure containing information about the subentries of a phone-book entry. The **dwSubEntries** member indicates the number of subentries and the **dwDialMode** member indicates the dialing configuration.

> [!NOTE]
> The ras.h header defines RasGetSubEntryProperties as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RASSUBENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377839(v=vs.85))

[RasGetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrypropertiesa)

[RasSetSubEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetsubentrypropertiesa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)