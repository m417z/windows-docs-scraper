# IMFTransform::GetAttributes

## Description

Gets the global attribute store for this Media Foundation transform (MFT).

## Parameters

### `pAttributes` [out]

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The MFT does not support attributes. |

## Remarks

Use the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) pointer retrieved by this method to get or set attributes that apply to the entire MFT. To get the attribute store for an input stream, call [IMFTransform::GetInputStreamAttributes](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getinputstreamattributes). To get the attribute store for an output stream, call [IMFTransform::GetOutputStreamAttributes](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreamattributes).

Implementation of this method is optional unless the MFT needs to support a particular set of attributes. Exception: Hardware-based MFTs must implement this method. See [Hardware MFTs](https://learn.microsoft.com/windows/desktop/medfound/hardware-mfts).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)

[Transform Attributes](https://learn.microsoft.com/windows/desktop/medfound/transform-attributes)