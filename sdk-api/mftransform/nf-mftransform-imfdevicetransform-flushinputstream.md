# IMFDeviceTransform::FlushInputStream

## Description

The **FlushInputStream** method flushes a Device MFT’s input stream.

## Parameters

### `dwStreamIndex` [in]

Stream ID of the input stream which needs to be flushed.

### `dwFlags` [in]

Contains the **HRESULT** of flushing the corresponding devproxy output stream.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Transitioning the stream state succeeded. |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVAILIDSTREAMNUMBER** | An invalid stream ID was passed. |
| **MF_E_INVALID_STREAM_STATE** | The requested stream transition is not possible. |

## Remarks

This interface method helps to flush a Device MFT’s input stream.

Device MFT should drop all samples in its queues and reset all its internal data structures related to that input stream. This is equivalent to resetting the input stream. The media type and stream state must not change.

### When called

When the input stream needs to be reset, device transform manager (DTM) would call this method.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)