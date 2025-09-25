# Shell_GetCachedImageIndexW function

## Description

[**Shell_GetCachedImageIndex** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use **Shell_GetCachedImageIndexA** or **Shell_GetCachedImageIndexW**.]

Retrieves the cache index of a cached icon.

## Parameters

### `pszIconPath`

TBD

### `iIconIndex`

Type: **int**

The index of the image within the file named at *pwszIconPath*.

### `uIconFlags`

Type: **UINT**

Not used.

#### - pwszIconPath [in]

Type: **PCWSTR**

A pointer to a buffer that contains the path to the image file.

## Return value

Type: **int**

Returns the index of the image, or –1 on failure.

## Remarks

The **Shell_GetCachedImageIndexA** and **Shell_GetCachedImageIndexW** versions of this function were added in Windows Vista. For Unicode strings, call either **Shell_GetCachedImageIndexW** or **Shell_GetCachedImageIndex**. For ANSI strings, you must call **Shell_GetCachedImageIndexA** explicitly.

**Windows Server 2003 and Windows XP:** Only **Shell_GetCachedImageIndex** is supported. **Shell_GetCachedImageIndex** requires a Unicode string.

> [!NOTE]
> The shlobj_core.h header defines Shell_GetCachedImageIndex as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FileIconInit](https://learn.microsoft.com/windows/desktop/shell/fileiconinit)