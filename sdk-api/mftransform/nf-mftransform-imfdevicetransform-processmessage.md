# IMFDeviceTransform::ProcessMessage

## Description

The **ProcessMessage** method sends a message to the Device Media Foundation transform (MFT).

## Parameters

### `eMessage` [in]

The message to send, specified as a member of the [MFT_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/mftransform/ne-mftransform-mft_message_type) enumeration.

### `ulParam` [in]

Message parameter. The meaning of this parameter depends on the message type.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | Invalid argument passed. |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVAILIDSTREAMNUMBER** | An invalid stream ID was passed. |
| **MF_E_INVALID_STREAM_STATE** | The requested stream transition is not possible. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | Input media type has not been set. |

## Remarks

Before calling this method, set the media types on all input and output streams.

The MFT might ignore certain message types. If so, the method returns **S_OK**. An error code indicates that the transform handles this message type but was unable to process the message in this instance.

For more information, see [MFT_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/mftransform/ne-mftransform-mft_message_type).

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)