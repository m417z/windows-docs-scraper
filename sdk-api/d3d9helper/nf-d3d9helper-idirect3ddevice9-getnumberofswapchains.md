# IDirect3DDevice9::GetNumberOfSwapChains

## Description

Gets the number of implicit swap chains.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of implicit swap chains. See Remarks.

## Remarks

Implicit swap chains are created by the device during [IDirect3D9::CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice). This method returns the number of swap chains created by CreateDevice.

An application may create additional swap chains using [IDirect3DDevice9::CreateAdditionalSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createadditionalswapchain).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)