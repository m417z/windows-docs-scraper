# HttpAddRequestHeadersA function

## Description

Adds one or more HTTP request headers to the HTTP request handle.

## Parameters

### `hRequest` [in]

A handle returned by a call to the
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) function.

### `lpszHeaders` [in]

A pointer to a string variable containing the headers to append to the request. Each header must be terminated by a CR/LF (carriage return/line feed) pair.

### `dwHeadersLength` [in]

The size of
*lpszHeaders*, in **TCHARs**. If this parameter is -1L, the function assumes that
*lpszHeaders* is zero-terminated (ASCIIZ), and the length is computed.

### `dwModifiers` [in]

A set of modifiers that control the semantics of this function. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **HTTP_ADDREQ_FLAG_ADD** | Adds the header if it does not exist. Used with **HTTP_ADDREQ_FLAG_REPLACE**. |
| **HTTP_ADDREQ_FLAG_ADD_IF_NEW** | Adds the header only if it does not already exist; otherwise, an error is returned. |
| **HTTP_ADDREQ_FLAG_COALESCE** | Coalesces headers of the same name. |
| **HTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA** | Coalesces headers of the same name. For example, adding "Accept: text/*" followed by "Accept: audio/*" with this flag results in the formation of the single header "Accept: text/*, audio/*". This causes the first header found to be coalesced. It is up to the calling application to ensure a cohesive scheme with respect to coalesced/separate headers. |
| **HTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON** | Coalesces headers of the same name using a semicolon. |
| **HTTP_ADDREQ_FLAG_REPLACE** | Replaces or removes a header. If the header value is empty and the header is found, it is removed. If not empty, the header value is replaced. |

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**HttpAddRequestHeaders** appends additional, free-format headers to the HTTP request handle and is intended for use by sophisticated clients that need detailed control over the exact request sent to the HTTP server.

Note that for basic
**HttpAddRequestHeaders**, the application can pass in multiple headers in a single buffer. If the application is trying to remove or replace a header, only one header can be supplied in
*lpszHeaders*.

**Note** The **HttpAddRequestHeadersA** function represents headers as ISO-8859-1 characters not ANSI characters. The **HttpAddRequestHeadersW** function represents headers as ISO-8859-1 characters converted to UTF-16LE characters. As a result, it is never safe to use the **HttpAddRequestHeadersW** function when the headers to be added can contain non-ASCII characters.
Instead, an application can use the [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) and [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte) functions with a *Codepage* parameter set to 28591 to map between ANSI characters and UTF-16LE characters.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines HttpAddRequestHeaders as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/http-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)