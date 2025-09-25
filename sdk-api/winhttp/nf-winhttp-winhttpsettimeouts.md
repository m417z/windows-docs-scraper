## Description

The **WinHttpSetTimeouts** function sets time-outs involved with HTTP transactions.

## Parameters

### `hInternet` [in]

The [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen) or [WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest).

### `nResolveTimeout` [in]

A value of type integer that specifies the time-out value, in milliseconds, to use for name resolution. If resolution takes longer than this time-out value, then the request is canceled. The initial value is zero, meaning no time-out (infinite).

**Windows Vista and Windows XP:** If DNS timeout is specified using NAME_RESOLUTION_TIMEOUT, there is an overhead of one thread per request.

### `nConnectTimeout` [in]

A value of type integer that specifies the time-out value, in milliseconds, to use for server connection requests. If a connection request takes longer than this time-out value, the request is canceled. The initial value is 60,000 (60 seconds).

TCP/IP can time out while setting up the socket during the three leg SYN/ACK exchange, regardless of the value of this parameter.

### `nSendTimeout` [in]

A value of type integer that specifies the time-out value, in milliseconds, to use for sending requests. If sending a request takes longer than this time-out value, the send is canceled. The initial value is 30,000 (30 seconds).

### `nReceiveTimeout` [in]

A value of type integer that specifies the time-out value, in milliseconds, to receive a response to a request. If a response takes longer than this time-out value, the request is canceled. The initial value is 30,000 (30 seconds).

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |
| **ERROR_INVALID_PARAMETER** | One or more of the timeout parameters has a negative value other than -1. |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

A value of 0 or -1 sets a time-out to wait infinitely. A value greater than 0 sets the time-out value in milliseconds. For example, 30,000 would set the time-out to 30 seconds. All negative values other than -1 cause the function to fail with ERROR_INVALID_PARAMETER.

**Important** If a small timeout is set using [WinHttpSetOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) and [WINHTTP_OPTION_RECEIVE_TIMEOUT](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags), it can override the value set with the *dwReceiveTimeout* parameter, causing a response to terminate earlier than expected. To avoid this, do not set a timeout with the **WINHTTP_OPTION_RECEIVE_TIMEOUT** option that is smaller than the value set using *dwReceiveTimeout*.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHTTP start page.

#### Examples

This example shows how to set new time-out values using
**WinHttpSetTimeouts**.

```cpp
    // Use WinHttpOpen to obtain an HINTERNET handle.
    HINTERNET hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
                                    WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                    WINHTTP_NO_PROXY_NAME,
                                    WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession)
    {
        // Use WinHttpSetTimeouts to set a new time-out values.
        if (!WinHttpSetTimeouts( hSession, 10000, 10000, 10000, 10000))
            printf( "Error %u in WinHttpSetTimeouts.\n", GetLastError());

        // PLACE ADDITIONAL CODE HERE.

        // When finished, release the HINTERNET handle.
        WinHttpCloseHandle(hSession);
    }
    else
    {
        printf("Error %u in WinHttpOpen.\n", GetLastError());
    }

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)