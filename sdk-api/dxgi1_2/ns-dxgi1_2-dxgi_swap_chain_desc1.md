# DXGI_SWAP_CHAIN_DESC1 structure

## Description

Describes a swap chain.

## Members

### `Width`

A value that describes the resolution width. If you specify the width as zero when you call the
[IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd)
method to create a swap chain, the runtime obtains the width from the output window and assigns this width value
to the swap-chain description. You can subsequently call the
[IDXGISwapChain1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getdesc1) method to
retrieve the assigned width value. You cannot specify the width as zero when you call the
[IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition)
method.

### `Height`

A value that describes the resolution height. If you specify the height as zero when you call the
[IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd)
method to create a swap chain, the runtime obtains the height from the output window and assigns this height
value to the swap-chain description. You can subsequently call the
[IDXGISwapChain1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getdesc1) method to
retrieve the assigned height value. You cannot specify the height as zero when you call the
[IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition)
method.

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) structure that describes the
display format.

### `Stereo`

Specifies whether the full-screen display mode or the swap-chain back buffer is stereo.
**TRUE** if stereo; otherwise, **FALSE**. If you specify stereo, you
must also specify a flip-model swap chain (that is, a swap chain that has the
[DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect)
value set in the **SwapEffect** member).

### `SampleDesc`

A [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure that
describes multi-sampling parameters. This member is valid only with bit-block transfer (bitblt) model swap
chains.

### `BufferUsage`

A [DXGI_USAGE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-usage)-typed value that describes the
surface usage and CPU access options for the back buffer. The back buffer can be used for shader input or
render-target output.

### `BufferCount`

A value that describes the number of buffers in the swap chain. When you create a full-screen swap chain,
you typically include the front buffer in this value.

### `Scaling`

A [DXGI_SCALING](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_scaling)-typed value that identifies
resize behavior if the size of the back buffer is not equal to the target output.

### `SwapEffect`

A [DXGI_SWAP_EFFECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect)-typed value
that describes the presentation model that is used by the swap chain and options for handling the contents of
the presentation buffer after presenting a surface. You must specify the
[DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect)
value when you call the
[IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition)
method because this method supports only [flip
presentation model](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-flip-model).

### `AlphaMode`

A [DXGI_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_alpha_mode)-typed value that
identifies the transparency behavior of the swap-chain back buffer.

### `Flags`

A combination of
[DXGI_SWAP_CHAIN_FLAG](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag)-typed values that are
combined by using a bitwise OR operation. The resulting value specifies options for swap-chain behavior.

## Remarks

This structure is used by the [CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd), [CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow), [CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition), [CreateSwapChainForCompositionSurfaceHandle](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgifactorymedia-createswapchainforcompositionsurfacehandle), and [GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getdesc1) methods.

**Note** You cannot cast a
**DXGI_SWAP_CHAIN_DESC1** to a
[DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc) and vice versa. An
application must explicitly use the
[IDXGISwapChain1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getdesc1) method to
retrieve the newer version of the swap-chain description structure.

In full-screen mode, there is a dedicated front buffer; in windowed mode, the desktop is the front buffer.

For a [flip-model](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-flip-model) swap chain (that is, a swap
chain that has the
[DXGI_SWAP_EFFECT_FLIP_DISCARD](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) or
[DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect)
value set in the **SwapEffect** member), you must set the
**Format** member to
[DXGI_FORMAT_R16G16B16A16_FLOAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format),
**DXGI_FORMAT_B8G8R8A8_UNORM**,
**DXGI_FORMAT_R8G8B8A8_UNORM**, or **DXGI_FORMAT_R10G10B10A10_UNORM**; you must set the
**Count** member of the
[DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure that the
**SampleDesc** member specifies to one and the **Quality** member
of **DXGI_SAMPLE_DESC** to zero because multiple
sample antialiasing (MSAA) is not supported; you must set the **BufferCount** member to
from two to sixteen. For more info about flip-model swap chain, see
DXGI Flip Model.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)

[IDXGISwapChain1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getdesc1)