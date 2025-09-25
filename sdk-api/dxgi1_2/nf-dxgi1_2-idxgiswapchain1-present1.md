# IDXGISwapChain1::Present1

## Description

Presents a frame on the display screen.

## Parameters

### `SyncInterval`

An integer that specifies how to synchronize presentation of a frame with the vertical blank.

For the bit-block transfer (bitblt) model ([DXGI_SWAP_EFFECT_DISCARD](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) or [DXGI_SWAP_EFFECT_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect)), values are:

* 0 - The presentation occurs immediately, there is no synchronization.
* 1 through 4 - Synchronize presentation after the *n*th vertical blank.

For the flip model ([DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect)), values are:

* 0 - Cancel the remaining time on the previously presented frame and discard this frame if a newer frame is queued.
* 1 through 4 - Synchronize presentation for at least *n* vertical blanks.

For an example that shows how sync-interval values affect a flip presentation queue, see Remarks.

If the update region straddles more than one output (each represented by [IDXGIOutput1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutput1)), **Present1** performs the synchronization to the output that contains the largest sub-rectangle of the target window's client area.

### `PresentFlags`

An integer value that contains swap-chain presentation options. These options are defined by the [DXGI_PRESENT](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) constants.

### `pPresentParameters` [in]

A pointer to a [DXGI_PRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_present_parameters) structure that describes updated rectangles and scroll information of the frame to present.

## Return value

Possible return values include: S_OK, [DXGI_ERROR_DEVICE_REMOVED](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) , [DXGI_STATUS_OCCLUDED](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-status), [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error), or E_OUTOFMEMORY.

## Remarks

An app can use **Present1** to optimize presentation by specifying scroll and dirty rectangles. When the runtime has information about these rectangles, the runtime can then perform necessary bitblts during presentation more efficiently and pass this metadata to the Desktop Window Manager (DWM). The DWM can then use the metadata to optimize presentation and pass the metadata to indirect displays and terminal servers to optimize traffic over the wire. An app must confine its modifications to only the dirty regions that it passes to **Present1**, as well as modify the entire dirty region to avoid undefined resource contents from being exposed.

For flip presentation model swap chains that you create with the [DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) value set, a successful presentation results in an unbind of back buffer 0 from the graphics pipeline, except for when you pass the [DXGI_PRESENT_DO_NOT_SEQUENCE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) flag in the *Flags* parameter.

For info about how data values change when you present content to the screen, see [Converting data for the color space](https://learn.microsoft.com/windows/desktop/direct3ddxgi/converting-data-color-space).

For info about calling **Present1** when your app uses multiple threads, see [Multithread Considerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-programming-guide-dxgi) and [Multithreading and DXGI](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-intro).

### Flip presentation model queue

Suppose the following frames with sync-interval values are queued from oldest (A) to newest (E) before you call **Present1**.

A: 3, B: 0, C: 0, D: 1, E: 0

When you call **Present1**, the runtime shows frame A for only 1 vertical blank interval. The runtime terminates frame A early because of the sync interval 0 in frame B. Then the runtime shows frame D for 1 vertical blank interval, and then frame E until you submit a new presentation. The runtime discards frames B and C.

### Variable refresh rate displays

It is a requirement of variable refresh rate displays that tearing is enabled. The [CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgifactory5-checkfeaturesupport) method can be used to determine if this feature is available, and to set the required flags refer to the descriptions of [DXGI_PRESENT_ALLOW_TEARING](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) and [DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag), and the **Variable refresh rate displays/Vsync off** section of [DXGI 1.5 Improvements](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-1-5-improvements).

## See also

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)

[Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present)