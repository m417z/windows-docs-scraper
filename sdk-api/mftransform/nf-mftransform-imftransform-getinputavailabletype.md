# IMFTransform::GetInputAvailableType

## Description

Gets an available media type for an input stream on this Media Foundation transform (MFT).

## Parameters

### `dwInputStreamID` [in]

Input stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `dwTypeIndex` [in]

Index of the media type to retrieve. Media types are indexed from zero and returned in approximate order of preference.

### `ppType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The MFT does not have a list of available input types. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |
| **MF_E_NO_MORE_TYPES** | The *dwTypeIndex* parameter is out of range. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | You must set the output types before setting the input types. |

## Remarks

The MFT defines a list of available media types for each input stream and orders them by preference. This method enumerates the available media types for an input stream. To enumerate the available types, increment *dwTypeIndex* until the method returns **MF_E_NO_MORE_TYPES**.

Setting the media type on one stream might change the available types for another stream, or change the preference order. However, an MFT is not required to update the list of available types dynamically. The only guaranteed way to test whether you can set a particular input type is to call [IMFTransform::SetInputType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-setinputtype).

In some cases, an MFT cannot return a list of input types until one or more output types are set. If so, the method returns **MF_E_TRANSFORM_TYPE_NOT_SET**.

An MFT is not required to implement this method. However, most MFTs should implement this method, unless the supported types are simple and can be discovered through the [MFTGetInfo](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftgetinfo) function.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetInputAvailableType**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

For encoders, after the output type is set, **GetInputAvailableType** must return a list of input types that are compatible with the current output type. This means that all types returned by **GetInputAvailableType** after the output type is set must be valid types for [SetInputType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-setinputtype).

Encoders should reject input types if the attributes of the input media type and output media type do not match, such as resolution setting with [MF_MT_FRAME_SIZE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-size-attribute), nominal range setting with [MF_MT_VIDEO_NOMINAL_RANGE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-nominal-range-attribute), or frame rate setting with MF_MT_FRAME_SIZE

### Implementation Notes

If the MFT stores a media type internally, the MFT should return a clone of the media type, not a pointer to the original type. Otherwise, the caller might modify the type and alter the internal state of the MFT.

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)