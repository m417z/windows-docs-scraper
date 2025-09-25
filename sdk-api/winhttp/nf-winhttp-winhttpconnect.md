# WinHttpConnect function

## Description

The **WinHttpConnect** function specifies the initial target server of an HTTP request and returns an [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) connection handle to an HTTP session for that initial target.

## Parameters

### `hSession` [in]

Valid
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) WinHTTP session handle returned by a previous call to
[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen).

### `pswzServerName` [in]

Pointer to a **null**-terminated string that contains the host name of an HTTP server. Alternately, the string can contain the IP address of the site as a string, for example, 10.0.1.45.
Note that WinHttp does not accept international host names without converting them first to [Punycode](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/). For more information, see [Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/win32/intl/handling-internationalized-domain-names--idns).

### `nServerPort` [in]

Unsigned integer that specifies the TCP/IP port on the server to which a connection is made. This parameter can be any valid TCP/IP port number, or one of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_DEFAULT_HTTP_PORT** | Uses the default port for HTTP servers (port 80). |
| **INTERNET_DEFAULT_HTTPS_PORT** | Uses the default port for HTTPS servers (port 443). Selecting this port does not automatically establish a secure connection. You must still specify the use of secure transaction semantics by using the [WINHTTP_FLAG_SECURE](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest) flag with [WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest). |
| **INTERNET_DEFAULT_PORT** | Uses port 80 for HTTP and port 443 for Secure Hypertext Transfer Protocol (HTTPS). |

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

Returns a valid connection handle to the HTTP session if the connection is successful, or **NULL** otherwise. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Codes | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_INVALID_URL** | The URL is invalid. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_UNRECOGNIZED_SCHEME** | The URL scheme could not be recognized, or is not supported. |
| **ERROR_WINHTTP_SHUTDOWN** | The WinHTTP function support is being shut down or unloaded. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

After the calling application has finished using the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
**WinHttpConnect**, it must be closed using the
[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle) function.

**WinHttpConnect** specifies the target HTTP server, however a response can come from another server if the request was redirected. You can determine the URL of the server sending the response by calling
[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) with the WINHTTP_OPTION_URL flag.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

#### Examples

The following example shows how to use secure transaction semantics to download a resource from an HTTPS server. The sample code initializes the Microsoft Windows HTTP Services (WinHTTP) application programming interface (API), selects a target HTTPS server, then opens and sends a request for this secure resource.
[WinHttpQueryDataAvailable](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpquerydataavailable) is used with the request handle to determine how much data is available for download, then
[WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata) is used to read that data. This process repeats until the entire document has been retrieved and displayed.

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
        do
        {
            // Check for available data.
            dwSize = 0;
            if (!WinHttpQueryDataAvailable( hRequest, &dwSize))
                printf("Error %u in WinHttpQueryDataAvailable.\n", GetLastError());

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
        printf("Error %d has occurred.\n", GetLastError());

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