# CreateUrlCacheEntryW function

## Description

Creates a local file name for saving the cache entry based on the specified URL and the file name extension.

## Parameters

### `lpszUrlName` [in]

Pointer to a string value that contains the name of the URL. The string must contain a value; an empty string will cause **CreateUrlCacheEntry** to fail. In addition, the string must not contain any escape characters.

### `dwExpectedFileSize` [in]

Expected size of the file needed to store the data that corresponds to the source entity, in **TCHARs**. If the expected size is unknown, set this value to zero.

### `lpszFileExtension` [in]

Pointer to a string value that contains an extension name of the file in the local storage.

### `lpszFileName` [out]

Pointer to a buffer that receives the file name. The buffer should be large enough to store the path of the created file (at least MAX_PATH characters in length).

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After
**CreateUrlCacheEntry** is called, the application can write directly into the file in local storage. When the file is completely received, the caller should call
[CommitUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-commiturlcacheentrya) to commit the entry in the cache.

WinINet attempts to decode Unicode parameters according to the system code page. Applications should ensure that Unicode parameters are properly encoded for the system code page. Applications can set the system code page with [InternetSetOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetoptiona) as shown in the following code example:

``` syntax
DWORD CP_SHIFT_JIS = 932;  // ANSI/OEM  Japanese, Shift-JIS
InternetSetOption( hRequest,
                   INTERNET_OPTION_CODEPAGE,
                   &CP_SHIFT_JIS,
                   sizeof(DWORD) );
```

If the Unicode parameter is not properly encoded to the system code page, WinINet attempts UTF8 decoding.

When items are retrieved from the cache, the system code page that was used to place the item in the cache must match the current system code page for the user. For applications running under IE6 and earlier, if decoding for the system code page fails, WinINet attempts UTF8 decoding.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines CreateUrlCacheEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Caching](https://learn.microsoft.com/windows/desktop/WinInet/caching)

[CommitUrlCacheEntry](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-commiturlcacheentrya)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)