# RtlUnicodeStringToUTF8String function (ntifs.h)

## Description

**RtlUnicodeStringToUTF8String** converts the specified Unicode string into a UTF-8 string.

## Parameters

### `DestinationString`

Pointer to the buffer in which the converted output UTF-8 string is placed. The *DestinationString->MaximumLength* field is set only if **AllocateDestinationString** is TRUE.

### `SourceString`

Pointer to the Unicode string to be converted to UTF-8.

### `AllocateDestinationString`

Boolean value. When set TRUE, **RtlUnicodeStringToUTF8String** allocates the buffer space for the destination string. Only storage for *DestinationString->Buffer* is allocated by this API. If **RtlUnicodeStringToUTF8String** does the buffer allocation, then the caller must deallocate the buffer using [**RtlFreeUTF8String**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeutf8string).

## Return value

This function returns STATUS_SUCCESS when the conversion is successful. Possible error or warning codes include:

| Code | Description |
| --------------------------- | ----------- |
| STATUS_INVALID_PARAMETER*X* | Error: One of the parameter values is invalid. |
| STATUS_NO_MEMORY | Error: **RtlUnicodeStringToUTF8String** was unable to allocate buffer space. |
| STATUS_BUFFER_OVERFLOW | Warning: The converted string in *DestinationString->Buffer* is truncated due to insufficient space in the destination buffer. |
| STATUS_SOME_NOT_MAPPED | Warning: The call was successful, but one or more of the input characters were invalid and were replaced by the Unicode replacement character, U+FFFD, before being converted to UTF-8. |

## Remarks

The UTF-8 output string is null-terminated only if the Unicode input string is null-terminated.

**RtlUnicodeStringToUTF8String** supports Unicode surrogate pairs. However, a surrogate leading word value that is not followed by a trailing word value, or a trailing word value that is not preceded by a leading word value, is not recognized as a valid character code and is replaced by the Unicode replacement character, U+FFFD.

**RtlUnicodeStringToUTF8String** continues to convert the input string to an output string until it reaches the end of the source buffer or the end of the destination buffer, whichever occurs first. The routine converts any null characters in the input string to null characters in the output string. If the input string contains a terminating null character, but the null character is not located at the end of the source buffer, the routine continues past the terminating null character until it reaches the end of the available buffer space.

The [**RtlUTF8StringToUnicodeString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlutf8stringtounicodestring) routine converts a UTF-8 string to a Unicode string.

You can use the **RtlUnicodeStringToUTF8String** and [**RtlUTF8StringToUnicodeString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlutf8stringtounicodestring) routines to perform a lossless conversion of valid text strings between the Unicode and UTF-8 formats. However, strings that have arbitrary data values are likely to violate the Unicode rules for encoding surrogate pairs, and any information that is contained in the invalid values in an input string is lost and cannot be recovered from the resulting output string.

## See also

[**RtlFreeUTF8String**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeutf8string)

[**RtlUTF8StringToUnicodeString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlutf8stringtounicodestring)