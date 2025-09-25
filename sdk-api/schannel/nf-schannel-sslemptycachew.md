# SslEmptyCacheW function

## Description

Removes the specified string from the Schannel cache.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Schannel.dll.

## Parameters

### `pszTargetName` [in]

A pointer to a null-terminated string that specifies the entry to remove from the cache. If the value of this parameter is **NULL**, all entries are removed from the cache.

### `dwFlags` [in]

This parameter is not used.

## Return value

Returns nonzero if the specified entries are removed from the Schannel cache or zero otherwise.

## Remarks

> [!NOTE]
> The schannel.h header defines SslEmptyCache as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).