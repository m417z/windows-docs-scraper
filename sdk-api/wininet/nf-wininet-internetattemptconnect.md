# InternetAttemptConnect function

## Description

Attempts to make a connection to the Internet.

## Parameters

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

Returns ERROR_SUCCESS if successful, or a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) otherwise.

## Remarks

This function allows an application to first attempt to connect before issuing any requests. A client program can use this to evoke the dial-up dialog box. If the attempt fails, the application should enter offline mode.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)