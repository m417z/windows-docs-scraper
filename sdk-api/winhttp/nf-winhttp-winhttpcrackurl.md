# WinHttpCrackUrl function

## Description

The **WinHttpCrackUrl** function separates a URL into its component parts such as host name and path.

## Parameters

### `pwszUrl` [in]

Pointer to a string that contains the canonical URL to separate. **WinHttpCrackUrl** does not check this URL for validity or correct format before attempting to crack it.

### `dwUrlLength` [in]

The length of the
*pwszUrl* string, in characters. If
*dwUrlLength* is set to zero,
**WinHttpCrackUrl** assumes that the
*pwszUrl* string is **null** terminated and determines the length of the
*pwszUrl* string based on that assumption.

### `dwFlags` [in]

The flags that control the operation. This parameter can be a combination of one or more of the following flags (values can be bitwise OR'd together). Or, the parameter can be 0, which performs no special operations.

| Value | Meaning |
| --- | --- |
| **ICU_DECODE** | Converts characters that are "escape encoded" (%xx) to their non-escaped form. This does not decode other encodings, such as UTF-8. This feature can be used only if the user provides buffers in the [URL_COMPONENTS](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-url_components) structure to copy the components into. |
| **ICU_ESCAPE** | Escapes certain characters to their escape sequences (%xx). Characters to be escaped are non-ASCII characters or those ASCII characters that must be escaped to be represented in an HTTP request. This feature can be used only if the user provides buffers in the [URL_COMPONENTS](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-url_components) structure to copy the components into. |
| **ICU_REJECT_USERPWD** | Rejects URLs as input that contain embedded credentials (either a username, a password, or both). If the function fails because of an invalid URL, then subsequent calls to GetLastError return **ERROR_WINHTTP_INVALID_URL**. |

### `lpUrlComponents` [in, out]

Pointer to a
[URL_COMPONENTS](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-url_components) structure that receives the URL components.

## Return value

Returns **TRUE** if the function succeeds, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Codes | Description |
| --- | --- |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_INVALID_URL** | The URL is invalid. |
| **ERROR_WINHTTP_UNRECOGNIZED_SCHEME** | The URL scheme could not be recognized, or is not supported. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The required components are indicated by members of the
[URL_COMPONENTS](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-url_components) structure. Each component has a pointer to the value and has a member that stores the length of the stored value. If both the value and the length for a component are equal to zero, that component is not returned. If the pointer to the value of the component is **NULL** and the value of its corresponding length member is nonzero, the address of the first character of the corresponding component in the
*pwszUrl* string is stored in the pointer, and the length of the component is stored in the length member.

If the pointer contains the address of the user-supplied buffer, the length member must contain the size of the buffer. The
**WinHttpCrackUrl** function copies the component into the buffer, and the length member is set to the length of the copied component, minus 1 for the trailing string terminator. If a user-supplied buffer is not large enough, **WinHttpCrackUrl** returns **FALSE**, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INSUFFICIENT_BUFFER**.

When _lpszExtraInfo_ is not set or _dwExtraInfoLength_ is left as 0 in _lpUrlComponents_, if _lpszUrlPath_ is set the query and/or fragment component of the URL will be included in that field.

For
**WinHttpCrackUrl** to work properly, the size of the
[URL_COMPONENTS](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-url_components) structure must be stored in the
[dwStructSize](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-url_components) member of that structure.

If the Internet protocol of the URL passed in for
*pwszUrl* is not HTTP or HTTPS, then
**WinHttpCrackUrl** returns **FALSE** and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) indicates
[ERROR_WINHTTP_UNRECOGNIZED_SCHEME](https://learn.microsoft.com/windows/desktop/WinHttp/error-messages).

**WinHttpCrackUrl** does not check the validity or format of a URL before attempting to crack it. As a result, if a string such as ""http://server?Bad=URL"" is passed in, the function returns incorrect results.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

#### Examples

This example shows how to break a URL into its components, update a component, then reconstruct the URL.

```cpp
    URL_COMPONENTS urlComp;
    LPCWSTR pwszUrl1 =
      L"http://search.msn.com/results.asp?RS=CHECKED&FORM=MSNH&v=1&q=wininet";
    DWORD dwUrlLen = 0;

    // Initialize the URL_COMPONENTS structure.
    ZeroMemory(&urlComp, sizeof(urlComp));
    urlComp.dwStructSize = sizeof(urlComp);

    // Set required component lengths to non-zero
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
        // Change the search information.
        // New info is the same length.
        urlComp.lpszExtraInfo = L"?RS=CHECKED&FORM=MSNH&v=1&q=winhttp";

        // Obtain the size of the new URL and allocate memory.
        WinHttpCreateUrl( &urlComp, 0, NULL, &dwUrlLen);
        LPWSTR pwszUrl2 = new WCHAR[dwUrlLen];

        // Create a new URL.
        if(!WinHttpCreateUrl( &urlComp, 0, pwszUrl2, &dwUrlLen))
        {
            printf("Error %u in WinHttpCreateUrl.\n", GetLastError());
        }
        else
        {
            // Show both URLs.
            printf("Old URL:  %S\nNew URL:  %S\n", pwszUrl1, pwszUrl2);
        }

        // Free allocated memory.
        delete [] pwszUrl2;
    }

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[Handling Uniform Resource Locators](https://learn.microsoft.com/windows/desktop/WinHttp/uniform-resource-locators--urls--in-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCreateUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcreateurl)