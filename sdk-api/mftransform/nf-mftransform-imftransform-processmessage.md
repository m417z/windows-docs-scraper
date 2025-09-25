# IMFTransform::ProcessMessage

## Description

Sends a message to the Media Foundation transform (MFT).

## Parameters

### `eMessage` [in]

The message to send, specified as a member of the [MFT_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/mftransform/ne-mftransform-mft_message_type) enumeration.

### `ulParam` [in]

Message parameter. The meaning of this parameter depends on the message type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream number. Applies to the **MFT_MESSAGE_NOTIFY_END_OF_STREAM** message. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type is not set on one or more streams. |

## Remarks

Each message type has a different requirement for calling order, see the [MFT_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/mftransform/ne-mftransform-mft_message_type) enumeration for more details.

The MFT might ignore certain message types. If so, the method returns **S_OK**. An error code indicates that the transform handles this message type but was unable to process the message in this instance.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTProcessMessage**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)