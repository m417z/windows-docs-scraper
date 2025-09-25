# IMFDeviceTransform::GetInputStreamPreferredState

## Description

The **GetInputStreamPreferredState** method gets a Device MFT input stream’s preferred state and media type.

## Parameters

### `dwStreamID` [in]

Stream ID of the input stream whose state needs to be retrieved.

### `value` [out]

Specifies the current **DeviceStreamState** of the specified input Device MFT stream.

### `ppMediaType` [out]

Preferred media type for the input stream is passed in through this parameter.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Transitioning the stream state succeeded. |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVAILIDSTREAMNUMBER** | An invalid stream ID was passed. |
| **MF_E_INVALID_STREAM_STATE** | The requested stream transition is not possible. |

## Remarks

This interface function helps to query the Device MFT input stream’s preferred state and mediatype to which it needs to be transitioned.

When a change in the output stream’s media type needs corresponding change in the input, then Device MFT would post [METransformInputStreamStateChanged](https://learn.microsoft.com/windows-hardware/drivers/stream/metransforminputstreamstatechanged) to DTM to change the relevant input stream. DTM would call **GetInputStreamPreferredState** to retrieve Device MFT input stream’s preferred mediatype and state.

As an example, consider a Device MFT that has two input streams and three output streams. Let Output 1 and Output 2 source from Input 1 and stream at 720p. Now, let us say Output 2’s media type changes to 1080p. To satisfy this request, Device MFT must change the Input 1 media type to 1080p, by posting [METransformInputStreamStateChanged](https://learn.microsoft.com/windows-hardware/drivers/stream/metransforminputstreamstatechanged) event to the DTM. DTM would call **GetInputStreamPreferredState** and retrieve the preferred state and mediatype. DTM would call [SetInputStreamState](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-setinputstreamstate) to change the input stream’ mediatype and state.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)