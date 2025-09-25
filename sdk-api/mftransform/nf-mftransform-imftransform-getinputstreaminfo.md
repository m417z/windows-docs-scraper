# IMFTransform::GetInputStreamInfo

## Description

Gets the buffer requirements and other information for an input stream on this Media Foundation transform (MFT).

## Parameters

### `dwInputStreamID` [in]

Input stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `pStreamInfo` [out]

Pointer to an [MFT_INPUT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_input_stream_info) structure. The method fills the structure with information about the input stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |

## Remarks

It is valid to call this method before setting the media types. Note that the results of this call can change dynamically after the media type changes and after [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput) is called, so you may need to call this method again after either of these occur.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetInputStreamInfo**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)