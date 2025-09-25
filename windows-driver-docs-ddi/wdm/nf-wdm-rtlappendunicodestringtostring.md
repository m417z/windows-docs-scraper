# RtlAppendUnicodeStringToString function

## Description

The **RtlAppendUnicodeStringToString** routine concatenates two Unicode strings.

## Parameters

### `Destination` [in, out]

Pointer to a buffered Unicode string.

### `Source` [in]

Pointer to the buffered string to be concatenated.

## Return value

**RtlAppendUnicodeStringToString** can return one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The source string was successfully appended to the destination counted string. The destination string length is updated to include the appended bytes. |
| **STATUS_BUFFER_TOO_SMALL** | The destination string length is too small to allow the source string to be concatenated. Accordingly, the destination string length is not updated. |

## Remarks

**RtlAppendUnicodeStringToString** copies bytes from the source to the specified destination string, after the current contents of the destination string and the destination length is incremented by the number of bytes copied.

The *Destination* and *Source* buffers must be resident if the caller is running at IRQL >= DISPATCH_LEVEL.

## See also

[RtlAppendUnicodeToString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlappendunicodetostring)