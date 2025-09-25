# IMFTransform::SetOutputType

## Description

Sets, tests, or clears the media type for an output stream on this Media Foundation transform (MFT).

## Parameters

### `dwOutputStreamID` [in]

Output stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `pType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface, or **NULL**.

### `dwFlags` [in]

Zero or more flags from the [_MFT_SET_TYPE_FLAGS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_set_type_flags) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDMEDIATYPE** | The transform cannot use the proposed media type. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |
| **MF_E_INVALIDTYPE** | The proposed type is not valid. This error code indicates that the media type itself is not configured correctly; for example, it might contain mutually contradictory flags. |
| **MF_E_TRANSFORM_CANNOT_CHANGE_MEDIATYPE_WHILE_PROCESSING** | The MFT cannot switch types while processing data. Try draining or flushing the MFT. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | You must set the input types before setting the output types. |
| **MF_E_UNSUPPORTED_D3D_TYPE** | The MFT could not find a suitable DirectX Video Acceleration (DXVA) configuration. |

## Remarks

This method can be used to set, test without setting, or clear the media type:

* To set the media type, set *dwFlags* to zero and set *pType* to a non-**NULL** pointer that specifies the media type.
* To test the media type without setting it, set *dwFlags* to **MFT_SET_TYPE_TEST_ONLY** and set *pType* to a non-**NULL** pointer that specifies the media type. If the media type is acceptable, the method return **S_OK**. Otherwise, it returns **MF_E_INVALIDMEDIATYPE**. Regardless of the return value, the current media type does not change.
* To clear the media type, set *pType* to **NULL**.

Setting the media type on one stream may change the acceptable types on another stream.

An MFT may require the caller to set one or more input types before setting the output type. If so, the method returns **MF_E_TRANSFORM_TYPE_NOT_SET**.

If the MFT supports DirectX Video Acceleration (DXVA) but is unable to find a suitable DXVA configuration (for example, if the graphics driver does not have the right capabilities), the method should return **MF_E_UNSUPPORTED_D3D_TYPE**. For more information, see [Supporting DXVA 2.0 in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/supporting-dxva-2-0-in-media-foundation).

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTSetOutputType**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)