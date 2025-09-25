# ParseURLA function

## Description

Performs rudimentary parsing of a URL.

## Parameters

### `pcszURL` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string containing the URL to be parsed.

### `ppu` [in, out]

Type: **[PARSEDURL](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-parsedurla)***

A pointer to a [PARSEDURL](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-parsedurla) structure that receives the parsed results. The calling application must set the structure's *cbSize* member to the size of the structure before calling **ParseURL**.

## Return value

Type: **HRESULT**

Returns **S_OK** on success, or a COM error code otherwise. The function returns **URL_E_INVALID_SYNTAX** (defined in Intshcut.h) if the string could not be parsed as a URL.

## Remarks

The parsing performed by **ParseURL** is fairly rudimentary. For more sophisticated URL parsing, use [InternetCrackUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcrackurla).

#### Examples

This sample console application uses **ParseURL** to parse several simple URLs.

```cpp

#include <windows.h>
#include <shlwapi.h>
#include <stdio.h>
#include <tchar.h>

void sample(LPCTSTR pcszUrl)
{
    PARSEDURL pu;
    pu.cbSize = sizeof(pu);
    HRESULT hr = ParseURL(pcszUrl, &pu);
    _tprintf(TEXT("ParseURL(%s) returned 0x%08x\n"), pcszUrl, hr);
    if (SUCCEEDED(hr)) {
        _tprintf(TEXT("Protocol = %.*s\n"), pu.cchProtocol, pu.pszProtocol);
        _tprintf(TEXT("Suffix   = %.*s\n"), pu.cchSuffix, pu.pszSuffix);
        _tprintf(TEXT("Scheme   = %d\n"), pu.nScheme);
        _tprintf(TEXT("\n"));
    }
}

int __cdecl main()
{
    sample(TEXT("http://msdn.microsoft.com/vstudio/"));
    sample(TEXT("mailto:someone@example.com"));
    sample(TEXT("file://C:\\AUTOEXEC.BAT"));
    sample(TEXT("C:\\AUTOEXEC.BAT"));
    return 0;
}

OUTPUT:
---------

ParseURL(http://msdn.microsoft.com/vstudio/) returned 0x00000000
Protocol = http
Suffix   = //msdn.microsoft.com/vstudio/
Scheme   = 2

ParseURL(mailto:someone@example.com) returned 0x00000000
Protocol = mailto
Suffix   = someone@example.com
Scheme   = 4

ParseURL(file://C:\AUTOEXEC.BAT) returned 0x00000000
Protocol = file
Suffix   = C:\AUTOEXEC.BAT
Scheme   = 9

ParseURL(C:\AUTOEXEC.BAT) returned 0x80041001

```

> [!NOTE]
> The shlwapi.h header defines ParseURL as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).