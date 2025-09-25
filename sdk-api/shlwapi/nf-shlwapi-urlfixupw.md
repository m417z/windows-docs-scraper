# UrlFixupW function

## Description

[**UrlFixupW** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Attempts to correct a URL whose protocol identifier is incorrect. For example, `htttp` will be changed to `http`.

## Parameters

### `pcszUrl` [in]

Type: **PCWSTR**

A pointer to a **null**-terminated string that contains the URL to be corrected. This string must not exceed INTERNET_MAX_PATH_LENGTH characters in length, including the terminating **NULL** character.

### `pszTranslatedUrl` [out]

Type: **PWSTR**

A pointer to a buffer that, when this function returns successfully, receives the copied characters. The buffer must be large enough to contain the number of WCHAR characters specified by the *cchMax* parameter, including the terminating **NULL** character. This parameter can be equal to the *pcszUrl* parameter to correct a URL in place. If *pszTranslatedUrl* is not equal to *pcszUrl*, the buffer pointed to by *pszTranslatedUrl* must not overlap the buffer pointed to by *pcszUrl*.

### `cchMax`

Type: **DWORD**

The number of **WCHAR** characters that can be contained in the buffer pointed to by *pszTranslatedUrl*. This parameter must be greater than zero.

## Return value

Type: **HRESULT**

Returns S_OK if the proposed URL was already acceptable or was successfully corrected. The *pszTranslatedUrl* buffer contains the corrected URL, or the original URL if no correction was needed. Returns S_FALSE if the proposed URL could not be recognized sufficiently to be corrected. Otherwise, returns a standard COM error code.

## Remarks

The UrlFixup function recognizes the schemes specified by the [URL_SCHEME](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-url_scheme) enumeration.

Priority is given to the first character in the protocol identifier section so `htp` will be converted to `http` instead of `ftp`.

**Note** Do not use this function for deterministic data transformation. The heuristics used by **UrlFixupW** can change from one release to the next. The function should only be used to correct possibly invalid user input.

This function is available only in a Unicode version.

#### Examples

This example shows how to use **UrlFixupW**. Notice that the last four autocorrections were probably not what the user intended and demonstrate limitations of the heuristic used by the function.

```cpp

#include <windows.h>
#include <shlwapi.h>
#include <stdio.h>
#include <tchar.h>

void sample(LPCWSTR pszUrl)
{
    WCHAR szBuf[256];

    HRESULT hr = UrlFixupW(pszUrl, szBuf, 256);
    if (hr == S_OK)
    {
        wprintf(L"%-35s %s\n", pszUrl, szBuf);
    }
    else
    {
        wprintf(L"%-35s failed\n", pszUrl);
    }
}

int __cdecl main()
{
    sample(L"http://www.microsoft.com");
    sample(L"mail:someone@example.com");
    sample(L"abc:def");
    sample(L"someone@example.com");
    sample(L"htpp:wwwmicrosoft.com");
    sample(L"htps:\\\\www.microsoft.com");
    sample(L"http:someone@example.com");

    return 0;
}

..................................

This example might produce the following output:

http://www.microsoft.com    http://www.microsoft.com
http:www.microsoft.com      http://www.microsoft.com
mail:someone@example.com    mailto:someone@example.com
abc:def                     failed
someone@example.com         failed
htpp:wwwmicrosoft.com       http://wwwmicrosoft.com
htps:\\www.microsoft.com    http://www.microsoft.com
http:someone@example.com    http://someone@example.com

```