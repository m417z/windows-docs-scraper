# IMFByteStreamBuffering::StopBuffering

## Description

Stops any buffering that is in progress.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The byte stream successfully stopped buffering. |
| **S_FALSE** | No buffering was in progress. |

## Remarks

If the byte stream is currently buffering data, it stops and sends an [MEBufferingStopped](https://learn.microsoft.com/windows/desktop/medfound/mebufferingstopped) event. If the byte stream is not currently buffering, this method has no effect.

## See also

[IMFByteStreamBuffering](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreambuffering)