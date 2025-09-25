## Description

The **WinHttpQueryDataAvailable** function returns the amount of data, in bytes, available to be read with
[WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata).

## Parameters

### `hRequest` [in]

A valid
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest). [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) must have been called for this handle and have completed before **WinHttpQueryDataAvailable** is called.

### `lpdwNumberOfBytesAvailable` [out]

A pointer to an unsigned long integer variable that receives the number of available bytes. When WinHTTP is used in asynchronous mode, always set this parameter to **NULL** and retrieve data in the callback function; not doing so can cause a memory fault.

## Return value

Returns **TRUE** if the function succeeds, or **FALSE** otherwise. To get extended error data, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_CONNECTION_ERROR** | The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP version 5.1 does not support SSL2 unless the client specifically enables it. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot complete because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_TIMEOUT** | The request has timed out. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function can operate either synchronously or asynchronously. If it returns **FALSE**, it failed and you can call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information. If it returns **TRUE**, use the WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE completion to determine whether this function was successful and the value of the parameters. The WINHTTP_CALLBACK_STATUS_REQUEST_ERROR completion indicates that the operation completed asynchronously, but failed.

**Warning** When WinHTTP is used in asynchronous mode, always set the *lpdwNumberOfBytesAvailable* parameter to **NULL** and retrieve the bytes available in the callback function; otherwise, a memory fault can occur.

This function returns the number of bytes of data that are available to read immediately by a subsequent call to
[WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata). If no data is available and the end of the file has not been reached, one of two things happens. If the session is synchronous, the request waits until data becomes available. If the session is asynchronous, the function returns **TRUE**, and when data becomes available, calls the callback function with WINHTTP_STATUS_CALLBACK_DATA_AVAILABLE and indicates the number of bytes immediately available to read by calling **WinHttpReadData**.

The amount of data that remains is not recalculated until all available data indicated by the call to
**WinHttpQueryDataAvailable** is read.

Use the return value of [WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata) to determine when a response has been completely read.

**Important** Do not use the return value of **WinHttpQueryDataAvailable** to determine whether the end of a response has been reached, because not all servers terminate responses properly, and an improperly terminated response causes **WinHttpQueryDataAvailable** to anticipate more data.

For
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handles created by the
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest) function and sent by
[WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest), a call to
[WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) must be made on the handle before
**WinHttpQueryDataAvailable** can be used.

If a status callback function has been installed with
[WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback), then those of the following notifications that have been set in the *dwNotificationFlags* parameter of **WinHttpSetStatusCallback** indicate progress in checking for available data:

* WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE
* WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED
* WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE

**Note** For more information about Windows XP and Windows 2000, see [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## Examples

The following example shows how to use secure transaction semantics to download a resource from an HTTPS server. The sample code initializes the WinHTTP API, selects a target HTTPS server, and then opens and sends a request for this secure resource.
**WinHttpQueryDataAvailable** is used with the request handle to determine how much data is available for download, then
[WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata) is used to read that data. This process repeats until the entire document has been retrieved and displayed.

> [!IMPORTANT]
> If you want some data as quickly as possible (that is, you're processing and parsing data as you receive it), then you should call **WinHttpQueryDataAvailable** and [WinHttpReadData](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpreaddata). If you're trying to download the entire response as quickly as possible, then call **WinHttpReadData** directly, because **WinHttpReadData** tries to fill your buffer before completing.
>
> Also, the code example below allocates on every loop iteration. For production code, where performance is important, you could instead start with an appropriately-sized buffer (perhaps 1 megabyte), and resize that if necessary. In practice, **WinHttpQueryDataAvailable** returns no more than 8 kilobytes.

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

    // Continue to verify data until there is nothing left.
    if (bResults)
        do
        {

            // Verify available data.
            dwSize = 0;
            if (!WinHttpQueryDataAvailable( hRequest, &dwSize))
                printf( "Error %u in WinHttpQueryDataAvailable.\n",
                        GetLastError());

            // Allocate space for the buffer.
            pszOutBuffer = new char[dwSize+1];
            if (!pszOutBuffer)
            {
                printf("Out of memory\n");
                dwSize=0;
            }
            else
            {
                // Read the Data.
                ZeroMemory(pszOutBuffer, dwSize+1);

                if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer,
                                      dwSize, &dwDownloaded))
                    printf( "Error %u in WinHttpReadData.\n", GetLastError());
                else
                    printf( "%s\n", pszOutBuffer);

                // Free the memory allocated to the buffer.
                delete [] pszOutBuffer;
            }

        } while (dwSize > 0);

    // Report any errors.
    if (!bResults)
        printf( "Error %d has occurred.\n", GetLastError());

    // Close open handles.
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

[WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata)

[WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest)