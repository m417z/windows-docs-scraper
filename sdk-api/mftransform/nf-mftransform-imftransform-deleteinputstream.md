# IMFTransform::DeleteInputStream

## Description

Removes an input stream from this Media Foundation transform (MFT).

## Parameters

### `dwStreamID` [in]

Identifier of the input stream to remove.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The transform has a fixed number of input streams. |
| **MF_E_INVALIDREQUEST** | The stream is not removable, or the transform currently has the minimum number of input streams it can support. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |
| **MF_E_TRANSFORM_INPUT_REMAINING** | The transform has unprocessed input buffers for the specified stream. |

## Remarks

If the transform has a fixed number of input streams, the method returns **E_NOTIMPL**.

An MFT might support this method but not allow certain input streams to be removed. If an input stream can be removed, the [IMFTransform::GetInputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getinputstreaminfo) method returns the **MFT_INPUT_STREAM_REMOVABLE** flag for that stream. Otherwise, the stream cannot be removed, and the method returns **MF_E_INVALIDREQUEST**. The method also fails if the MFT currently has the minimum number of input streams that it requires. To find the minimum number of streams, call [IMFTransform::GetStreamLimits](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamlimits).

If the transform still has unprocessed input for that stream, the method might succeed or it might return **MF_E_TRANSFORM_INPUT_REMAINING**. If the method succeeds, the MFT will continue to process the remaining input after the stream is removed. If the method returns **MF_E_TRANSFORM_INPUT_REMAINING**, you must clear the input buffers before removing the stream. To clear the input buffers, either call [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) or else call [IMFTransform::ProcessMessage](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processmessage) with the **MFT_MESSAGE_COMMAND_FLUSH** to flush the MFT. Then call the **DeleteInputStream** again. An MFT should never discard input buffers when **DeleteInputStream** is called.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTDeleteInputStream**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)