# WinHttpSendRequest function

## Description

The **WinHttpSendRequest** function sends the specified request to the HTTP server.

## Parameters

### `hRequest` [in]

An [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest).

### `lpszHeaders` [in, optional]

A pointer to a string that contains the additional headers to append to the request. This parameter can be **WINHTTP_NO_ADDITIONAL_HEADERS** if there are no additional headers to append.

### `dwHeadersLength` [in]

An unsigned long integer value that contains the length, in characters, of the additional headers. If this parameter is **-1L** and
*pwszHeaders* is not **NULL**, this function assumes that
*pwszHeaders* is **null**-terminated, and the length is calculated.

### `lpOptional` [in, optional]

A pointer to a buffer that contains any optional data to send immediately after the request headers. This parameter is generally used for POST and PUT operations. The optional data can be the resource or data posted to the server. This parameter can be **WINHTTP_NO_REQUEST_DATA** if there is no optional data to send.

If the *dwOptionalLength* parameter is 0, this parameter is ignored and set to **NULL**.

This buffer must remain available until the request handle is closed or the call to [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) has completed.

### `dwOptionalLength` [in]

An unsigned long integer value that contains the length, in bytes, of the optional data. This parameter can be zero if there is no optional data to send.

This parameter must contain a valid length when the *lpOptional* parameter is not **NULL**. Otherwise, *lpOptional* is ignored and set to **NULL**.

### `dwTotalLength` [in]

An unsigned long integer value that contains the length, in bytes, of the total data sent. This parameter specifies the Content-Length header of the request. If the value of this parameter is greater than the length specified by
*dwOptionalLength*, then
[WinHttpWriteData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwritedata) can be used to send additional data.

*dwTotalLength* must not change between calls to **WinHttpSendRequest** for the same request. If *dwTotalLength* needs to be changed, the caller should create a new request.

### `dwContext` [in]

A pointer to a pointer-sized variable that contains an application-defined value that is passed, with the request handle, to any callback functions.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Error codes are listed in the following table.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_CANNOT_CONNECT** | Returned if connection to the server failed. |
| **ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED** | The secure HTTP server requires a client certificate. The application retrieves the list of certificate issuers by calling [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) with the **WINHTTP_OPTION_CLIENT_CERT_ISSUER_LIST** option.<br><br>If the server requests the client certificate, but does not require it, the application can alternately call [WinHttpSetOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) with the **WINHTTP_OPTION_CLIENT_CERT_CONTEXT** option. In this case, the application specifies the WINHTTP_NO_CLIENT_CERT_CONTEXT macro in the *lpBuffer* parameter of **WinHttpSetOption**. For more information, see the **WINHTTP_OPTION_CLIENT_CERT_CONTEXT** option.**Windows Server 2003 with SP1, Windows XP with SP2 and Windows 2000:** This error is not supported. |
| **ERROR_WINHTTP_CONNECTION_ERROR** | The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP version 5.1 does not support SSL2 unless the client specifically enables it. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_INVALID_URL** | The URL is invalid. |
| **ERROR_WINHTTP_LOGIN_FAILURE** | The login attempt failed. When this error is encountered, the request handle should be closed with [WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle). A new request handle must be created before retrying the function that originally produced this error. |
| **ERROR_WINHTTP_NAME_NOT_RESOLVED** | The server name cannot be resolved. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW** | Returned when an incoming response exceeds an internal WinHTTP size limit. |
| **ERROR_WINHTTP_SECURE_FAILURE** | One or more errors were found in the Secure Sockets Layer (SSL) certificate sent by the server. To determine what type of error was encountered, verify through a [WINHTTP_CALLBACK_STATUS_SECURE_FAILURE](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback) notification in a status callback function. For more information, see [WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback). |
| **ERROR_WINHTTP_SHUTDOWN** | The WinHTTP function support is shut down or unloaded. |
| **ERROR_WINHTTP_TIMEOUT** | The request timed out. |
| **ERROR_WINHTTP_UNRECOGNIZED_SCHEME** | The URL specified a scheme other than "http:" or "https:". |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code)<br><br>**Windows Server 2003, Windows XP and Windows 2000:** The TCP reservation range set with the **WINHTTP_OPTION_PORT_RESERVATION** option is not large enough to send this request. |
| **ERROR_INVALID_PARAMETER** | The content length specified in the *dwTotalLength* parameter does not match the length specified in the Content-Length header.<br><br>The *lpOptional* parameter must be **NULL** and the *dwOptionalLength* parameter must be zero when the Transfer-Encoding header is present.<br><br>The Content-Length header cannot be present when the Transfer-Encoding header is present. |
| **ERROR_WINHTTP_RESEND_REQUEST** | The application must call [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest) again due to a redirect or authentication challenge.<br><br>**Windows Server 2003 with SP1, Windows XP with SP2 and Windows 2000:** This error is not supported. |

## Remarks

Even when WinHTTP is used in asynchronous mode, that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen), this function can operate either synchronously or asynchronously. In either case, if the request is sent successfully, the application is called back with the completion status set to **WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE**. The **WINHTTP_CALLBACK_STATUS_REQUEST_ERROR** completion indicates that the operation completed asynchronously, but failed. Upon receiving the **WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE** status callback, the application can start to receive a response from the server with [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse). Before then, no other asynchronous functions can be called, otherwise, **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** is returned.

An application must not delete or alter the buffer pointed to by *lpOptional* until the request handle is closed or the call to [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) has completed, because an authentication challenge or redirect that required the optional data could be encountered in the course of receiving the response. If the operation must be aborted with [WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle), the application must keep the buffer valid until it receives the callback **WINHTTP_CALLBACK_STATUS_REQUEST_ERROR** with an **ERROR_WINHTTP_OPERATION_CANCELLED** error code.

If WinHTTP is used synchronously, that is, when **WINHTP_FLAG_ASYNC** was not set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen), an application is not called with a completion status even if a callback function is registered. While in this mode, the application can call [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) when **WinHttpSendRequest** returns.

The
**WinHttpSendRequest** function sends the specified request to the HTTP server and allows the client to specify additional headers to send along with the request.

This function also lets the client specify optional data to send to the HTTP server immediately following the request headers. This feature is generally used for write operations such as PUT and POST.

An application can use the same HTTP request handle in multiple calls to
**WinHttpSendRequest** to re-send the same request, but the application must read all data returned from the previous call before calling this function again.

The name and value of request headers added with this function are validated. Headers must be well formed. For more information about valid HTTP headers, see
[RFC 2616](https://www.ietf.org/rfc/rfc2616.txt). If an invalid header is used, this function fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
[ERROR_INVALID_PARAMETER](https://learn.microsoft.com/windows/desktop/WinHttp/error-messages). The invalid header is not added.

**Windows 2000:** When sending requests from multiple threads, there may be a significant decrease in network and CPU performance.

**Windows XP and Windows 2000:** See [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

### WinHttpSetStatusCallback

If a status callback function has been installed with
[WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback), then those of the following notifications that have been set in the *dwNotificationFlags* parameter of **WinHttpSetStatusCallback** indicate the progress in sending the request:

* WINHTTP_CALLBACK_STATUS_DETECTING_PROXY (not implemented)
* WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE (only in asynchronous mode)
* WINHTTP_CALLBACK_STATUS_REDIRECT
* WINHTTP_CALLBACK_STATUS_SECURE_FAILURE
* WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE

**Note** On Windows 7 and Windows Server 2008 R2, all of the following notifications are deprecated.

* WINHTTP_CALLBACK_STATUS_RESOLVING_NAME
* WINHTTP_CALLBACK_STATUS_NAME_RESOLVED
* WINHTTP_CALLBACK_STATUS_CONNECTING_TO_SERVER
* WINHTTP_CALLBACK_STATUS_CONNECTED_TO_SERVER
* WINHTTP_CALLBACK_STATUS_SENDING_REQUEST
* WINHTTP_CALLBACK_STATUS_REQUEST_SENT
* WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE
* WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED

If the server closes the connection, the following notifications are also sent, provided that they have been set in the *dwNotificationFlags* parameter of [WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback):

* WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION
* WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED

### Support for Greater Than 4-GB Upload

Starting in Windows Vista and Windows Server 2008, WinHttp supports uploading files up to the size of a LARGE_INTEGER (2^64 bytes) using the Content-Length header. Payload lengths specified in the call to **WinHttpSendRequest** are limited to the size of a **DWORD** (2^32 bytes). To upload data to a URL larger than a **DWORD**, the application must provide the length in the Content-Length header of the request. In this case, the WinHttp client application calls **WinHttpSendRequest** with the *dwTotalLength* parameter set to **WINHTTP_IGNORE_REQUEST_TOTAL_LENGTH**.

If the Content-Length header specifies a length less than a 2^32, the application must also specify the content length in the call to **WinHttpSendRequest**. If the *dwTotalLength* parameter does not match the length specified in the Content-Length header, the call fails and returns **ERROR_INVALID_PARAMETER**.

The Content-Length header can be added in the call to [WinHttpAddRequestHeaders](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpaddrequestheaders), or it can be specified in the *lpszHeader* parameter of **WinHttpSendRequest** as shown in the following code example.

``` syntax
BOOL fRet = WinHttpSendRequest(
			hReq,
			L"Content-Length: 68719476735\r\n",
			-1L,
			WINHTTP_NO_REQUEST_DATA,
			0,
			WINHTTP_IGNORE_REQUEST_TOTAL_LENGTH,
			pMyContent);
```

### Transfer-Encoding Header

Starting in Windows Vista and Windows Server 2008, WinHttp enables applications to perform chunked transfer encoding on data sent to the server. When the Transfer-Encoding header is present on the WinHttp request, the *dwTotalLength* parameter in the call to **WinHttpSendRequest** is set to **WINHTTP_IGNORE_REQUEST_TOTAL_LENGTH** and the application sends the entity body in one or more calls to [WinHttpWriteData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwritedata). The *lpOptional* parameter of **WinHttpSendRequest** must be **NULL** and the *dwOptionLength* parameter must be zero, otherwise an **ERROR_WINHTTP_INVALID_PARAMETER** error is returned. To terminate the chunked data transfer, the application generates a zero length chunk and sends it in the last call to **WinHttpWriteData**.

#### Examples

The following code example shows how to obtain an
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle, open an HTTP
session, create a request header, and send that header to the server.

```cpp
    BOOL  bResults = FALSE;
    HINTERNET hSession = NULL,
              hConnect = NULL,
              hRequest = NULL;

    // Use WinHttpOpen to obtain a session handle.
    hSession = WinHttpOpen(  L"A WinHTTP Example Program/1.0",
                             WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                             WINHTTP_NO_PROXY_NAME,
                             WINHTTP_NO_PROXY_BYPASS, 0);

    // Specify an HTTP server.
    if (hSession)
        hConnect = WinHttpConnect( hSession, L"www.wingtiptoys.com",
                                   INTERNET_DEFAULT_HTTP_PORT, 0);

    // Create an HTTP Request handle.
    if (hConnect)
        hRequest = WinHttpOpenRequest( hConnect, L"PUT",
                                       L"/writetst.txt",
                                       NULL, WINHTTP_NO_REFERER,
                                       WINHTTP_DEFAULT_ACCEPT_TYPES,
                                       0);

    // Send a Request.
    if (hRequest)
        bResults = WinHttpSendRequest( hRequest,
                                       WINHTTP_NO_ADDITIONAL_HEADERS,
                                       0, WINHTTP_NO_REQUEST_DATA, 0,
                                       0, 0);

    // Place additional code here.

    // Report errors.
    if (!bResults)
        printf("Error %d has occurred.\n",GetLastError());

    // Close open handles.
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

*WINHTTP_STATUS_CALLBACK*

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)

[WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse)