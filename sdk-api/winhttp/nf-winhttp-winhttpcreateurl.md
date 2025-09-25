# WinHttpCreateUrl function

## Description

The **WinHttpCreateUrl** function creates a URL from component parts such as the host name and path.

## Parameters

### `lpUrlComponents` [in]

Pointer to a
[URL_COMPONENTS](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-url_components) structure that contains the components from which to create the URL.

### `dwFlags` [in]

Flags that control the operation of this function. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ICU_ESCAPE** | Converts all unsafe characters to their corresponding escape sequences in the path string pointed to by the **lpszUrlPath** member and in **lpszExtraInfo** the extra-information string pointed to by the member of the [URL_COMPONENTS](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-url_components) structure pointed to by the *lpUrlComponents* parameter. |
| **ICU_REJECT_USERPWD** | Rejects URLs as input that contains either a username, or a password, or both. If the function fails because of an invalid URL, subsequent calls to GetLastError will return ERROR_WINHTTP_INVALID_URL. |

### `pwszUrl` [out]

Pointer to a character buffer that receives the URL as a wide character (Unicode) string.

### `pdwUrlLength` [in, out]

Pointer to a variable of type unsigned long integer that receives the length of the
*pwszUrl* buffer in wide (Unicode) characters. When the function returns, this parameter receives the length of the URL string wide in characters, minus 1 for the terminating character. If
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER, this parameter receives the number of wide characters required to hold the created URL.

## Return value

Returns **TRUE** if the function succeeds, or **FALSE** otherwise. To get extended error data, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode, that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen), this function operates synchronously. The return value indicates success or failure. To get extended error data, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

#### Examples

The following example shows how to decompile, or crack, a URL into its subcomponents, update a component, then reconstruct the URL.

```cpp

    URL_COMPONENTS urlComp;
    LPCWSTR pwszUrl1 =
       L"http://search.msn.com/results.asp?RS=CHECKED&FORM=MSNH&v=1&q=wininet";
    DWORD dwUrlLen = 0;

    // Initialize the URL_COMPONENTS structure.
    ZeroMemory(&urlComp, sizeof(urlComp));
    urlComp.dwStructSize = sizeof(urlComp);

    // Set required component lengths to non-zero,
    // so that they are cracked.
    urlComp.dwSchemeLength    = (DWORD)-1;
    urlComp.dwHostNameLength  = (DWORD)-1;
    urlComp.dwUrlPathLength   = (DWORD)-1;
    urlComp.dwExtraInfoLength = (DWORD)-1;

    // Crack the URL.
    if (!WinHttpCrackUrl( pwszUrl1, (DWORD)wcslen(pwszUrl1), 0, &urlComp))
    {
        printf("Error %u in WinHttpCrackUrl.\n", GetLastError());
    }
    else
    {
        // Change the search data. New data is the same length.
        urlComp.lpszExtraInfo = L"?RS=CHECKED&FORM=MSNH&v=1&q=winhttp";

        // Obtain the size of the new URL and allocate memory.
        WinHttpCreateUrl( &urlComp, 0, NULL, &dwUrlLen);
        LPWSTR pwszUrl2 = new WCHAR[dwUrlLen];

        // Create a new URL.
        if(!WinHttpCreateUrl( &urlComp, 0, pwszUrl2, &dwUrlLen))
        {
            printf( "Error %u in WinHttpCreateUrl.\n", GetLastError());
        }
        else
        {
            // Show both URLs.
            printf( "Old URL:  %S\nNew URL:  %S\n", pwszUrl1, pwszUrl2);
        }

        // Free allocated memory.
        delete [] pwszUrl2;
    }

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[Handling Uniform Resource Locators](https://learn.microsoft.com/windows/desktop/WinHttp/uniform-resource-locators--urls--in-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCrackUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcrackurl)