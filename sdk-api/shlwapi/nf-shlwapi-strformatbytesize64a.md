# StrFormatByteSize64A function

## Description

Converts a numeric value into a string that represents the number expressed as a size value in bytes, kilobytes, megabytes, or gigabytes, depending on the size.

## Parameters

### `qdw`

Type: **LONGLONG**

The numeric value to be converted.

### `pszBuf` [out]

Type: **PSTR**

A pointer to a buffer that, when this function returns successfully, receives the converted number.

### `cchBuf`

Type: **UINT**

The size of the buffer pointed to by *pszBuf*, in characters.

## Return value

Type: **PSTR**

Returns a pointer to the converted string, or **NULL** if the conversion fails.

## Remarks

**StrFormatByteSize64** can be used for either ANSI or Unicode characters. However, while **StrFormatByteSize64A** can be called directly, **StrFormatByteSize64W** is not defined. When **StrFormatByteSize64** is called with a Unicode value, [StrFormatByteSizeW](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizew) is used.

In Windows 10, size is reported in base 10 rather than base 2. For example, 1 KB is 1000 bytes rather than 1024.

The following table illustrates how this function converts a numeric value into a text string.

| Numeric value | Text string |
| --- | --- |
| 532 | 532 bytes |
| 1340 | 1.30 KB |
| 23506 | 23.5 KB |
| 2400016 | 2.40 MB |
| 2400000000 | 2.4 GB |

## See also

[StrFormatByteSizeA](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizea)

[StrFormatByteSizeW](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizew)