# RasGetCustomAuthDataA function

## Description

Use the
**RasGetCustomAuthData** function to retrieve connection-specific authentication information. This information is not specific to a particular user.

## Parameters

### `pszPhonebook` [in]

Pointer to a **null**-terminated string that specifies the full path of the phone-book (PBK) file. If this parameter is **NULL**, the function uses the system phone book.

### `pszEntry` [in]

Pointer to a **null**-terminated string that specifies an existing entry name.

### `pbCustomAuthData` [out]

Pointer to a buffer that receives the authentication data. The caller should allocate the memory for this buffer. If the buffer is not large enough,
**RasGetCustomAuthData** returns ERROR_BUFFER_TOO_SMALL, and the *pdwSizeofEapData* parameter contains the required size.

### `pdwSizeofCustomAuthData` [in, out]

Pointer to a **DWORD** variable that, on input, specifies the size of the buffer pointed to by the *pbCustomAuthData* parameter.

If the buffer specified by the *pbCustomAuthData* parameter is not large enough, *pdwSizeofEapData* receives, on output, the required size.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | The *pdwSizeofCustomAuthData* parameter is **NULL**. |
| **ERROR_BUFFER_TOO_SMALL** | The buffer pointed to by *pbCustomAuthData* is too small to receive the data. The *pdwSizeofCustomAuthData* contains the required size. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | [RasGetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuserdataa) was unable to open the specified phone-book file. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | [RasGetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuserdataa) was unable to find the specified entry in the phone book. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[RasGetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuserdataa)

[RasSetCustomAuthData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetcustomauthdataa)

## Remarks

> [!NOTE]
> The ras.h header defines RasGetCustomAuthData as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).