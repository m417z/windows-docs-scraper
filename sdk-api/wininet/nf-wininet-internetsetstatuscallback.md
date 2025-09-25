# InternetSetStatusCallback function

## Description

The InternetSetStatusCallback function sets up a callback function that WinINet functions can call as progress is made during an operation.

## Parameters

### `hInternet` [in]

The handle for which the callback is set.

### `lpfnInternetCallback` [in]

A pointer to the callback function to call when progress is made, or **NULL** to remove the existing callback function. For more information about the callback function, see
[InternetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nc-wininet-internet_status_callback).

## Return value

Returns the previously defined status callback function if successful, **NULL** if there was no previously defined status callback function, or INTERNET_INVALID_STATUS_CALLBACK if the callback function is not valid.

## Remarks

Both synchronous and asynchronous functions use the callback function to indicate the progress of the request, such as resolving a name, connecting to a server, and so on. The callback function is required for an asynchronous operation. The asynchronous request will call back to the application with INTERNET_STATUS_REQUEST_COMPLETE to indicate the request has been completed.

A callback function can be set on any handle, and is inherited by derived handles. A callback function can be changed using
**InternetSetStatusCallback**, providing there are no pending requests that need to use the previous callback value. Note, however, that changing the callback function on a handle does not change the callbacks on derived handles, such as that returned by
[InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta). You must change the callback function at each level.

Many of the WinINet functions perform several operations on the network. Each operation can take time to complete, and each can fail.

It is sometimes desirable to display status information during a long-term operation. You can display status information by setting up an Internet status callback function that cannot be removed as long as any callbacks or any asynchronous functions are pending.

After initiating
**InternetSetStatusCallback**, the callback function can be accessed from within any WinINet function for monitoring time-intensive network operations.

**Note** The callback function specified in the *lpfnInternetCallback* parameter will not be called on asynchronous operations for the request handle when the *dwContext* parameter of [HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) is set to zero (**INTERNET_NO_CALLBACK**), or the connection handle when the *dwContext* handle of [InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta) is set to zero (**INTERNET_NO_CALLBACK**).

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[InternetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nc-wininet-internet_status_callback)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)