# IMFTransform::AddInputStreams

## Description

Adds one or more new input streams to this Media Foundation transform (MFT).

## Parameters

### `cStreams` [in]

Number of streams to add.

### `adwStreamIDs` [in]

Array of stream identifiers. The new stream identifiers must not match any existing input streams.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOTIMPL** | The MFT has a fixed number of input streams. |

## Remarks

If the new streams exceed the maximum number of input streams for this transform, the method returns **E_INVALIDARG.** To find the maximum number of input streams, call [IMFTransform::GetStreamLimits](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamlimits).

If any of the new stream identifiers conflicts with an existing input stream, the method returns **E_INVALIDARG**.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTAddInputStreams**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)