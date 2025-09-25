# RasGetEntryPropertiesA function

## Description

The
**RasGetEntryProperties** function retrieves the properties of a phone-book entry.

## Parameters

### `unnamedParam1` [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

**Windows Me/98/95:** This parameter should always be **NULL**. Dial-up networking stores phone-book entries in the registry rather than in a phone-book file.

### `unnamedParam2` [in]

Pointer to a **null**-terminated string that specifies an existing entry name. If an empty string is specified, the function returns default values in the buffers pointed to by the *lpRasEntry* and *lpbDeviceInfo* parameters.

### `unnamedParam3` [in, out]

Pointer to a
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure followed by additional bytes for the alternate phone number list, if there is one.

On output, the structure receives the connection data associated with the phone-book entry specified by the *lpszEntry* parameter.

On input, set the **dwSize** member of the structure to sizeof([RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))) to identify the version of the structure.

This parameter can be **NULL**.

**Windows Me/98 and Windows 95 OSR2:** The
Microsoft Layer for Unicode does not support **dwAlternateOffset** in
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)).

### `unnamedParam4` [in, out]

Pointer to a variable that, on input, specifies the size, in bytes, of the *lpRasEntry* buffer.

On output, this variable receives the number of bytes required.

This parameter can be **NULL** if the *lpRasEntry* parameter is **NULL**.

To determine the required buffer size, call
**RasGetEntryProperties** with *lpRasEntry* set to **NULL** and **lpdwEntryInfoSize* set to zero. The function returns the required buffer size in **lpdwEntryInfoSize*.

### `unnamedParam5` [out]

This parameter is no longer used. The calling function should set this parameter to **NULL**.

**Windows Me/98/95:** Pointer to a buffer that receives device-specific configuration information. Do not directly manipulate this opaque TAPI device information. For more information about TAPI device configuration, see the
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) function in the TAPI Programmer's Reference in the Platform SDK.

This parameter can be **NULL**.

### `unnamedParam6` [in, out]

This parameter is unused. The calling function should set this parameter to **NULL**.

**Windows Me/98/95:** Pointer to a variable that, on input, specifies the size, in bytes, of the buffer specified by the *lpbDeviceInfo* parameter.

On output, this variable receives the number of bytes required.

This parameter can be **NULL** if the *lpbDeviceInfo* parameter s **NULL**.

To determine the required buffer size, call
**RasGetEntryProperties** with *lpbDeviceInfo* set to **NULL** and **lpdwDeviceInfoSize* set to zero. The function returns the required buffer size in **lpdwDeviceInfoSize*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The function was called with an invalid parameter. |
| **ERROR_INVALID_SIZE** | The value of the dwSize member of the *lpRasEntry* is too small. |
| **ERROR_BUFFER_INVALID** | The address or buffer specified by *lpRasEntry* is invalid. |
| **ERROR_BUFFER_TOO_SMALL** | The buffer size indicated in *lpdwEntryInfoSize* is too small. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The phone-book entry does not exist, or the phone-book file is corrupted and/or has missing components. |

## See also

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RasSetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrypropertiesa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)

## Remarks

> [!NOTE]
> The ras.h header defines RasGetEntryProperties as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).