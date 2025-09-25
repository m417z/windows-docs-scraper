# InternetAutodialHangup function

## Description

Disconnects an automatic dial-up connection.

## Parameters

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. Applications can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the error code.

## Remarks

**InternetAutoDialHangup** returns **TRUE** if autodial is not enabled, or if autodial is enabled but does not have an entry configured on the computer.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Establishing a Dial-Up Connection to the Internet](https://learn.microsoft.com/windows/desktop/WinInet/establishing-a-dial-up-connection-to-the-internet)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)