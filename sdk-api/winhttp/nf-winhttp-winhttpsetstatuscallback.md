# WinHttpSetStatusCallback function

## Description

The **WinHttpSetStatusCallback** function sets up a callback function that WinHTTP can call as progress is made during an operation.

## Parameters

### `hInternet` [in]

[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle for which the callback is to be set.

### `lpfnInternetCallback` [in]

Pointer to the callback function to call when progress is made. Set this to **NULL** to remove the existing callback function. For more information about the callback function, see
[WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback).

### `dwNotificationFlags` [in]

Unsigned long integer value that specifies flags to indicate which
events activate the callback function.

The possible values are as follows.

| Value | Meaning |
| --- | --- |
| **WINHTTP_CALLBACK_FLAG_ALL_COMPLETIONS** | Activates upon any completion notification. This flag specifies that all notifications required for read or write operations are used. See [WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback) for a list of completions. |
| **WINHTTP_CALLBACK_FLAG_ALL_NOTIFICATIONS** | Activates upon any status change notification including completions. See [WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback) for a list of notifications. |
| **WINHTTP_CALLBACK_FLAG_RESOLVE_NAME** | Activates upon beginning and completing name resolution. |
| **WINHTTP_CALLBACK_FLAG_CONNECT_TO_SERVER** | Activates upon beginning and completing connection to the server. |
| **WINHTTP_CALLBACK_FLAG_DETECTING_PROXY** | Activates when detecting the proxy server. |
| **WINHTTP_CALLBACK_FLAG_DATA_AVAILABLE** | Activates when completing a query for data. |
| **WINHTTP_CALLBACK_FLAG_HEADERS_AVAILABLE** | Activates when the response headers are available for retrieval. |
| **WINHTTP_CALLBACK_FLAG_READ_COMPLETE** | Activates upon completion of a data-read operation. |
| **WINHTTP_CALLBACK_FLAG_REQUEST_ERROR** | Activates when an asynchronous error occurs. |
| **WINHTTP_CALLBACK_FLAG_SEND_REQUEST** | Activates upon beginning and completing the sending of a request header with [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest). |
| **WINHTTP_CALLBACK_FLAG_SENDREQUEST_COMPLETE** | Activates when a request header has been sent with [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest). |
| **WINHTTP_CALLBACK_FLAG_WRITE_COMPLETE** | Activates upon completion of a data-post operation. |
| **WINHTTP_CALLBACK_FLAG_RECEIVE_RESPONSE** | Activates upon beginning and completing the receipt of a resource from the HTTP server. |
| **WINHTTP_CALLBACK_FLAG_CLOSE_CONNECTION** | Activates when beginning and completing the closing of an HTTP connection. |
| **WINHTTP_CALLBACK_FLAG_HANDLES** | Activates when an [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle is created or closed. |
| **WINHTTP_CALLBACK_FLAG_REDIRECT** | Activates when the request is redirected. |
| **WINHTTP_CALLBACK_FLAG_INTERMEDIATE_RESPONSE** | Activates when receiving an intermediate (100 level) status code message from the server. |
| **WINHTTP_CALLBACK_FLAG_SECURE_FAILURE** | Activates upon a secure connection failure. |

### `dwReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

If successful, returns a pointer to the previously defined status callback function or **NULL** if there was no previously defined status callback function. Returns **WINHTTP_INVALID_STATUS_CALLBACK** if the callback function could not be installed. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

If you set the callback on the session handle before creating the request handle, the request handle inherits the callback function pointer from its parent session.

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Both synchronous and asynchronous functions use the callback function to indicate the progress of the request, such as resolving a name, connecting to a server, and so on. The callback function is required for an asynchronous operation.

A callback function can be set on any handle and is inherited by derived handles. A callback function can be changed using
**WinHttpSetStatusCallback**, provided there are no pending requests that need to use the previous callback value. However, changing the callback function on a handle does not change the callbacks on derived handles, such as that returned by
[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect). You must change the callback function at each level.

Many WinHTTP functions perform several operations on the network. Each operation can take time to complete and each can fail.

After initiating the
**WinHttpSetStatusCallback** function, the callback function can be accessed from within WinHTTP for monitoring time-intensive network operations.

At the end of asynchronous processing, the application may set the callback function to **NULL**. This prevents the client application from receiving additional notifications.

The following code snippet shows the recommended method for setting the callback function to **NULL**.

``` syntax
WinHttpSetStatusCallback( hOpen,
                          NULL,
                          WINHTTP_CALLBACK_FLAG_ALL_NOTIFICATIONS,
                          NULL );

```

Note, however, that WinHTTP does not synchronize **WinHttpSetStatusCallback** with worker threads. If a callback originating in another thread is in progress when an application calls **WinHttpSetStatusCallback**, the application still receives a callback notification even after **WinHttpSetStatusCallback** successfully sets the callback function to **NULL** and returns.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

## Examples

The following example shows how to install a callback function for asynchronous WinHTTP functions. The example assumes that a
[WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback) function named "AsyncCallback( )" has been previously implemented:

```cpp
    // Use WinHttpOpen to obtain an HINTERNET handle.
    HINTERNET hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
                                    WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                    WINHTTP_NO_PROXY_NAME,
                                    WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession)
    {
        // Install the status callback function.
        WINHTTP_STATUS_CALLBACK isCallback = WinHttpSetStatusCallback( hSession,
                                               (WINHTTP_STATUS_CALLBACK)AsyncCallback,
                                               WINHTTP_CALLBACK_FLAG_ALL_NOTIFICATIONS,
                                               NULL);

        // Place additional code here.

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

[WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)