# WinHttpAddRequestHeaders function

## Description

The **WinHttpAddRequestHeaders** function adds one or more HTTP request headers to the HTTP request handle.

## Parameters

### `hRequest` [in]

A [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by a call to the
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest) function.

### `lpszHeaders` [in]

A pointer to a string variable that contains the headers to append to the request. Each header except the last must be terminated by a carriage return/line feed (CR/LF).

### `dwHeadersLength` [in]

An unsigned long integer value that contains the length, in characters, of
*pwszHeaders*. If this parameter is -1L, the function assumes that
*pwszHeaders* is zero-terminated (ASCIIZ), and the length is computed.

### `dwModifiers` [in]

An unsigned long integer value that contains the flags used to modify the semantics of this function. Can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **WINHTTP_ADDREQ_FLAG_ADD** | Adds the header if it does not exist. Used with **WINHTTP_ADDREQ_FLAG_REPLACE**. |
| **WINHTTP_ADDREQ_FLAG_ADD_IF_NEW** | Adds the header only if it does not already exist; otherwise, an error is returned. |
| **WINHTTP_ADDREQ_FLAG_COALESCE** | Merges headers of the same name. |
| **WINHTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA** | Merges headers of the same name using a comma. For example, adding "Accept: text/*" followed by "Accept: audio/*" with this flag results in a single header "Accept: text/*, audio/*". This causes the first header found to be merged. The calling application must to ensure a cohesive scheme with respect to merged and separate headers. |
| **WINHTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON** | Merges headers of the same name using a semicolon. |
| **WINHTTP_ADDREQ_FLAG_REPLACE** | Replaces or removes a header. If the header value is empty and the header is found, it is removed. If the value is not empty, it is replaced. |

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be performed because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. |

## Remarks

Headers are transferred across redirects. This can be a security issue. To avoid having headers transferred when a redirect occurs, use the [WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback) callback to correct the specific headers when a redirect occurs.

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The
**WinHttpAddRequestHeaders** function appends additional free-format headers to the HTTP request handle and is intended for use by sophisticated clients that require detailed control over the exact request sent to the HTTP server.

The name and value of request headers added with this function are validated. Headers must be well formed. For more information about valid HTTP headers, see
[RFC 2616](https://www.ietf.org/rfc/rfc2616.txt). If an invalid header is used, this function fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
[ERROR_INVALID_PARAMETER](https://learn.microsoft.com/windows/desktop/WinHttp/error-messages). The invalid header is not added.

If you are sending a Date: request header, you can use the [WinHttpTimeFromSystemTime](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttptimefromsystemtime) function to create structure for the header.

For basic
**WinHttpAddRequestHeaders**, the application can pass in multiple headers in a single buffer.

An application can also use
[WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest) to add additional headers to the HTTP request handle before sending a request.

**Note** For more information, see [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

#### Examples

The following code example includes an If-Modified-Since header in a request. The response header is interpreted to determine whether the target document has been updated.

```cpp

  DWORD dwSize = sizeof(DWORD);
  DWORD dwStatusCode = 0;
  BOOL  bResults = FALSE;
  HINTERNET hSession = NULL,
        hConnect = NULL,
        hRequest = NULL;

  // Use WinHttpOpen to obtain a session handle.
  hSession = WinHttpOpen( L"A WinHTTP Example Program/1.0",
                          WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                          WINHTTP_NO_PROXY_NAME,
                          WINHTTP_NO_PROXY_BYPASS,
                          0 );

  // Specify an HTTP server.
  if( hSession )
    hConnect = WinHttpConnect( hSession,
                               L"www.microsoft.com",
                               INTERNET_DEFAULT_HTTP_PORT,
                               0 );

  // Create an HTTP Request handle.
  if( hConnect )
    hRequest = WinHttpOpenRequest( hConnect,
                                   L"GET",
                                   NULL,
                                   NULL,
                                   WINHTTP_NO_REFERER,
                                   WINHTTP_DEFAULT_ACCEPT_TYPES,
                                   0 );

  // Add a request header.
  if( hRequest )
    bResults = WinHttpAddRequestHeaders( hRequest,
                 L"If-Modified-Since: Mon, 20 Nov 2000 20:00:00 GMT",
                                         (ULONG)-1L,
                                         WINHTTP_ADDREQ_FLAG_ADD );

  // Send a Request.
  if( bResults )
    bResults = WinHttpSendRequest( hRequest,
                                   WINHTTP_NO_ADDITIONAL_HEADERS,
                                   0,
                                   WINHTTP_NO_REQUEST_DATA,
                                   0,
                                   0,
                                   0 );

  // End the request.
  if( bResults )
    bResults = WinHttpReceiveResponse( hRequest, NULL);

  // Use WinHttpQueryHeaders to obtain the header buffer.
  if( bResults )
    bResults = WinHttpQueryHeaders( hRequest,
                WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                                    NULL,
                                    &dwStatusCode,
                                    &dwSize,
                                    WINHTTP_NO_HEADER_INDEX );

  // Based on the status code, determine whether
  // the document was recently updated.
  if( bResults )
  {
    if( dwStatusCode == 304 )
      printf( "Document has not been updated.\n" );
    else if( dwStatusCode == 200 )
      printf( "Document has been updated.\n" );
    else
      printf( "Status code = %u.\n",dwStatusCode );
  }

  // Report any errors.
  if( !bResults )
    printf( "Error %d has occurred.\n", GetLastError( ) );

  // Close open handles.
  if( hRequest ) WinHttpCloseHandle( hRequest );
  if( hConnect ) WinHttpCloseHandle( hConnect );
  if( hSession ) WinHttpCloseHandle( hSession );

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)

[WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest)