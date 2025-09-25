## Description

Used with [IDXGIFactoryMedia::CreateDecodeSwapChainForCompositionSurfaceHandle](https://learn.microsoft.com/windows/win32/api/dxgi1_3/nf-dxgi1_3-idxgifactorymedia-createdecodeswapchainforcompositionsurfacehandle) to describe a decode swap chain.

## Members

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

Can be 0, or a combination of **DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO** and/or **DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO**. Those named values are members of the [DXGI_SWAP_CHAIN_FLAG](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_chain_flag) enumerated type, and you can combine them by using a bitwise OR operation. The resulting value specifies options for decode swap-chain behavior.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/win32/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)