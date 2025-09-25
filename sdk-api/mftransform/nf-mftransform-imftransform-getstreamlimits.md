# IMFTransform::GetStreamLimits

## Description

Gets the minimum and maximum number of input and output streams for this Media Foundation transform (MFT).

## Parameters

### `pdwInputMinimum` [out]

Receives the minimum number of input streams.

### `pdwInputMaximum` [out]

Receives the maximum number of input streams. If there is no maximum, receives the value **MFT_STREAMS_UNLIMITED**.

### `pdwOutputMinimum` [out]

Receives the minimum number of output streams.

### `pdwOutputMaximum` [out]

Receives the maximum number of output streams. If there is no maximum, receives the value **MFT_STREAMS_UNLIMITED**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the MFT has a fixed number of streams, the minimum and maximum values are the same.

It is not recommended to create an MFT that supports zero inputs or zero outputs. An MFT with no inputs or no outputs may not be compatible with the rest of the Media Foundation pipeline. You should create a Media Foundation sink or source for this purpose instead.

When an MFT is first created, it is not guaranteed to have the minimum number of streams. To find the actual number of streams, call [IMFTransform::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamcount).

This method should not be called with **NULL** parameters, although in practice some implementations may allow **NULL** parameters.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetStreamLimits**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)