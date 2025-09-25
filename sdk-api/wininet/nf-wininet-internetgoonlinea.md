# InternetGoOnlineA function

## Description

Prompts the user for permission to initiate connection to a URL.

## Parameters

### `lpszURL` [in]

Pointer to a null-terminated string that specifies the URL of the website for the connection.

### `hwndParent` [in]

Handle to the parent window.

### `dwFlags` [in]

This parameter can be zero or the following flag.

| Value | Meaning |
| --- | --- |
| **INTERNET_GOONLINE_REFRESH** | This flag is not used. |

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. Applications can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the error code.

If the functions fails, it can return the following error code:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is incorrect.<br><br>The *dwFlags* parameter contains a value other than zero or **INTERNET_GOONLINE_REFRESH**. |

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetGoOnline as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Establishing a Dial-Up Connection to the Internet](https://learn.microsoft.com/windows/desktop/WinInet/establishing-a-dial-up-connection-to-the-internet)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)