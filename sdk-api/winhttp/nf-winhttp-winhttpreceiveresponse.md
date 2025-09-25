# WinHttpReceiveResponse function

## Description

The **WinHttpReceiveResponse** function waits to receive the response to an HTTP request initiated by [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest). When **WinHttpReceiveResponse** completes successfully, the status code and response headers have been received and are available for the application to inspect using [WinHttpQueryHeaders](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryheaders). An application must call **WinHttpReceiveResponse** before it can use [WinHttpQueryDataAvailable](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpquerydataavailable) and [WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata) to access the response entity body (if any).

## Parameters

### `hRequest` [in]

[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest) and sent by
[WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest). Wait until **WinHttpSendRequest** has completed for this handle before calling **WinHttpReceiveResponse**.

### `lpReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_CANNOT_CONNECT** | Returned if connection to the server failed. |
| **ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW** | Returned when an overflow condition is encountered in the course of parsing chunked encoding. |
| **ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED** | Returned when the server requests client authentication. |
| **ERROR_WINHTTP_CONNECTION_ERROR** | The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP version 5.1 does not support SSL2 unless the client specifically enables it. |
| **ERROR_WINHTTP_HEADER_COUNT_EXCEEDED** | Returned when a larger number of headers were present in a response than WinHTTP could receive. |
| **ERROR_WINHTTP_HEADER_SIZE_OVERFLOW** | Returned by [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) when the size of headers received exceeds the limit for the request handle. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_INVALID_SERVER_RESPONSE** | The server response could not be parsed. |
| **ERROR_WINHTTP_INVALID_URL** | The URL is invalid. |
| **ERROR_WINHTTP_LOGIN_FAILURE** | The login attempt failed. When this error is encountered, the request handle should be closed with [WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle). A new request handle must be created before retrying the function that originally produced this error. |
| **ERROR_WINHTTP_NAME_NOT_RESOLVED** | The server name could not be resolved. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_REDIRECT_FAILED** | The redirection failed because either the scheme changed or all attempts made to redirect failed (default is five attempts). |
| **ERROR_WINHTTP_RESEND_REQUEST** | The WinHTTP function failed. The desired function can be retried on the same request handle. |
| **ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW** | Returned when an incoming response exceeds an internal WinHTTP size limit. |
| **ERROR_WINHTTP_SECURE_FAILURE** | One or more errors were found in the Secure Sockets Layer (SSL) certificate sent by the server. To determine what type of error was encountered, check for a [WINHTTP_CALLBACK_STATUS_SECURE_FAILURE](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback) notification in a status callback function. For more information, see [WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback). |
| **ERROR_WINHTTP_TIMEOUT** | The request has timed out. |
| **ERROR_WINHTTP_UNRECOGNIZED_SCHEME** | The URL specified a scheme other than "http:" or "https:". |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function can operate either synchronously or asynchronously. If this function returns **FALSE**, this function failed and you can call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information. If this function returns **TRUE**, the application should expect either the **WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE** completion callback, indicating success, or the **WINHTTP_CALLBACK_STATUS_REQUEST_ERROR** completion callback, indicating that the operation completed asynchronously, but failed.

If a status callback function has been installed with
[WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback), then those of the following notifications that have been set in the *dwNotificationFlags* parameter of **WinHttpSetStatusCallback** indicate progress in receiving the response:

* WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE
* WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED
* WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE
* WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE
* WINHTTP_CALLBACK_STATUS_REDIRECT

If the server closes the connection, the following notifications will also be reported, provided that they have been set in the *dwNotificationFlags* parameter of [WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback):

* WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION
* WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

#### Examples

This example shows code that writes data to an HTTP server. The server name supplied in the example, www.wingtiptoys.com, is fictitious and must be replaced with the name of a server for which you have write access.

```cpp
    LPSTR pszData = "WinHttpWriteData Example";
    DWORD dwBytesWritten = 0;
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
                                       (DWORD)strlen(pszData), 0);

    // Write data to the server.
    if (bResults)
        bResults = WinHttpWriteData( hRequest, pszData,
                                     (DWORD)strlen(pszData),
                                     &dwBytesWritten);

    // End the request.
    if (bResults)
        bResults = WinHttpReceiveResponse( hRequest, NULL);

    // Report any errors.
    if (!bResults)
        printf("Error %d has occurred.\n",GetLastError());

    // Close any open handles.
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)

[WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest)