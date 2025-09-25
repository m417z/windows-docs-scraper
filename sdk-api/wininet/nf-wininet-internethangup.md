# InternetHangUp function

## Description

Instructs the modem to disconnect from the Internet.

## Parameters

### `dwConnection` [in]

Connection number of the connection to be disconnected.

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Establishing a Dial-Up Connection to the Internet](https://learn.microsoft.com/windows/desktop/WinInet/establishing-a-dial-up-connection-to-the-internet)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)