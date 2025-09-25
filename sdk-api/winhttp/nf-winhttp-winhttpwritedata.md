# WinHttpWriteData function

## Description

The **WinHttpWriteData** function writes request data to an HTTP server.

## Parameters

### `hRequest` [in]

Valid
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest). Wait until [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest) has completed before calling this function.

### `lpBuffer` [in]

Pointer to a buffer that contains the data to be sent to the server. Be sure that this buffer remains valid until after **WinHttpWriteData** completes.

### `dwNumberOfBytesToWrite` [in]

Unsigned long integer value that contains the number of bytes to be written to the file.

### `lpdwNumberOfBytesWritten` [out]

Pointer to an unsigned long integer variable that receives the number of bytes written to the buffer. The
**WinHttpWriteData** function sets this value to zero before doing any work or error checking. When using WinHTTP asynchronously, this parameter must be set to **NULL** and retrieve the information in the callback function. Not doing so can cause a memory fault.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are:

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_CONNECTION_ERROR** | The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP version 5.1 does not support SSL2 unless the client specifically enables it. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_TIMEOUT** | The request has timed out. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function can operate either synchronously or asynchronously. If this function returns **FALSE**, you can call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information. If this function returns **TRUE**, use the WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE completion to determine whether this function was successful and the value of the parameters. The WINHTTP_CALLBACK_STATUS_REQUEST_ERROR completion indicates that the operation completed asynchronously, but failed.

**Warning** When using WinHTTP asynchronously, always set the *lpdwNumberOfBytesWritten* parameter to **NULL** and retrieve the bytes written in the callback function; otherwise, a memory fault can occur.

When the application is sending data, it can call
[WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) to end the data transfer. If
[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle) is called, then the data transfer is aborted.

If a status callback function has been installed with
[WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback), then those of the following notifications that have been set in the *dwNotificationFlags* parameter of **WinHttpSetStatusCallback** indicate progress in sending data to the server:

* WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE
* WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED
* WINHTTP_CALLBACK_STATUS_DATA_WRITTEN
* WINHTTP_CALLBACK_STATUS_SENDING_REQUEST
* WINHTTP_CALLBACK_STATUS_REQUEST_SENT
* WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE

Two issues can arise when attempting to POST (or PUT) data to proxies or servers that challenge using NTLM or Negotiate authentication.
First, these proxies or servers may send 401/407 challenges and close the connection before all the data can be POST'ed, in which case not only does **WinHttpWriteData** fail, but also WinHTTP cannot handle the authentication challenges. NTLM and Negotiate require that all authentication handshakes be exchanged on the same socket connection, so authentication fails if the connection is broken prematurely.

Secondly, NTLM and Negotiate may require multiple handshakes to complete authentication, which requires data to be re-POST'ed for each authentication legs. This can be very inefficient for large data uploads.

To work around these two issues, one solution is to send an idempotent warm-up request such as HEAD to the authenticating v-dir first, handle the authentication challenges associated with this request, and only then POST data. As long as the same socket is re-used to handle the POST'ing, no further authentication challenges should be encountered and all data can be uploaded at once. Since an authenticated socket can only be reused for subsequent requests within the same session, the POST should go out in the same socket as long as the socket is not pooled with concurrent requests competing for it.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHTTP start page.

#### Examples

This example shows code that writes data to an HTTP server. The server name supplied in the example, www.wingtiptoys.com, is fictitious and must be replaced with the name of a server for which you have write access.

```cpp
    PCSTR pszData = "WinHttpWriteData Example";
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

[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)