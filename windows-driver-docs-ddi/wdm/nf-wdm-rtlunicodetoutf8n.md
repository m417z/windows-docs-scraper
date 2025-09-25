# RtlUnicodeToUTF8N function (wdm.h)

## Description

The **RtlUnicodeToUTF8N** routine converts a Unicode string to a UTF-8 string.

## Parameters

### `UTF8StringDestination` [out]

A pointer to a caller-allocated destination buffer into which the routine writes the UTF-8 output string. If this parameter is **NULL**, the routine writes the required size of the output buffer to **UTF8StringActualByteCount*.

### `UTF8StringMaxByteCount` [in]

Specifies the maximum number of bytes that the routine can write to the buffer that *UTF8StringDestination* points to. If *UTF8StringDestination* = **NULL**, set *UTF8StringMaxByteCount* = 0.

### `UTF8StringActualByteCount` [out]

A pointer to a location into which the routine writes the actual number of bytes that it has written to the buffer that *UTF8StringDestination* points to. If *UTF8StringDestination* is non-**NULL**, this count never exceeds the value of *UTF8StringMaxByteCount*. If *UTF8StringDestination* is **NULL**, this count is the number of bytes that are required to contain the entire output string.

### `UnicodeStringSource` [in]

A pointer to the Unicode source string.

### `UnicodeStringByteCount` [in]

Specifies the number of bytes in the Unicode source string that the *UnicodeStringSource* parameter points to.

## Return value

**RtlUnicodeToUTF8N** returns STATUS_SUCCESS if the call is successful and all Unicode character codes in the input string were converted to the corresponding UTF-8 character codes in the output string. It returns STATUS_SOME_NOT_MAPPED if the call is successful but one or more input characters were invalid and were replaced by the Unicode replacement character, U+FFFD, before they were converted to UTF-8. Possible error return values include the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The *UTF8StringMaxByteCount* parameter specifies a buffer size that is too small to contain the entire output string. |
| **STATUS_INVALID_PARAMETER** | The *UTF8StringDestination* and *UTF8StringActualByteCount* parameters are both **NULL**. |
| **STATUS_INVALID_PARAMETER_4** | The *UnicodeStringSource* parameter is **NULL**. |
| **STATUS_INVALID_PARAMETER_5** | *UnicodeStringByteCount* is not an integer multiple of **sizeof**(WCHAR). |

## Remarks

The UTF-8 output string is null-terminated only if the Unicode input string is null-terminated.

The routine returns STATUS_BUFFER_TOO_SMALL if the *UTF8StringMaxByteCount* parameter specifies a buffer size that is too small to contain the entire output string. In this case, the routine writes as many UTF-8 characters as will fit in the buffer, and the **UTF8StringActualByteCount* value specifies the number of valid bytes that the routine has written to the buffer. The partial string that is contained in the output buffer might not include a terminating null character.

You can make an initial call to **RtlUnicodeToUTF8N** to obtain the required output buffer size, and then call **RtlUnicodeToUTF8N** again to obtain the Unicode output string. In the initial call, set *UTF8StringDestination* = **NULL** and *UTF8StringMaxByteCount* = 0, and the routine will write the required buffer size to **UTF8StringActualByteCount*. Next, allocate a buffer of the required size and call **RtlUnicodeToUTF8N** a second time to obtain the UTF-8 output string.

**RtlUnicodeToUTF8N** supports Unicode surrogate pairs. However, a surrogate leading word value that is not followed by a trailing word value, or a trailing word value that is not preceded by a leading word value, is not recognized as a valid character code and is replaced by the Unicode replacement character, U+FFFD.

**RtlUnicodeToUTF8N** continues to convert the input string to an output string until it reaches the end of the source buffer or the end of the destination buffer, whichever occurs first. The routine converts any null characters in the input string to null characters in the output string. If the input string contains a terminating null character, but the null character is not located at the end of the source buffer, the routine continues past the terminating null character until it reaches the end of the available buffer space.

The [RtlUTF8ToUnicodeN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlutf8tounicoden) routine converts a UTF-8 string to a Unicode string.

You can use **RtlUnicodeToUTF8N** and **RtlUTF8ToUnicode** routines to perform a lossless conversion of valid text strings between the Unicode and UTF-8 formats. However, strings that have arbitrary data values are likely to violate the Unicode rules for encoding surrogate pairs, and any information that is contained in the invalid values in an input string is lost and cannot be recovered from the resulting output string.

## See also

[RtlUTF8ToUnicodeN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlutf8tounicoden)