# WINHTTP_STATUS_CALLBACK callback function

## Description

The **WINHTTP_STATUS_CALLBACK** type represents an application-defined status callback function.

## Parameters

### `hInternet` [in]

The handle for which the callback function is called.

### `dwContext` [in]

A pointer to a **DWORD** that specifies the application-defined context value associated with the handle in the
*hInternet* parameter.

A context value can be assigned to a Session, Connect, or Request handle by calling [WinHttpSetOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) with the [WINHTTP_OPTION_CONTEXT_VALUE](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags) option. Alternatively, [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest) can be used to associate a context value with a Request handle.

### `dwInternetStatus` [in]

Points to a **DWORD** that specifies the status code that indicates why the callback function is called. This can be one of the following values:

#### WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION

Closing the connection to the server. The
*lpvStatusInformation* parameter is **NULL**.

#### WINHTTP_CALLBACK_STATUS_CONNECTED_TO_SERVER

Successfully connected to the server. The
*lpvStatusInformation* parameter contains a pointer to an **LPWSTR** that indicates the IP address of the server in dotted notation.

#### WINHTTP_CALLBACK_STATUS_CONNECTING_TO_SERVER

Connecting to the server. The
*lpvStatusInformation* parameter contains a pointer to an **LPWSTR** that indicates the IP address of the server in dotted notation.

#### WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED

Successfully closed the connection to the server. The
*lpvStatusInformation* parameter is **NULL**.

#### WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE

Data is available to be retrieved with
[WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata). The *lpvStatusInformation* parameter points to a **DWORD** that contains the number of bytes of data available. The *dwStatusInformationLength*
parameter itself is 4 (the size of a **DWORD**).

#### WINHTTP_CALLBACK_STATUS_HANDLE_CREATED

An
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle has been created. The
*lpvStatusInformation* parameter contains a pointer to the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle.

#### WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING

This handle value has been terminated. The
*lpvStatusInformation* parameter contains a pointer to the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle. There will be no more callbacks for this handle.

#### WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE

The response header has been received and is available with
[WinHttpQueryHeaders](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryheaders). The
*lpvStatusInformation* parameter is **NULL**.

#### WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE

Received an intermediate (100 level) status code message from the server. The
*lpvStatusInformation* parameter contains a pointer to a **DWORD** that indicates the status code.

#### WINHTTP_CALLBACK_STATUS_NAME_RESOLVED

Successfully found the IP address of the server. The
*lpvStatusInformation* parameter contains a pointer to a **LPWSTR** that indicates the name that was resolved.

#### WINHTTP_CALLBACK_STATUS_READ_COMPLETE

Data was successfully read from the server. The
*lpvStatusInformation* parameter contains a pointer to the buffer specified in the call to
[WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata). The
*dwStatusInformationLength* parameter contains the number of bytes read.

When used by [WinHttpWebSocketReceive](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketreceive), the
*lpvStatusInformation* parameter contains a pointer to a [WINHTTP_WEB_SOCKET_STATUS](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_web_socket_status) structure, and the
*dwStatusInformationLength* parameter indicates the size of *lpvStatusInformation*.

#### WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE

Waiting for the server to respond to a request. The
*lpvStatusInformation* parameter is **NULL**.

#### WINHTTP_CALLBACK_STATUS_REDIRECT

An HTTP request is about to automatically redirect the request. The
*lpvStatusInformation* parameter contains a pointer to an **LPWSTR** indicating the new URL. At this point, the application can read any data returned by the server with the redirect response and can query the response headers. It can also cancel the operation by closing the handle.

#### WINHTTP_CALLBACK_STATUS_REQUEST_ERROR

An error occurred while sending an HTTP request. The
*lpvStatusInformation* parameter contains a pointer to a
[WINHTTP_ASYNC_RESULT](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_async_result) structure. Its **dwResult** member indicates the ID of the called function and **dwError** indicates the return value.

#### WINHTTP_CALLBACK_STATUS_REQUEST_SENT

Successfully sent the information request to the server. The
*lpvStatusInformation* parameter contains a pointer to a **DWORD** indicating the number of bytes sent.

#### WINHTTP_CALLBACK_STATUS_RESOLVING_NAME

Looking up the IP address of a server name. The
*lpvStatusInformation* parameter contains a pointer to the server name being resolved.

#### WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED

Successfully received a response from the server. The
*lpvStatusInformation* parameter contains a pointer to a **DWORD** indicating the number of bytes received.

#### WINHTTP_CALLBACK_STATUS_SECURE_FAILURE

One or more errors were encountered while establishing a Secure (HTTPS) connection to the server. The
*lpvStatusInformation* parameter contains a pointer to a **DWORD** that is a bitwise-OR combination of
error values. For more information, see the description for *lpvStatusInformation*.

#### WINHTTP_CALLBACK_STATUS_SENDING_REQUEST

Sending the information request to the server. The
*lpvStatusInformation* parameter is **NULL**.

#### WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE

The request completed successfully. The
*lpvStatusInformation* parameter is the lpOptional value passed to
[WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest) (the initial request body),
and the *dwStatusInformationLength* parameter indicates the number of such initial body bytes successfully
written (the dwOptionalLength value passed to WinHttpSendRequest).

#### WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE

Data was successfully written to the server. The
*lpvStatusInformation* parameter contains a pointer to a **DWORD** that indicates the number of bytes written.

When used by [WinHttpWebSocketSend](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketreceive), the
*lpvStatusInformation* parameter contains a pointer to a [WINHTTP_WEB_SOCKET_STATUS](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_web_socket_status) structure, and the
*dwStatusInformationLength* parameter indicates the size of *lpvStatusInformation*.

#### WINHTTP_CALLBACK_STATUS_GETPROXYFORURL_COMPLETE

The operation initiated by a call to [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex) is complete. Data is available to be retrieved with
[WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata).

#### WINHTTP_CALLBACK_STATUS_CLOSE_COMPLETE

The connection was successfully closed via a call to [WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose).
The *lpvStatusInformation* parameter is **NULL**.

#### WINHTTP_CALLBACK_STATUS_SHUTDOWN_COMPLETE

The connection was successfully shut down via a call to [WinHttpWebSocketShutdown](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketshutdown).
The *lpvStatusInformation* parameter is **NULL**.

### `lpvStatusInformation` [in]

A pointer to a buffer that specifies information pertinent to this call to the callback function. The format of these data depends on the value of the *dwInternetStatus* argument. For more information, see *dwInternetStatus*.

If the *dwInternetStatus* argument is WINHTTP_CALLBACK_STATUS_SECURE_FAILURE, then *lpvStatusInformation* points to a DWORD which is a bitwise-OR combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **WINHTTP_CALLBACK_STATUS_FLAG_CERT_REV_FAILED** | Certification revocation checking has been enabled, but the revocation check failed to verify whether a certificate has been revoked. The server used to check for revocation might be unreachable. |
| **WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CERT** | SSL certificate is invalid. |
| **WINHTTP_CALLBACK_STATUS_FLAG_CERT_REVOKED** | SSL certificate was revoked. |
| **WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CA** | The function is unfamiliar with the Certificate Authority that generated the server's certificate. |
| **WINHTTP_CALLBACK_STATUS_FLAG_CERT_CN_INVALID** | SSL certificate common name (host name field) is incorrect, for example, if you entered www.microsoft.com and the common name on the certificate says www.msn.com. |
| **WINHTTP_CALLBACK_STATUS_FLAG_CERT_DATE_INVALID** | SSL certificate date that was received from the server is bad. The certificate is expired. |
| **WINHTTP_CALLBACK_STATUS_FLAG_SECURITY_CHANNEL_ERROR** | The application experienced an internal error loading the SSL libraries. |

### `dwStatusInformationLength` [in]

**WINHTTP_CALLBACK_STATUS_REDIRECT** status callbacks provide a *dwStatusInformationLength* value that corresponds to the character count of the **LPWSTR** pointed to by *lpvStatusInformation*.

## Remarks

The callback function must be threadsafe and reentrant because it can be called on another thread for a separate request, and reentered on the same thread for the current request. It must therefore be coded to handle reentrance safely while processing. When the *dwInternetStatus* parameter is equal to **WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING**, the callback does not need to be able to handle reentrance for the same request, because this callback is guaranteed to be the last, and does not occur when other messages for this request are handled.

The status callback function receives updates on the status of asynchronous operations through notification flags. Notifications that indicate a particular operation is complete are called completion notifications, or just completions. The following table lists the six completion flags and the corresponding function that is complete when this flag is received.

| Completion flag | Function |
| --- | --- |
| WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE | [WinHttpQueryDataAvailable](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpquerydataavailable) |
| WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE | [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) |
| WINHTTP_CALLBACK_STATUS_READ_COMPLETE | [WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata) |
| WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE | [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest) |
| WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE | [WinHttpWriteData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwritedata) |
| WINHTTP_CALLBACK_STATUS_REQUEST_ERROR | Any of the above functions when an error occurs. |

Because callbacks are made during the processing of the request, the application should spend as little time as possible in the callback function to avoid degrading data throughput on the network. For example, displaying a dialog box in a callback function can be such a lengthy operation that the server terminates the request.

The callback function can be called in a thread context different from the thread that initiated the request.

Similarly, there is no callback thread affinity when you call WinHttp asynchronously: a call might start from one thread, but any other thread can receive the callback.

**Note** For more information about implementation in Windows XP and Windows 2000, see [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback)