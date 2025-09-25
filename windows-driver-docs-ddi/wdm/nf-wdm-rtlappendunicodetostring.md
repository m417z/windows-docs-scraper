# RtlAppendUnicodeToString function

## Description

The **RtlAppendUnicodeToString** routine concatenates the supplied Unicode string to a buffered Unicode string.

## Parameters

### `Destination` [in, out]

A pointer to the buffered string.

### `Source` [in, optional]

A pointer to the null-terminated string to append to the *Destination* string.

## Return value

**RtlAppendUnicodeToString** can return one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The source string was successfully appended to the destination string, and the destination string length was updated to include the appended bytes. |
| **STATUS_BUFFER_TOO_SMALL** | The destination string buffer is too small to allow the source string to be appended, so the destination string length is not updated and the contents of the destination string buffer are not changed. |

## Remarks

**RtlAppendUnicodeToString** appends the source string to the end of the destination string.

If the destination buffer is not large enough to contain the string that would result from concatenating the source and destination strings (not including the null character that terminates the source string), the routine returns STATUS_BUFFER_TOO_SMALL and leaves the destination string unchanged.

The *Destination* buffer must be resident if the caller is running at IRQL >= DISPATCH_LEVEL.

## See also

[RtlAppendUnicodeStringToString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlappendunicodestringtostring)