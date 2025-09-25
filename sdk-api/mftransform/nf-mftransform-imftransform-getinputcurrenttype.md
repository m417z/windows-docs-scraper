# IMFTransform::GetInputCurrentType

## Description

Gets the current media type for an input stream on this Media Foundation transform (MFT).

## Parameters

### `dwInputStreamID` [in]

Input stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `ppType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The input media type has not been set. |

## Remarks

If the specified input stream does not yet have a media type, the method returns **MF_E_TRANSFORM_TYPE_NOT_SET**. Most MFTs do not set any default media types when first created. Instead, the client must set the media type by calling [IMFTransform::SetInputType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-setinputtype).

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetInputCurrentType**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

### Implementation Notes

The MFT should return a clone of the media type, not a pointer to the original type. Otherwise, the caller might modify the type and alter the internal state of the MFT.

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)