# StrFormatByteSizeA function

## Description

Converts a numeric value into a string that represents the number expressed as a size value in bytes, kilobytes, megabytes, or gigabytes, depending on the size. Differs from [StrFormatByteSizeW](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizew) in one parameter type.

## Parameters

### `dw`

Type: **DWORD**

The numeric value to be converted.

### `pszBuf` [out]

Type: **PSTR**

A pointer to a buffer that receives the converted string.

### `cchBuf`

Type: **UINT**

The size of the buffer pointed to by *pszBuf*, in characters.

## Return value

Type: **PSTR**

Returns a pointer to the converted string, or **NULL** if the conversion fails.

## Remarks

The first parameter of this function has a different type for the ANSI and Unicode versions. If your numeric value is a **DWORD**, you can use **StrFormatByteSize** with text macros for both cases. The compiler will cast the numerical value to a **LONGLONG** for the Unicode case. If your numerical value is a **LONGLONG**, you should use [StrFormatByteSizeW](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizew) explicitly.

In Windows 10, size is reported in base 10 rather than base 2. For example, 1 KB is 1000 bytes rather than 1024.

The following table illustrates how this function converts a numeric value into a text string.

| Numeric value | Text string |
| --- | --- |
| 532 | 532 bytes |
| 1340 | 1.30 KB |
| 23506 | 22.9 KB |
| 2400016 | 2.28 MB |
| 2400000000 | 2.23 GB |

> [!NOTE]
> The shlwapi.h header defines StrFormatByteSize as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[StrFormatByteSize64](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesize64a)

[StrFormatByteSizeEx](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizeex)

[StrFormatByteSizeW](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strformatbytesizew)