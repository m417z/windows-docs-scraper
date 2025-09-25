# DXGI_SWAP_CHAIN_DESC structure

## Description

Describes a swap chain.

## Members

### `BufferDesc`

Type: **[DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85))**

A [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85)) structure that describes the backbuffer display mode.

### `SampleDesc`

Type: **[DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc)**

A [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure that describes multi-sampling parameters.

### `BufferUsage`

Type: **[DXGI_USAGE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-usage)**

A member of the [DXGI_USAGE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-usage) enumerated type that describes the surface usage and CPU access options for the back buffer. The back buffer can
be used for shader input or render-target output.

### `BufferCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that describes the number of buffers in the swap chain. When you call [IDXGIFactory::CreateSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-createswapchain) to create a full-screen swap chain, you typically include the front buffer in this value. For more information about swap-chain buffers, see Remarks.

### `OutputWindow`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) handle to the output window. This member must not be **NULL**.

### `Windowed`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that specifies whether the output is in windowed mode. **TRUE** if the output is in windowed mode; otherwise, **FALSE**.

We recommend that you create a windowed swap chain and allow the end user to change the swap chain to full screen through [IDXGISwapChain::SetFullscreenState](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-setfullscreenstate); that is, do not set this member to FALSE to force the swap chain to be full screen. However, if you create the swap chain as full screen, also provide the end user with a list of supported display modes through the **BufferDesc** member because a swap chain that is created with an unsupported display mode might cause the display to go black and prevent the end user from seeing anything.

For more information about choosing windowed verses full screen, see [IDXGIFactory::CreateSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-createswapchain).

### `SwapEffect`

Type: **[DXGI_SWAP_EFFECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect)**

A member of the [DXGI_SWAP_EFFECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) enumerated type that describes options for handling the contents of the presentation buffer after
presenting a surface.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A member of the [DXGI_SWAP_CHAIN_FLAG](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag) enumerated type that describes options for swap-chain behavior.

## Remarks

This structure is used by the [GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-getdesc) and [CreateSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-createswapchain) methods.

In full-screen mode, there is a dedicated front buffer; in windowed mode, the desktop is the front buffer.

If you create a swap chain with one buffer, specifying **DXGI_SWAP_EFFECT_SEQUENTIAL** does not cause the contents of the single
buffer to be swapped with the front buffer.

For performance information about flipping swap-chain buffers in full-screen application,
see [Full-Screen Application Performance Hints](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-programming-guide-dxgi).

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)

[IDXGIFactory::CreateSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-createswapchain)

[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)