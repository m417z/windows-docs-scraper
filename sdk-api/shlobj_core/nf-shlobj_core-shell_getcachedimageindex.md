# Shell_GetCachedImageIndex function

## Description

[**Shell_GetCachedImageIndex** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use **Shell_GetCachedImageIndexA** or **Shell_GetCachedImageIndexW**.]

Retrieves the cache index of a cached icon.

## Parameters

### `pwszIconPath` [in]

Type: **PCWSTR**

A pointer to a buffer that contains the path to the image file.

### `iIconIndex`

Type: **int**

The index of the image within the file named at *pwszIconPath*.

### `uIconFlags`

Type: **UINT**

Not used.

## Return value

Type: **int**

Returns the index of the image, or –1 on failure.

## Remarks

The **Shell_GetCachedImageIndexA** and **Shell_GetCachedImageIndexW** versions of this function were added in Windows Vista. For Unicode strings, call either **Shell_GetCachedImageIndexW** or **Shell_GetCachedImageIndex**. For ANSI strings, you must call **Shell_GetCachedImageIndexA** explicitly.

**Windows Server 2003 and Windows XP:** Only **Shell_GetCachedImageIndex** is supported. **Shell_GetCachedImageIndex** requires a Unicode string.

## See also

[FileIconInit](https://learn.microsoft.com/windows/desktop/shell/fileiconinit)