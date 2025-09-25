# IMFTransform::GetStreamCount

## Description

Gets the current number of input and output streams on this Media Foundation transform (MFT).

## Parameters

### `pcInputStreams` [out]

Receives the number of input streams.

### `pcOutputStreams` [out]

Receives the number of output streams.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The number of streams includes unselected streams—that is, streams with no media type or a **NULL** media type.

This method should not be called with **NULL** parameters, although in practice some implementations may allow **NULL** parameters.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetStreamCount**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)