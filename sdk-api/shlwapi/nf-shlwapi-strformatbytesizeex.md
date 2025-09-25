# StrFormatByteSizeEx function

## Description

Converts a numeric value into a string that represents the number in bytes, kilobytes, megabytes, or gigabytes, depending on the size. Extends [StrFormatByteSizeW](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizew) by offering the option to round to the nearest displayed digit or to discard undisplayed digits.

## Parameters

### `ull`

Type: **ULONGLONG**

The numeric value to be converted.

### `flags`

Type: **[SFBS_FLAGS](https://learn.microsoft.com/windows/win32/api/shlwapi/ne-shlwapi-tagsfbs_flags)**

One of the [SFBS_FLAGS](https://learn.microsoft.com/windows/win32/api/shlwapi/ne-shlwapi-tagsfbs_flags) enumeration values that specifies whether to round or truncate undisplayed digits. This value cannot be NULL.

### `pszBuf` [out]

Type: **PWSTR**

A pointer to a buffer that receives the converted string.

### `cchBuf`

Type: **UINT**

The size of the buffer pointed to by *pszBuf*, in characters.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following table illustrates how this function converts a numeric value into a text string in relation to the passed flag.

| Numeric value | Flag | Text string |
| --- | --- | --- |
| 2147483647 | SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT | 2.00 GB |
| 2147483647 | SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS | 1.99 GB |

In Windows 10, size is reported in base 10 rather than base 2. For example, 1 KB is 1000 bytes rather than 1024.

## See also

[StrFormatByteSize64](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesize64a)

[StrFormatByteSizeA](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizea)

[StrFormatByteSizeW](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizew)