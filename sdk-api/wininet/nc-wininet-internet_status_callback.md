# INTERNET_STATUS_CALLBACK callback function

## Description

Prototype for an application-defined status callback function.

The **INTERNET_STATUS_CALLBACK** type defines a pointer to this callback function.*InternetStatusCallback* is a placeholder for the application-defined function name.

## Parameters

### `hInternet` [in]

The handle for which the callback function is called.

### `dwContext` [in]

A pointer to a variable that specifies the application-defined context value associated with
*hInternet*.

### `dwInternetStatus` [in]

A status code that indicates why the callback function is called. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_STATUS_CLOSING_CONNECTION** | Closing the connection to the server. The *lpvStatusInformation* parameter is **NULL**. |
| **INTERNET_STATUS_CONNECTED_TO_SERVER** | Successfully connected to the socket address (SOCKADDR) pointed to by *lpvStatusInformation*. |
| **INTERNET_STATUS_CONNECTING_TO_SERVER** | Connecting to the socket address (SOCKADDR) pointed to by *lpvStatusInformation*. |
| **INTERNET_STATUS_CONNECTION_CLOSED** | Successfully closed the connection to the server. The *lpvStatusInformation* parameter is **NULL**. |
| **INTERNET_STATUS_COOKIE_HISTORY** | Retrieving content from the cache. Contains data about past cookie events for the URL such as if cookies were accepted, rejected, downgraded, or leashed. <br><br>The *lpvStatusInformation* parameter is a pointer to an [InternetCookieHistory](https://learn.microsoft.com/windows/win32/api/wininet/ns-wininet-internet_proxy_info) structure. |
| **INTERNET_STATUS_COOKIE_RECEIVED** | Indicates the number of cookies that were accepted, rejected, downgraded (changed from persistent to session cookies), or leashed (will be sent out only in 1st party context). The *lpvStatusInformation* parameter is a **DWORD** with the number of cookies received. |
| **INTERNET_STATUS_COOKIE_SENT** | Indicates the number of cookies that were either sent or suppressed, when a request is sent. The *lpvStatusInformation* parameter is a **DWORD** with the number of cookies sent or suppressed. |
| **INTERNET_STATUS_CTL_RESPONSE_RECEIVED** | Not implemented. |
| **INTERNET_STATUS_DETECTING_PROXY** | Notifies the client application that a proxy has been detected. |
| **INTERNET_STATUS_HANDLE_CLOSING** | This handle value has been terminated. pvStatusInformation contains the address of the handle being closed. The *lpvStatusInformation* parameter contains the address of the handle being closed. |
| **INTERNET_STATUS_HANDLE_CREATED** | Used by [InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta) to indicate it has created the new handle. This lets the application call [InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle) from another thread, if the connect is taking too long. The *lpvStatusInformation* parameter contains the address of an [HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle. |
| **INTERNET_STATUS_INTERMEDIATE_RESPONSE** | Received an intermediate (100 level) status code message from the server. |
| **INTERNET_STATUS_NAME_RESOLVED** | Successfully found the IP address of the name contained in *lpvStatusInformation*. The *lpvStatusInformation* parameter points to a **PCTSTR** containing the host name. |
| **INTERNET_STATUS_P3P_HEADER** | The response has a P3P header in it. |
| **INTERNET_STATUS_P3P_POLICYREF** | Not implemented. |
| **INTERNET_STATUS_PREFETCH** | Not implemented. |
| **INTERNET_STATUS_PRIVACY_IMPACTED** | Not implemented. |
| **INTERNET_STATUS_RECEIVING_RESPONSE** | Waiting for the server to respond to a request. The *lpvStatusInformation* parameter is **NULL**. |
| **INTERNET_STATUS_REDIRECT** | An HTTP request is about to automatically redirect the request. The *lpvStatusInformation* parameter points to the new URL. At this point, the application can read any data returned by the server with the redirect response and can query the response headers. It can also cancel the operation by closing the handle. This callback is not made if the original request specified [INTERNET_FLAG_NO_AUTO_REDIRECT](https://learn.microsoft.com/windows/desktop/WinInet/api-flags). |
| **INTERNET_STATUS_REQUEST_COMPLETE** | An asynchronous operation has been completed. The *lpvStatusInformation* parameter contains the address of an [INTERNET_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_async_result) structure. |
| **INTERNET_STATUS_REQUEST_SENT** | Successfully sent the information request to the server. The *lpvStatusInformation* parameter points to a **DWORD** value that contains the number of bytes sent. |
| **INTERNET_STATUS_RESOLVING_NAME** | Looking up the IP address of the name contained in *lpvStatusInformation*. The *lpvStatusInformation* parameter points to a **PCTSTR** containing the host name. |
| **INTERNET_STATUS_RESPONSE_RECEIVED** | Successfully received a response from the server. |
| **INTERNET_STATUS_SENDING_REQUEST** | Sending the information request to the server. The *lpvStatusInformation* parameter is **NULL**. |
| **INTERNET_STATUS_STATE_CHANGE** | Moved between a secure (HTTPS) and a nonsecure (HTTP) site. The user must be informed of this change; otherwise, the user is at risk of disclosing sensitive information involuntarily. When this flag is set, the *lpvStatusInformation* parameter points to a status DWORD that contains additional flags. |

### `lpvStatusInformation` [in]

A pointer to additional status information. When the **INTERNET_STATUS_STATE_CHANGE** flag is set, *lpvStatusInformation* points to a **DWORD** that contains one or more of the following flags:

| Value | Meaning |
| --- | --- |
| **INTERNET_STATE_CONNECTED** | Connected state. Mutually exclusive with disconnected state. |
| **INTERNET_STATE_DISCONNECTED** | Disconnected state. No network connection could be established. |
| **INTERNET_STATE_DISCONNECTED_BY_USER** | Disconnected by user request. |
| **INTERNET_STATE_IDLE** | No network requests are being made by Windows Internet. |
| **INTERNET_STATE_BUSY** | Network requests are being made by Windows Internet. |
| **INTERNET_STATUS_USER_INPUT_REQUIRED** | The request requires user input to be completed. |

### `dwStatusInformationLength` [in]

The size, in bytes, of the data pointed to by
*lpvStatusInformation*.

## Remarks

Because callbacks are made during processing of the request, the application should spend little time in the callback function to avoid degrading data throughput on the network. For example, displaying a dialog box in a callback function can be such a lengthy operation that the server terminates the request.

The callback function can be called in a thread context different from the thread that initiated the request.

**Caution** Always notify the user when a state change from a secure (HTTPS) site to a nonsecure (HTTP) site occurs, to guard against involuntary information disclosure.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Asynchronous Operation](https://learn.microsoft.com/windows/desktop/WinInet/asynchronous-operation)

[Creating Status Callback Functions](https://learn.microsoft.com/windows/desktop/WinInet/creating-status-callback-functions)

[INTERNET_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_async_result)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)