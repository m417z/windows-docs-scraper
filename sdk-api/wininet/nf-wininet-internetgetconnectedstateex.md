# InternetGetConnectedStateEx function

## Description

**Note** Using this API is not recommended, use the [INetworkListManager::GetConnectivity](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworklistmanager-getconnectivity) method instead.

Retrieves the connected state of the specified Internet connection.

## Parameters

### `lpdwFlags` [out]

Pointer to a variable that receives the connection description. This parameter may return a valid flag even when the function returns **FALSE**. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_CONNECTION_CONFIGURED**<br><br>0x40 | Local system has a valid connection to the Internet, but it might or might not be currently connected. |
| **INTERNET_CONNECTION_LAN**<br><br>0x02 | Local system uses a local area network to connect to the Internet. |
| **INTERNET_CONNECTION_MODEM**<br><br>0x01 | Local system uses a modem to connect to the Internet. |
| **INTERNET_CONNECTION_MODEM_BUSY**<br><br>0x08 | No longer used. |
| **INTERNET_CONNECTION_OFFLINE**<br><br>0x20 | Local system is in offline mode. |
| **INTERNET_CONNECTION_PROXY**<br><br>0x04 | Local system uses a proxy server to connect to the Internet. |

### `lpszConnectionName` [out]

Pointer to a string value that receives the connection name.

### `dwNameLen` [in]

Size of the
*lpszConnectionName* string, in **TCHARs**.

### `dwReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

Returns **TRUE** if there is an Internet connection, or **FALSE** if there is no Internet connection, or if all possible Internet connections are not currently active. For more information, see the Remarks section.

When [InternetGetConnectedState](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetconnectedstate) returns **FALSE**, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the error code.

## Remarks

A return value of **TRUE** from [InternetGetConnectedState](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetconnectedstate) indicates that at least one connection to the Internet is available. It does not guarantee that a connection to a specific host can be established. Applications should always check for errors returned from API calls that connect to a server. [InternetCheckConnection](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcheckconnectiona) can be called to determine if a connection to a specific destination can be established.

A return value of **TRUE** indicates that either the modem connection is active, or a LAN connection is active and a proxy is properly configured for the LAN. A return value of **FALSE** indicates that neither the modem nor the LAN is connected. If **FALSE** is returned, the **INTERNET_CONNECTION_CONFIGURED** flag may be set to indicate that autodial is configured to "always dial" but is not currently active. If autodial is not configured, the function returns **FALSE**.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Establishing a Dial-Up Connection to the Internet](https://learn.microsoft.com/windows/desktop/WinInet/establishing-a-dial-up-connection-to-the-internet)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)