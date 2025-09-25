# IMFDeviceTransform::SetInputStreamState

## Description

The **SetInputStreamState** method sets the Device MFT input stream state and media type.

## Parameters

### `dwStreamID` [in]

Stream ID of the input stream where the state and media type needs to be changed.

### `pMediaType` [in]

Preferred media type for the input stream is passed in through this parameter. Device MFT should change the media type only if the incoming media type is different from the current media type.

### `value` [in]

Specifies the **DeviceStreamState** which the input stream should transition to.

### `dwFlags` [in]

When **S_OK** is returned, perform the state change operation. Otherwise, this contains an error that occurred while setting the media type on the devproxy output pin. In this case, propagate the error appropriately.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Initialization succeeded |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVAILIDSTREAMNUMBER** | An invalid stream ID was passed. |
| **MF_E_INVALID_STREAM_STATE** | The requested stream transition is not possible. |

## Remarks

This interface function helps to transition the input stream to a specified state with a specified media type set on the input stream. This will be used by device transform manager (DTM) when the Device MFT requests a specific input stream’s state and media type to be changed. Device MFT would need to request such a change when one of the Device MFT's output changes.

As an example, consider a Device MFT that has two input streams and three output streams. Let Output 1 and Output 2 source from Input 1 and stream at 720p. Now, if Output 2’s media type changes to 1080p, Device MFT has to change Input 1's media type to 1080p. To achieve this, Device MFT should request DTM to call this method using the [METransformInputStreamStateChanged](https://learn.microsoft.com/windows-hardware/drivers/stream/metransforminputstreamstatechanged) message.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)