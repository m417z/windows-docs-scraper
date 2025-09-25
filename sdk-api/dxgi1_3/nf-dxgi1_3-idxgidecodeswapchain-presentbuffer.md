# IDXGIDecodeSwapChain::PresentBuffer

## Description

Presents a frame on the output adapter. The frame is a subresource of the [IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource) object that was used to create the decode swap chain.

## Parameters

### `BufferToPresent`

An index indicating which member of the subresource array to present.

### `SyncInterval`

An integer that specifies how to synchronize presentation of a frame with the vertical blank.

For the bit-block transfer (bitblt) model ([DXGI_SWAP_EFFECT_DISCARD](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) or [DXGI_SWAP_EFFECT_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect)), values are:

* 0 - The presentation occurs immediately, there is no synchronization.
* 1,2,3,4 - Synchronize presentation after the *n*th vertical blank.

For the flip model ([DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect)), values are:

* 0 - Cancel the remaining time on the previously presented frame and discard this frame if a newer frame is queued.
* n > 0 - Synchronize presentation for at least *n* vertical blanks.

### `Flags`

An integer value that contains swap-chain presentation options. These options are defined by the [DXGI_PRESENT](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) constants.

The **DXGI_PRESENT_USE_DURATION** flag must be set if a custom present duration (custom refresh rate) is being used.

## Return value

This method returns **S_OK** on success, or it returns one of the following error codes:

* [DXGI_ERROR_DEVICE_REMOVED](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error)
* [DXGI_STATUS_OCCLUDED](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-status)
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error)
* **E_OUTOFMEMORY**

## See also

[IDXGIDecodeSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgidecodeswapchain)