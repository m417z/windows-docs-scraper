# IMFTransform::GetOutputAvailableType

## Description

Gets an available media type for an output stream on this Media Foundation transform (MFT).

## Parameters

### `dwOutputStreamID` [in]

Output stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `dwTypeIndex` [in]

Index of the media type to retrieve. Media types are indexed from zero and returned in approximate order of preference.

### `ppType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The MFT does not have a list of available output types. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |
| **MF_E_NO_MORE_TYPES** | The *dwTypeIndex* parameter is out of range. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | You must set the input types before setting the output types. |

## Remarks

The MFT defines a list of available media types for each output stream and orders them by preference. This method enumerates the available media types for an output stream. To enumerate the available types, increment *dwTypeIndex* until the method returns MF_**E_NO_MORE_TYPES**.

Setting the media type on one stream can change the available types for another stream (or change the preference order). However, an MFT is not required to update the list of available types dynamically. The only guaranteed way to test whether you can set a particular input type is to call [IMFTransform::SetOutputType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-setoutputtype).

In some cases, an MFT cannot return a list of output types until one or more input types are set. If so, the method returns **MF_E_TRANSFORM_TYPE_NOT_SET**.

An MFT is not required to implement this method. However, most MFTs should implement this method, unless the supported types are simple and can be discovered through the [MFTGetInfo](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftgetinfo) function.

This method can return a *partial* media type. A partial media type contains an incomplete description of a format, and is used to provide a hint to the caller. For example, a partial type might include just the major type and subtype GUIDs. However, after the client sets the input types on the MFT, the MFT should generally return at least one complete output type, which can be used without further modification.
For more information, see [Complete and Partial Media Types](https://learn.microsoft.com/windows/desktop/medfound/complete-and-partial-media-types).

Some MFTs cannot provide an accurate list of output types until the MFT receives the first input sample. For example, the MFT might need to read the first packet header to deduce the format. An MFT should handle this situation as follows:

1. Before the MFT receives any input, it offers a list of one or more output types that it could possibly produce. For example, an MPEG-2 decoder might return a media type that describes the MPEG-2 main profile/main level.
2. The client selects one of these types (generally the first) and sets it on the output stream.
3. The client delivers the first input sample by calling [IMFTransform::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput).
4. If the output type does not conform to the input data, the transform signals a format change in the [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method. For more information about format changes, see [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).
5. The calls **GetOutputAvailableType** again. At this point, the method should return an updated list of types that reflects the input data.
6. The client selects a new output type from this list and calls [SetOutputType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-setoutputtype).

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetOutputAvailableType**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

### Implementation Notes

If the MFT stores a media type internally, the MFT should return a clone of the media type, not a pointer to the original type. Otherwise, the caller might modify the type and alter the internal state of the MFT.

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)