# IMFTransform::GetOutputStreamAttributes

## Description

Gets the attribute store for an output stream on this Media Foundation transform (MFT).

## Parameters

### `dwOutputStreamID` [in]

Output stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `pAttributes` [out]

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The MFT does not support output stream attributes. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |

## Remarks

Implementation of this method is optional unless the MFT needs to support a particular set of attributes.

To get the attribute store for the entire MFT, call [IMFTransform::GetAttributes](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getattributes).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)

[Transform Attributes](https://learn.microsoft.com/windows/desktop/medfound/transform-attributes)