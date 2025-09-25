# HttpSendRequestW function

## Description

Sends the specified request to the HTTP server, allowing callers to send extra data beyond what is normally passed to [HttpSendRequestEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequestexa).

## Parameters

### `hRequest` [in]

A handle returned by
a call to the [HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) function.

### `lpszHeaders` [in]

A pointer to a **null**-terminated string that contains the additional headers to be appended to the request. This parameter can be **NULL** if there are no additional headers to be appended.

### `dwHeadersLength` [in]

The size of the additional headers, in **TCHARs**. If this parameter is -1L and
*lpszHeaders* is not **NULL**, the function assumes that
*lpszHeaders* is zero-terminated (ASCIIZ), and the length is calculated. See Remarks for specifics.

### `lpOptional` [in]

A pointer to a buffer containing any optional data to be sent immediately after the request headers. This parameter is generally used for POST and PUT operations. The optional data can be the resource or information being posted to the server. This parameter can be **NULL** if there is no optional data to send.

### `dwOptionalLength` [in]

The size of the optional data, in bytes. This parameter can be zero if there is no optional data to send.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**HttpSendRequest** sends the specified request to the HTTP server and allows the client to specify additional headers to send along with the request.

The function also lets the client specify optional data to send to the HTTP server immediately following the request headers. This feature is generally used for "write" operations such as PUT and POST.

After the request is sent, the status code and response headers from the HTTP server are read. These headers are maintained internally and are available to client applications through the
[HttpQueryInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpqueryinfoa) function.

An application can use the same HTTP request handle in multiple calls to
**HttpSendRequest**, but the application must read all data returned from the previous call before calling the function again.

In offline mode,
**HttpSendRequest** returns **ERROR_FILE_NOT_FOUND** if the resource is not found in the Internet cache.

There are two versions of
**HttpSendRequest**—**HttpSendRequestA** (used with ANSI builds) and **HttpSendRequestW** (used with Unicode builds). If
**dwHeadersLength** is -1L and
*lpszHeaders* is not **NULL**, the following will happen: If **HttpSendRequestA** is called, the function assumes that
*lpszHeaders* is zero-terminated (ASCIIZ), and the length is calculated. If **HttpSendRequestW** is called, the function fails with **ERROR_INVALID_PARAMETER**.

**Note** The **HttpSendRequestA** function represents headers as ISO-8859-1 characters not ANSI characters. The **HttpSendRequestW** function represents headers as ISO-8859-1 characters converted to UTF-16LE characters. As a result, it is never safe to use the **HttpSendRequestW** function when the headers to be added can contain non-ASCII characters.
Instead, an application can use the [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) and [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte) functions with a *Codepage* parameter set to 28591 to map between ANSI characters and UTF-16LE characters.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines HttpSendRequest as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/http-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)