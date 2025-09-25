# ID3D11Debug::GetPresentPerRenderOpDelay

## Description

Get the number of milliseconds to sleep after [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present) is called.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of milliseconds to sleep after Present is called.

## Remarks

Value is set with [ID3D11Debug::SetPresentPerRenderOpDelay](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11debug-setpresentperrenderopdelay).

## See also

[ID3D11Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11debug)