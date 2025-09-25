# InternetAutodial function

## Description

Causes the modem to automatically dial the default Internet connection.

## Parameters

### `dwFlags` [in]

Controls this operation. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_AUTODIAL_FAILIFSECURITYCHECK**<br><br>0x04 | Causes **InternetAutodial** to fail if file and printer sharing is disabled for Windows 95 or later.<br><br>**Windows Server 2008 and Windows Vista:** This flag is obsolete. |
| **INTERNET_AUTODIAL_FORCE_ONLINE**<br><br>0x01 | Forces an online Internet connection. |
| **INTERNET_AUTODIAL_FORCE_UNATTENDED**<br><br>0x02 | Forces an unattended Internet dial-up. |
| **INTERNET_AUTODIAL_OVERRIDE_NET_PRESENT**<br><br>0x08 | Causes **InternetAutodial** to dial the modem connection even when a network connection to the Internet is present. |

### `hwndParent` [in]

Handle to the parent window.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. Applications can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the error code.

## Remarks

**InternetAutodial** does not support double-dial connections, SmartCard authentication, or connections that require registry-based certification.

**Note** Starting on Windows Vista and Windows Server 2008, the WinINet dial-up functions use the [RAS functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions) to establish a dial-up connection. WinINet supports the functionality documented in the [RasDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasdialdlga) function.

**InternetAutodial** does not attempt to dial if there is an existing dial-up connection on the system. Also, if there is an existing LAN connection, and **InternetAutodial** is not configured to force dial (set the **INTERNET_AUTODIAL_FORCE_ONLINE** in the *dwFlags* parameter), **InternetAutodial** does not attempt to dial the connection and returns **TRUE**.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Establishing a Dial-Up Connection to the Internet](https://learn.microsoft.com/windows/desktop/WinInet/establishing-a-dial-up-connection-to-the-internet)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)