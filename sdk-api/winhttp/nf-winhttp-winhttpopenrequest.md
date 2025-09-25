# WinHttpOpenRequest function

## Description

The **WinHttpOpenRequest** function creates an HTTP request handle.

## Parameters

### `hConnect` [in]

[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) connection handle to an HTTP session returned by
[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect).

### `pwszVerb` [in]

Pointer to a string that contains the [HTTP verb](https://learn.microsoft.com/windows/desktop/WinHttp/glossary) to use in the request. If this parameter is **NULL**, the function uses GET as the *HTTP verb*. **Note** This string should be all uppercase. Many servers treat HTTP verbs as case-sensitive, and the Internet Engineering Task Force (IETF) Requests for Comments (RFCs) spell these verbs using uppercase characters only.

### `pwszObjectName` [in]

Pointer to a **null**-terminated string that contains the name of the target resource of the specified HTTP verb. This is generally a file name, an executable module, or a search specifier.

### `pwszVersion` [in]

Pointer to a string that contains the HTTP version. If this parameter is **NULL**, the function uses HTTP/1.1.

### `pwszReferrer` [in]

Pointer to a string that specifies the URL of the document from which the URL in the request
*pwszObjectName* was obtained. If this parameter is set to **WINHTTP_NO_REFERER**, no referring document is specified.

### `ppwszAcceptTypes` [in]

Pointer to a **null**-terminated array of string pointers that specifies media types accepted by the client. If this parameter is set to **WINHTTP_DEFAULT_ACCEPT_TYPES**, no types are accepted by the client. Typically, servers handle a lack of accepted types as indication that the client accepts only documents of type "text/*"; that is, only text documents—no pictures or other binary files. For a list of valid media types, see Media Types defined by IANA at http://www.iana.org/assignments/media-types/.

### `dwFlags` [in]

Unsigned long integer value that contains the Internet flag values. This can be one or more of the following values:

| Value | Meaning |
| --- | --- |
| **WINHTTP_FLAG_BYPASS_PROXY_CACHE** | This flag provides the same behavior as **WINHTTP_FLAG_REFRESH**. |
| **WINHTTP_FLAG_ESCAPE_DISABLE** | Unsafe characters in the URL passed in for *pwszObjectName* are not converted to escape sequences. |
| **WINHTTP_FLAG_ESCAPE_DISABLE_QUERY** | Unsafe characters in the query component of the URL passed in for *pwszObjectName* are not converted to escape sequences. |
| **WINHTTP_FLAG_ESCAPE_PERCENT** | The string passed in for *pwszObjectName* is converted from an **LPCWSTR** to an **LPSTR**. All unsafe characters are converted to an escape sequence including the percent symbol. By default, all unsafe characters except the percent symbol are converted to an escape sequence. |
| **WINHTTP_FLAG_NULL_CODEPAGE** | The string passed in for *pwszObjectName* is assumed to consist of valid ANSI characters represented by **WCHAR**. No check are done for unsafe characters.<br><br>**Windows 7:** This option is obsolete. |
| **WINHTTP_FLAG_REFRESH** | Indicates that the request should be forwarded to the originating server rather than sending a cached version of a resource from a proxy server. When this flag is used, a "Pragma: no-cache" header is added to the request handle. When creating an HTTP/1.1 request header, a "Cache-Control: no-cache" is also added. |
| **WINHTTP_FLAG_SECURE** | Uses secure transaction semantics. This translates to using Secure Sockets Layer (SSL)/Transport Layer Security (TLS). |

## Return value

Returns a valid HTTP request handle if successful, or **NULL** if not. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_INVALID_URL** | The URL is invalid. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_UNRECOGNIZED_SCHEME** | The URL specified a scheme other than "http:" or "https:". |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The
**WinHttpOpenRequest** function creates a new HTTP request handle and stores the specified parameters in that handle. An HTTP request handle holds a request to send to an HTTP server and contains all [RFC822](https://www.ietf.org/rfc/rfc0822.txt)/MIME/HTTP headers to be sent as part of the request.

If
*pwszVerb* is set to "HEAD", the Content-Length header is ignored.

If a status callback function has been installed with
[WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback), then a **WINHTTP_CALLBACK_STATUS_HANDLE_CREATED** notification indicates that
**WinHttpOpenRequest** has created a request handle.

After the calling application finishes using the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
**WinHttpOpenRequest**, it must be closed using the
[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle) function.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

#### Examples

This example shows how to obtain an
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

    // PLACE ADDITIONAL CODE HERE.

    // Report any errors.
    if (!bResults)
        printf( "Error %d has occurred.\n", GetLastError());

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