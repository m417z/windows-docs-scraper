# IDirect3DDevice9::GetGammaRamp

## Description

Retrieves the gamma correction ramp for the swap chain.

## Parameters

### `iSwapChain` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An unsigned integer specifying the swap chain.

### `pRamp` [in, out]

Type: **[D3DGAMMARAMP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dgammaramp)***

Pointer to an application-supplied [D3DGAMMARAMP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dgammaramp) structure to fill with the gamma correction ramp.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetGammaRamp](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setgammaramp)

[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)