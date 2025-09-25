# RasSetEapUserDataW function

## Description

Use the
**RasSetEapUserData** function to store user-specific Extensible Authentication Protocol (EAP) information for the specified phone-book entry in the registry.

## Parameters

### `hToken` [in]

Handle to a primary or impersonation access token that represents the user for which to store data. This parameter can be **NULL** if the function is called from a process already running in the user's context.

### `pszPhonebook` [in]

Pointer to a **null**-terminated string that specifies the full path of the phone-book (PBK) file. If this parameter is **NULL**, the function uses the system phone book.

### `pszEntry` [in]

Pointer to a **null**-terminated string that specifies an existing entry name.

### `pbEapData` [in]

Pointer to the data to store for the user.

### `dwSizeofEapData` [in]

Specifies the size of the data pointed to by the *pbEapData* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | The *dwSizeofEapData* parameter is zero, or the *pbEapData* parameter is **NULL**. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | **RasSetEapUserData** was unable to open the specified phone-book file. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | **RasSetEapUserData** was unable to find the specified entry in the phone book. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[RasGetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuserdataa)

[RasInvokeEapUI](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasinvokeeapui)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)

## Remarks

> [!NOTE]
> The ras.h header defines RasSetEapUserData as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).