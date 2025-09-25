# IMFDeviceTransform::SetOutputStreamState

## Description

The **SetOutputStreamState** method sets the Device MFT output stream state and media type.

## Parameters

### `dwStreamID` [in]

Stream ID of the input stream where the state and media type needs to be changed.

### `pMediaType` [in]

Preferred media type for the input stream is passed in through this parameter. Device MFT should change the media type only if the incoming media type is different from the current media type.

### `value` [in]

Specifies the **DeviceStreamState** which the input stream should transition to.

### `dwFlags` [in]

Must be zero.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Transitioning the stream state succeeded. |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVAILIDSTREAMNUMBER** | An invalid stream ID was passed. |
| **MF_E_INVALID_STREAM_STATE** | The requested stream transition is not possible. |

## Remarks

This interface method helps to transition the output stream to a specified state with specified media type set on the output stream. This will be used by the DTM when the Device Source requests a specific output stream’s state and media type to be changed. Device MFT should change the specified output stream’s media type and state to the requested media type.

If the incoming media type and stream state are same as the current media type and stream state the method return **S_OK**.

If the incoming media type and current media type of the stream are the same, Device MFT must change the stream’s state to the requested value and return the appropriate **HRESULT**.

When a change in the output stream’s media type requires a corresponding change in the input then Device MFT must post the [METransformInputStreamStateChanged](https://learn.microsoft.com/windows-hardware/drivers/stream/metransforminputstreamstatechanged) event to DTM to change the relevant input stream. The call must return only after changing the input stream’s media type and the appropriate **HRESULT**.

As an example, consider a Device MFT that has two input streams and three output streams. Let Output 1 and Output 2 source from Input 1 and stream at 720p. Now, let us say Output 2’s media type changes to 1080p. To satisfy this request, Device MFT must change the Input 1 media type to 1080p, by posting [METransformInputStreamStateChanged](https://learn.microsoft.com/windows-hardware/drivers/stream/metransforminputstreamstatechanged) event to the DTM. DTM would call [SetInputStreamState](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-setinputstreamstate) to change the input stream’ media type and state. After this call, the **SetOutputStreamState** must return.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)