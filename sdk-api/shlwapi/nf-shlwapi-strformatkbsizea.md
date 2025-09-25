# StrFormatKBSizeA function

## Description

Converts a numeric value into a string that represents the number expressed as a size value in kilobytes.

## Parameters

### `qdw`

Type: **LONGLONG**

The numeric value to be converted.

### `pszBuf` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives the converted number.

### `cchBuf`

Type: **UINT**

The size of *pszBuf*, in characters.

## Return value

Type: **PTSTR**

Returns a pointer to the converted string, or **NULL** if the conversion fails.

## Remarks

In Windows 10, size is reported in base 10 rather than base 2. For example, 1 KB is 1000 bytes rather than 1024.

> [!NOTE]
> The shlwapi.h header defines StrFormatKBSize as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[StrFormatByteSizeA](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizea)

[StrFormatByteSizeW](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizew)