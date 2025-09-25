# IMFStreamingSinkConfig::StartStreaming

## Description

Called by the streaming media client before the Media Session starts streaming to specify the byte offset or the time offset.

## Parameters

### `fSeekOffsetIsByteOffset` [in]

 A Boolean value that specifies whether *qwSeekOffset* gives a byte offset of a time offset.

| Value | Meaning |
| --- | --- |
| **TRUE** | The *qwSeekOffset* parameter specifies a byte offset. |
| **FALSE** | The *qwSeekOffset* parameter specifies the time position in 100-nanosecond units. |

### `qwSeekOffset` [in]

A byte offset or a time offset, depending on the value passed in *fSeekOffsetIsByteOffset*. Time offsets are specified in
100-nanosecond units.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFStreamingSinkConfig](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamingsinkconfig)