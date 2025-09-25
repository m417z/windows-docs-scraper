## Description

Presents a rendered image to the user.

## Parameters

### `SyncInterval`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An integer that specifies how to synchronize presentation of a frame with the vertical blank.

For the bit-block transfer (bitblt) model ([DXGI_SWAP_EFFECT_DISCARD](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_effect) or [DXGI_SWAP_EFFECT_SEQUENTIAL](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_effect)), values are:

* 0 - The presentation occurs immediately, there is no synchronization.
* 1 through 4 - Synchronize presentation after the *n*th vertical blank.

For the flip model ([DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_effect)), values are:

* 0 - Cancel the remaining time on the previously presented frame and discard this frame if a newer frame is queued.
* 1 through 4 - Synchronize presentation for at least *n* vertical blanks.

For an example that shows how sync-interval values affect a flip presentation queue, see Remarks.

If the update region straddles more than one output (each represented by [IDXGIOutput](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgioutput)), **Present** performs the synchronization to the output that contains the largest sub-rectangle of the target window's client area.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

An integer value that contains swap-chain presentation options. These options are defined by the [DXGI_PRESENT](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) constants.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include: S_OK, DXGI_ERROR_DEVICE_RESET or DXGI_ERROR_DEVICE_REMOVED (see [DXGI_ERROR](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error)), DXGI_STATUS_OCCLUDED (see [DXGI_STATUS](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-status)), or D3DDDIERR_DEVICEREMOVED.

**Note** The **Present** method can return either DXGI_ERROR_DEVICE_REMOVED or D3DDDIERR_DEVICEREMOVED if a video card has been physically removed from the computer, or a driver upgrade for the video card has occurred.

## Remarks

Starting with Direct3D 11.1, consider using [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) because you can then use dirty rectangles and the scroll rectangle in the swap chain presentation and as such use less memory bandwidth and as a result less system power. For more info about using dirty rectangles and the scroll rectangle in swap chain presentation, see [Using dirty rectangles and the scroll rectangle in swap chain presentation](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-1-2-presentation-improvements).

For the best performance when flipping swap-chain buffers in a full-screen application, see [Full-Screen Application Performance Hints](https://learn.microsoft.com/windows/win32/direct3ddxgi/d3d10-graphics-programming-guide-dxgi).

Because calling **Present** might cause the render thread to wait on the message-pump thread, be careful when calling this method in an application that uses multiple threads. For more details, see [Multithreading Considerations](https://learn.microsoft.com/windows/win32/direct3ddxgi/d3d10-graphics-programming-guide-dxgi).

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>Specifying [DXGI_PRESENT_TEST](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-present) in the *Flags* parameter is analogous to [IDirect3DDevice9::TestCooperativeLevel](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-testcooperativelevel) in Direct3D 9. |

For flip presentation model swap chains that you create with the [DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_effect) or **DXGI_SWAP_EFFECT_DISCARD** value set, a successful presentation unbinds back buffer 0 (usually set by [OMSetRenderTargets](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11devicecontext-omsetrendertargets)) from the graphics pipeline, except for when you pass the [DXGI_PRESENT_DO_NOT_SEQUENCE](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-present) flag in the *Flags* parameter.

For info about how data values change when you present content to the screen, see [Converting data for the color space](https://learn.microsoft.com/windows/win32/direct3ddxgi/converting-data-color-space).

### Flip presentation model queue

Suppose the following frames with sync-interval values are queued from oldest (A) to newest (E) before you call **Present**.

A: 3, B: 0, C: 0, D: 1, E: 0

When you call **Present**, the runtime shows frame A for only 1 vertical blank interval. The runtime terminates frame A early because of the sync interval 0 in frame B. Then the runtime shows frame D for 1 vertical blank interval, and then frame E until you submit a new presentation. The runtime discards frames B and C.

### Variable refresh rate displays

It is a requirement of variable refresh rate displays that tearing is enabled. The [CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/dxgi1_5/nf-dxgi1_5-idxgifactory5-checkfeaturesupport) method can be used to determine if this feature is available, and to set the required flags refer to the descriptions of [DXGI_PRESENT_ALLOW_TEARING](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-present) and [DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_chain_flag), and [Variable refresh rate displays](https://learn.microsoft.com/windows/win32/direct3ddxgi/variable-refresh-rate-displays#variable-refresh-rate-displaysvsync-off).

## See also

[IDXGISwapChain](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiswapchain)