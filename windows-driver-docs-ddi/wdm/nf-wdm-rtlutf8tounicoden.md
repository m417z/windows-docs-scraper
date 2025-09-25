# RtlUTF8ToUnicodeN function (wdm.h)

## Description

The **RtlUTF8ToUnicodeN** routine converts a UTF-8 string to a Unicode string.

## Parameters

### `UnicodeStringDestination` [out, optional]

A pointer to a caller-allocated destination buffer into which the routine writes the Unicode output string. If this parameter is **NULL**, the routine writes the required size of the output buffer to **UnicodeStringActualByteCount*.

### `UnicodeStringMaxByteCount` [in]

Specifies the maximum number of bytes that the routine can write to the buffer that *UnicodeStringDestination* points to. If *UnicodeStringDestination* = **NULL**, set *UnicodeStringMaxByteCount* = 0.

### `UnicodeStringActualByteCount` [out]

A pointer to a location into which the routine writes the actual number of bytes that the routine has written to the buffer that *UnicodeStringDestination* points to. If *UnicodeStringDestination* is non-**NULL**, this count never exceeds the value of *UnicodeStringMaxByteCount*. If *UnicodeStringDestination* is **NULL**, this count is the number of bytes that are required to contain the entire output string.

### `UTF8StringSource` [in]

A pointer to the UTF-8 source string.

### `UTF8StringByteCount` [in]

Specifies the number of bytes in the UTF-8 source string that the *UTF8StringSource* parameter points to.

## Return value

**RtlUTF8ToUnicodeN** returns STATUS_SUCCESS if the call is successful and all UTF-8 character codes in the input string were converted to the corresponding Unicode character codes in the output string. It returns STATUS_SOME_NOT_MAPPED if the call is successful but one or more input characters were invalid and were converted to the Unicode replacement character, U+FFFD. Possible error return values include the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The *UnicodeStringMaxByteCount* parameter specifies a buffer size that is too small to contain the entire output string. |
| **STATUS_INVALID_PARAMETER** | The *UnicodeStringDestination* and *UnicodeStringActualByteCount* parameters are both **NULL**. |
| **STATUS_INVALID_PARAMETER_4** | The *UTF8StringSource* parameter is **NULL**. |

## Remarks

The Unicode output string is null-terminated only if the UTF-8 input string is null-terminated.

The routine returns STATUS_BUFFER_TOO_SMALL if the *UnicodeStringMaxByteCount* parameter specifies a buffer size that is too small to contain the entire output string. In this case, the routine writes as many Unicode characters as will fit in the buffer, and the **UnicodeStringActualByteCount* value specifies the number of valid bytes that the routine has written to the buffer. The partial string that is contained in the output buffer might not include a terminating null character.

You can make an initial call to **RtlUTF8ToUnicodeN** to obtain the required output buffer size, and then call **RtlUTF8ToUnicodeN** again to obtain the Unicode output string. In the initial call, set *UnicodeStringDestination* = **NULL** and *UnicodeStringMaxByteCount* = 0, and the routine will write the required buffer size to **UnicodeStringActualByteCount*. Next, allocate a buffer of the required size and call **RtlUTF8ToUnicodeN** a second time to obtain the Unicode output string.

**RtlUTF8ToUnicodeN** supports Unicode surrogate pairs. However, a surrogate leading word value that is not followed by a trailing word value, or a trailing word value that is not preceded by a leading word value, is not recognized as a valid character and is replaced by the Unicode replacement character, U+FFFD.

**RtlUTF8ToUnicodeN** continues to convert the input string to an output string until it reaches the end of the source buffer or the end of the destination buffer, whichever occurs first. The routine converts any null characters in the input string to null characters in the output string. If the input string contains a terminating null character, but the null character is not located at the end of the source buffer, the routine continues past the terminating null character until it reaches the end of the available buffer space.

The [RtlUnicodeToUTF8N](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetoutf8n) routine converts a Unicode string to a UTF-8 string.

You can use the **RtlUTF8ToUnicode** and **RtlUnicodeToUTF8N** routines to perform a lossless conversion of valid text strings between the UTF-8 and Unicode formats. However, strings that have arbitrary data values are likely to violate the Unicode rules for encoding surrogate pairs, and any information that is contained in the invalid values in an input string is lost and cannot be recovered from the resulting output string.

## See also

[RtlUnicodeToUTF8N](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetoutf8n)