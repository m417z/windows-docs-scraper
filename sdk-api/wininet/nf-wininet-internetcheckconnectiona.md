# InternetCheckConnectionA function

## Description

[**InternetCheckConnection** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [NetworkInformation.GetInternetConnectionProfile](https://learn.microsoft.com/uwp/api/Windows.Networking.Connectivity.NetworkInformation#Windows_Networking_Connectivity_NetworkInformation_GetInternetConnectionProfile_) or the [NLM Interfaces](https://learn.microsoft.com/windows/desktop/NLA/nlm-interfaces).
]

Allows an application to check if a connection to the Internet can be established.

## Parameters

### `lpszUrl` [in]

Pointer to a **null**-terminated string that specifies the URL to use to check the connection. This value can be **NULL**.

### `dwFlags` [in]

Options. FLAG_ICC_FORCE_CONNECTION is the only flag that is currently available. If this flag is set, it forces a connection. A sockets connection is attempted in the following order:

* If
  *lpszUrl* is non-**NULL**, the host value is extracted from it and used to ping that specific host.
* If
  *lpszUrl* is **NULL** and there is an entry in the internal server database for the nearest server, the host value is extracted from the entry and used to ping that server.

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

Returns **TRUE** if a connection is made successfully, or **FALSE** otherwise. Use
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the error code. ERROR_NOT_CONNECTED is returned by
**GetLastError** if a connection cannot be made or if the sockets database is unconditionally offline.

## Remarks

**InternetCheckConnection** is deprecated. **InternetCheckConnection** does not work in environments that use a web proxy server to access the Internet. Depending on the environment, use [NetworkInformation.GetInternetConnectionProfile](https://learn.microsoft.com/uwp/api/Windows.Networking.Connectivity.NetworkInformation#Windows_Networking_Connectivity_NetworkInformation_GetInternetConnectionProfile_) or the [NLM Interfaces](https://learn.microsoft.com/windows/desktop/NLA/nlm-interfaces) to check for Internet access instead.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetCheckConnection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)