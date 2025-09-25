## Description

The **WinHttpQueryHeaders** function retrieves header information associated with an HTTP request.

Also see [WinHttpQueryHeadersEx](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpqueryheadersex), which offers a way to retrieve parsed header name and value strings.

## Parameters

### `hRequest` [in]

[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) request handle returned by
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest).
WinHttpReceiveResponse must have been called for this handle and have completed before **WinHttpQueryHeaders** is called.

### `dwInfoLevel` [in]

Value of type **DWORD** that specifies a combination of attribute and modifier flags listed on the
[Query Info Flags](https://learn.microsoft.com/windows/desktop/WinHttp/query-info-flags) page. These attribute and modifier flags indicate that the information is being requested and how it is to be formatted.

### `pwszName` [in, optional]

Pointer to a string that contains the header name. If the flag in
*dwInfoLevel* is not
**WINHTTP_QUERY_CUSTOM**, set this parameter to WINHTTP_HEADER_NAME_BY_INDEX.

### `lpBuffer` [out]

Pointer to the buffer that receives the information. Setting this parameter to WINHTTP_NO_OUTPUT_BUFFER causes this function to return **FALSE**. Calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) then returns
**ERROR_INSUFFICIENT_BUFFER** and
*lpdwBufferLength* contains the number of bytes required to hold the requested information.

### `lpdwBufferLength` [in, out]

Pointer to a value of type **DWORD** that specifies the length of the data buffer, in bytes. When the function returns, this parameter contains the pointer to a value that specifies the length of the information written to the buffer. When the function returns strings, the following rules apply.

* If the function succeeds,
  *lpdwBufferLength* specifies the length of the string, in bytes, minus 2 for the terminating null.
* If the function fails and
  **ERROR_INSUFFICIENT_BUFFER** is returned,
  *lpdwBufferLength* specifies the number of bytes that the application must allocate to receive the string.

### `lpdwIndex` [in, out]

Pointer to a zero-based header index used to enumerate multiple headers with the same name. When calling the function, this parameter is the index of the specified header to return. When the function returns, this parameter is the index of the next header. If the next index cannot be found,
**ERROR_WINHTTP_HEADER_NOT_FOUND** is returned. Set this parameter to WINHTTP_NO_HEADER_INDEX to specify that only the first occurrence of a header should be returned.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_HEADER_NOT_FOUND** | The requested header could not be located. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

By default
**WinHttpQueryHeaders** returns a string. However, you can request data in the form of a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure or **DWORD** by including the appropriate modifier flag in
*dwInfoLevel*. The following table shows the possible data types that
**WinHttpQueryHeaders** can return along with the modifier flag that you use to select that data type.

| Data type | Modifier flag |
| --- | --- |
| **LPCWSTR** | Default. No modifier flag required. |
| **SYSTEMTIME** | **WINHTTP_QUERY_FLAG_SYSTEMTIME** |
| **DWORD** | **WINHTTP_QUERY_FLAG_NUMBER** |

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

#### Examples

The following example shows how to obtain an
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle, open an HTTP session, create and send a request header, and examine the returned response header.

```cpp
    DWORD dwSize = 0;
    LPVOID lpOutBuffer = NULL;
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
        hConnect = WinHttpConnect( hSession, L"www.microsoft.com",
                                   INTERNET_DEFAULT_HTTP_PORT, 0);

    // Create an HTTP request handle.
    if (hConnect)
        hRequest = WinHttpOpenRequest( hConnect, L"GET", NULL,
                                       NULL, WINHTTP_NO_REFERER,
                                       WINHTTP_DEFAULT_ACCEPT_TYPES,
                                       0);

    // Send a request.
    if (hRequest)
        bResults = WinHttpSendRequest( hRequest,
                                       WINHTTP_NO_ADDITIONAL_HEADERS,
                                       0, WINHTTP_NO_REQUEST_DATA, 0,
                                       0, 0);

    // End the request.
    if (bResults)
        bResults = WinHttpReceiveResponse( hRequest, NULL);

    // First, use WinHttpQueryHeaders to obtain the size of the buffer.
    if (bResults)
    {
        WinHttpQueryHeaders( hRequest, WINHTTP_QUERY_RAW_HEADERS_CRLF,
                             WINHTTP_HEADER_NAME_BY_INDEX, NULL,
                             &dwSize, WINHTTP_NO_HEADER_INDEX);

        // Allocate memory for the buffer.
        if( GetLastError( ) == ERROR_INSUFFICIENT_BUFFER )
        {
            lpOutBuffer = new WCHAR[dwSize/sizeof(WCHAR)];

            // Now, use WinHttpQueryHeaders to retrieve the header.
            bResults = WinHttpQueryHeaders( hRequest,
                                       WINHTTP_QUERY_RAW_HEADERS_CRLF,
                                       WINHTTP_HEADER_NAME_BY_INDEX,
                                       lpOutBuffer, &dwSize,
                                       WINHTTP_NO_HEADER_INDEX);
        }
    }

    // Print the header contents.
    if (bResults)
        printf("Header contents: \n%S",lpOutBuffer);

    // Free the allocated memory.
    delete [] lpOutBuffer;

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

Microsoft Windows HTTP Services (WinHTTP)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)