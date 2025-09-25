# IMFTransform::GetOutputStreamInfo

## Description

Gets the buffer requirements and other information for an output stream on this Media Foundation transform (MFT).

## Parameters

### `dwOutputStreamID` [in]

Output stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `pStreamInfo` [out]

Pointer to an [MFT_OUTPUT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_stream_info) structure. The method fills the structure with information about the output stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream number. |

## Remarks

It is valid to call this method before setting the media types. Note that the results of this call can change dynamically after the media type changes and after [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) is called, so you may need to call this method again after either of these occur.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetOutputStreamInfo**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)