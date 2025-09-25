# WinHttpReadData function

## Description

The **WinHttpReadData** function reads data from a handle opened by the
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest) function.

Also see [WinHttpReadDataEx](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpreaddataex).

## Parameters

### `hRequest` [in]

Valid
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned from a previous call to
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest). [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) or [WinHttpQueryDataAvailable](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpquerydataavailable) must have been called for this handle and must have completed before **WinHttpReadData** is called. Although calling **WinHttpReadData** immediately after completion of **WinHttpReceiveResponse** avoids the expense of a buffer copy, doing so requires that the application use a fixed-length buffer for reading.

### `lpBuffer` [out]

Pointer to a buffer that receives the data read. Make sure that this buffer remains valid until **WinHttpReadData** has completed.

### `dwNumberOfBytesToRead` [in]

Unsigned long integer value that contains the number of bytes to read.

### `lpdwNumberOfBytesRead` [out]

Pointer to an unsigned long integer variable that receives the number of bytes read.
**WinHttpReadData** sets this value to zero before doing any work or error checking. When using WinHTTP asynchronously, always set this parameter to **NULL** and retrieve the information in the callback function; not doing so can cause a memory fault.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following table identifies the error codes that are returned.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_CONNECTION_ERROR** | The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP 5.1 does not support SSL2 unless the client specifically enables it. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW** | Returned when an incoming response exceeds an internal WinHTTP size limit. |
| **ERROR_WINHTTP_TIMEOUT** | The request has timed out. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Starting in Windows Vista and Windows Server 2008, WinHttp enables applications to perform chunked transfer encoding on data sent to the server. When the Transfer-Encoding header is present on the WinHttp response, **WinHttpReadData** strips the chunking information before giving the data to the application.

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function can operate either synchronously or asynchronously. If this function returns **FALSE**, this function failed and you can call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information. If this function returns **TRUE**, use the WINHTTP_CALLBACK_STATUS_READ_COMPLETE completion to determine whether this function was successful and the value of the parameters. The WINHTTP_CALLBACK_STATUS_REQUEST_ERROR completion indicates that the operation completed asynchronously, but failed.

**Warning** When WinHTTP is used in asynchronous mode, always set the *lpdwNumberOfBytesRead* parameter to **NULL** and retrieve the bytes read in the callback function; otherwise, a memory fault can occur.

When the read buffer is very small,
**WinHttpReadData** might complete synchronously. If the WINHTTP_CALLBACK_STATUS_READ_COMPLETE completion triggers another call to
**WinHttpReadData**, the situation can result in a stack overflow. In general, it is best to use a read buffer that is comparable in size, or larger than the internal read buffer used by WinHTTP, which is 8 KB.

If you are using **WinHttpReadData** synchronously, and the return value is **TRUE** and the number of bytes read is zero, the transfer has been completed and there are no more bytes to read on the handle. This is analogous to reaching end-of-file in a local file. If you are using the function asynchronously, the [WINHTTP_CALLBACK_STATUS_READ_COMPLETE](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback) callback is called with the *dwStatusInformationLength* parameter set to zero when the end of a response is found.

**WinHttpReadData** tries to fill the buffer pointed to by
*lpBuffer* until there is no more data available from the response. If sufficient data has not arrived from the server, the buffer is not filled.

For
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handles created by the
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest) function and sent by
[WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest), a call to
[WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) must be made on the handle before
**WinHttpReadData** can be used.

Single byte characters retrieved with
**WinHttpReadData** are not converted to multi-byte characters.

When the read buffer is very small, **WinHttpReadData** may complete synchronously, and if the **WINHTTP_CALLBACK_STATUS_READ_COMPLETE** completion then triggers another call to **WinHttpReadData**, a stack overflow can result. It is best to use a read buffer that is 8 Kilobytes or larger in size.

If sufficient data has not arrived from the server, **WinHttpReadData** does not entirely fill the buffer pointed to by *lpBuffer*. The buffer must be large enough at least to hold the HTTP headers on the first read, and when reading HTML encoded directory entries, it must be large enough to hold at least one complete entry.

If a status callback function has been installed by using [WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback), then those of the following notifications that have been set in the *dwNotificationFlags* parameter of **WinHttpSetStatusCallback** indicate progress in checking for available data:

* WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE
* WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED
* WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED
* WINHTTP_CALLBACK_STATUS_READ_COMPLETE

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/win32/winhttp/winhttp-start-page#run-time-requirements) section of the WinHttp start page.

#### Examples

The following example shows how to use secure transaction semantics to download a resource from an Secure Hypertext Transfer Protocol (HTTPS) server. The sample code initializes the WinHTTP application programming interface (API), selects a target HTTPS server, then opens and sends a request for this secure resource.
[WinHttpQueryDataAvailable](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpquerydataavailable) is used with the request handle to determine how much data is available for download, then
**WinHttpReadData** is used to read that data. This process repeats until the entire document has been retrieved and displayed.

```cpp
    DWORD dwSize = 0;
    DWORD dwDownloaded = 0;
    LPSTR pszOutBuffer;
    BOOL  bResults = FALSE;
    HINTERNET  hSession = NULL,
               hConnect = NULL,
               hRequest = NULL;

    // Use WinHttpOpen to obtain a session handle.
    hSession = WinHttpOpen( L"WinHTTP Example/1.0",
                            WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                            WINHTTP_NO_PROXY_NAME,
                            WINHTTP_NO_PROXY_BYPASS, 0);

    // Specify an HTTP server.
    if (hSession)
        hConnect = WinHttpConnect( hSession, L"www.microsoft.com",
                                   INTERNET_DEFAULT_HTTPS_PORT, 0);

    // Create an HTTP request handle.
    if (hConnect)
        hRequest = WinHttpOpenRequest( hConnect, L"GET", NULL,
                                       NULL, WINHTTP_NO_REFERER,
                                       WINHTTP_DEFAULT_ACCEPT_TYPES,
                                       WINHTTP_FLAG_SECURE);

    // Send a request.
    if (hRequest)
        bResults = WinHttpSendRequest( hRequest,
                                       WINHTTP_NO_ADDITIONAL_HEADERS,
                                       0, WINHTTP_NO_REQUEST_DATA, 0,
                                       0, 0);

    // End the request.
    if (bResults)
        bResults = WinHttpReceiveResponse( hRequest, NULL);

    // Keep checking for data until there is nothing left.
    if (bResults)
    {
        do
        {
            // Check for available data.
            dwSize = 0;
            if (!WinHttpQueryDataAvailable( hRequest, &dwSize))
            {
                printf( "Error %u in WinHttpQueryDataAvailable.\n",
                        GetLastError());
                break;
            }

            // No more available data.
            if (!dwSize)
                break;

            // Allocate space for the buffer.
            pszOutBuffer = new char[dwSize+1];
            if (!pszOutBuffer)
            {
                printf("Out of memory\n");
                break;
            }

            // Read the Data.
            ZeroMemory(pszOutBuffer, dwSize+1);

            if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer,
                                  dwSize, &dwDownloaded))
            {
                printf( "Error %u in WinHttpReadData.\n", GetLastError());
            }
            else
            {
                printf("%s", pszOutBuffer);
            }

            // Free the memory allocated to the buffer.
            delete [] pszOutBuffer;

            // This condition should never be reached since WinHttpQueryDataAvailable
            // reported that there are bits to read.
            if (!dwDownloaded)
                break;

        } while (dwSize > 0);
    }
    else
    {
        // Report any errors.
        printf( "Error %d has occurred.\n", GetLastError() );
    }

    // Close any open handles.
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)

[WinHttpQueryDataAvailable](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpquerydataavailable)

[WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest)

[WinHttpWriteData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwritedata)