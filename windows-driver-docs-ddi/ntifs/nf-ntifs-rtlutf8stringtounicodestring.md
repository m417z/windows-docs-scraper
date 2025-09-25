# RtlUTF8StringToUnicodeString function (ntifs.h)

## Description

The **RtlUTF8StringToUnicodeString** routine converts the specified UTF-8 string to a Unicode string.

## Parameters

### `DestinationString`

Pointer to the buffer in which the converted output Unicode string is stored. The *DestinationString->MaximumLength* field is set only if **AllocateDestinationString** is TRUE.

### `SourceString`

Pointer to the UTF-8 source string to be converted to Unicode.

### `AllocateDestinationString`

Boolean value. When set TRUE, **RtlUTF8StringToUnicodeString** allocates the buffer space for the destination string. Only storage for *DestinationString->Buffer* is allocated by this API. If **RtlUTF8StringToUnicodeString** does the buffer allocation, then the caller must deallocate the buffer using [**RtlFreeUnicodeString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring).

## Return value

This function returns STATUS_SUCCESS when the conversion is successful. Possible error or warning codes include:

| Code | Description |
| ------------------------- | ----------- |
| STATUS_INVALID_PARAMETER*X* | Error: One of the parameter values is invalid. |
| STATUS_NO_MEMORY | Error: **RtlUTF8StringToUnicodeString** was unable to allocate buffer space. |
| STATUS_BUFFER_OVERFLOW | Warning: The converted string in *DestinationString->Buffer* is truncated due to insufficient space in the destination buffer. |
| STATUS_SOME_NOT_MAPPED | Warning: The call was successful, but one or more of the input characters were invalid and were converted by the Unicode replacement character, U+FFFD, before being converted to UTF-8. |

## Remarks

The Unicode output string is null-terminated only if the UTF-8 input string is null-terminated.

**RtlUTF8StringToUnicodeString** supports Unicode surrogate pairs. However, a surrogate leading word value that is not followed by a trailing word value, or a trailing word value that is not preceded by a leading word value, is not recognized as a valid character and is replaced by the Unicode replacement character, U+FFFD.

**RtlUTF8StringToUnicodeString** continues to convert the input string to an output string until it reaches the end of the source buffer or the end of the destination buffer, whichever occurs first. The routine converts any null characters in the input string to null characters in the output string. If the input string contains a terminating null character, but the null character is not located at the end of the source buffer, the routine continues past the terminating null character until it reaches the end of the available buffer space.

The [**RtlUnicodeStringToUTF8String**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtoutf8string) routine converts a Unicode string to a UTF-8 string.

You can use the **RtlUTF8StringToUnicodeString** and [**RtlUnicodeStringToUTF8String**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtoutf8string) routines to perform a lossless conversion of valid text strings between the UTF-8 and Unicode formats. However, strings that have arbitrary data values are likely to violate the Unicode rules for encoding surrogate pairs, and any information that is contained in the invalid values in an input string is lost and cannot be recovered from the resulting output string.

## See also

[**RtlFreeUnicodeString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)

[**RtlUnicodeStringToUTF8String**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtoutf8string)