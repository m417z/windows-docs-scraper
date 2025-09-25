# InternetCreateUrlA function

## Description

Creates a URL from its component parts.

## Parameters

### `lpUrlComponents` [in]

Pointer to a
[URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure that contains the components from which to create the URL.

### `dwFlags` [in]

Controls the operation of this function. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| ICU_ESCAPE | Converts all unsafe characters to their corresponding escape sequences in the path string pointed to by the **lpszUrlPath** member and in **lpszExtraInfo** the extra-information string pointed to by the member of the [URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure pointed to by the *lpUrlComponents* parameter.<br><br>The Unicode version of **InternetCreateUrl** will first try to convert using the system code page. If that fails it falls back to UTF-8. |
| ICU_USERNAME | Obsolete — ignored. |

### `lpszUrl` [out]

Pointer to a buffer that receives the URL.

### `lpdwUrlLength` [in, out]

Pointer to a variable that specifies the size of the
URL *lpszUrl* buffer, in **TCHARs**. When the function returns, this parameter receives the size of the URL string, excluding the NULL terminator. If
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER, this parameter receives the number of bytes required to hold the created URL.

## Return value

Returns **TRUE** if the function succeeds, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When specifying scheme in the [URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure passed to *lpUrlComponents*, if *lpszScheme* is not NULL it will be used for the scheme. If *lpszScheme* is NULL, the scheme can be specified using the [INTERNET_SCHEME](https://learn.microsoft.com/windows/desktop/api/wininet/ne-wininet-internet_scheme) enumeration by setting **nScheme** to the required **INTERNET_SCHEME** or **INTERNET_SCHEME_DEFAULT**.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetCreateUrl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Handling Uniform Resource Locators](https://learn.microsoft.com/windows/desktop/WinInet/handling-uniform-resource-locators)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)