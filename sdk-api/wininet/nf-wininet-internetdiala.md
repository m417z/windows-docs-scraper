# InternetDialA function

## Description

Initiates a connection to the Internet using a modem.

## Parameters

### `hwndParent` [in]

Handle to the parent window.

### `lpszConnectoid` [in]

Pointer to a **null**-terminated string that specifies the name of the dial-up connection to be used. If this parameter contains the empty string (""), the user chooses the connection. If this parameter is **NULL**, the function connects to the autodial connection.

### `dwFlags` [in]

Options. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| INTERNET_AUTODIAL_FORCE_ONLINE | Forces an online connection. |
| INTERNET_AUTODIAL_FORCE_UNATTENDED | Forces an unattended Internet dial-up. If user intervention is required, the function will fail. |
| INTERNET_DIAL_FORCE_PROMPT | Ignores the "dial automatically" setting and forces the dialing user interface to be displayed. |
| INTERNET_DIAL_UNATTENDED | Connects to the Internet through a modem, without displaying a user interface, if possible. Otherwise, the function will wait for user input. |
| INTERNET_DIAL_SHOW_OFFLINE | Shows the **Work Offline** button instead of the **Cancel** button in the dialing user interface. |

### `lpdwConnection` [out]

Pointer to a variable that specifies the connection number. This number is a unique identifier for the connection that can be used in other functions, such as [InternetHangUp](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internethangup).

### `dwReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

Returns ERROR_SUCCESS if successful, or an error value otherwise. The error code can be one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters are incorrect. |
| **ERROR_NO_CONNECTION** | There is a problem with the dial-up connection. |
| **ERROR_USER_DISCONNECTION** | The user clicked either the **Work Offline** or **Cancel** button on the Internet connection dialog box. |

## Remarks

**InternetDial** does not support double-dial connections, SmartCard authentication, or connections that require registry-based certification.

**Note** Starting on Windows Vista and Windows Server 2008, the WinINet dial-up functions use the [RAS functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions) to establish a dial-up connection. WinINet supports the functionality documented in the [RasDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasdialdlga) function.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetDial as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Establishing a Dial-Up Connection to the Internet](https://learn.microsoft.com/windows/desktop/WinInet/establishing-a-dial-up-connection-to-the-internet)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)