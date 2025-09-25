# IMFDeviceTransform::GetOutputStreamState

## Description

The **GetOutputStreamState** method gets the Device MFT’s output stream state.

## Parameters

### `dwStreamID` [in]

Stream ID of the output stream whose state needs to be retrieved.

### `value` [out]

Specifies the current **DeviceStreamState** of the specified output Device MFT stream.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Transitioning the stream state succeeded. |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVAILIDSTREAMNUMBER** | An invalid stream ID was passed. |

## Remarks

This method is used by device transform manager (DTM) to get a specific output stream’s state.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)