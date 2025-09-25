# RasSetCustomAuthDataW function

## Description

Use the
**RasSetCustomAuthData** function to set connection-specific authentication information. This information should not be specific to a particular user.

## Parameters

### `pszPhonebook` [in]

Pointer to a **null**-terminated string that specifies the full path of the phone-book (PBK) file. If this parameter is **NULL**, the function uses the system phone book.

### `pszEntry` [in]

Pointer to a **null**-terminated string that specifies an existing entry name.

### `pbCustomAuthData` [in]

Pointer to a buffer that specifies the new authentication data.

### `dwSizeofCustomAuthData` [in]

Specifies the size of the data pointed to by the *pbCustomAuthData* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | The *dwSizeofCustomAuthData* parameter is zero, or the *pbCustomAuthData* parameter is **NULL**. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | [RasSetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasseteapuserdataa) was unable to open the specified phone-book file. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | [RasSetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasseteapuserdataa) was unable to find the specified entry in the phone book. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[RasGetCustomAuthData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetcustomauthdataa)

[RasSetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasseteapuserdataa)

## Remarks

> [!NOTE]
> The ras.h header defines RasSetCustomAuthData as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).