# ID3D10Debug::GetPresentPerRenderOpDelay

## Description

Get the number of milliseconds to sleep after [Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present) is called.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of milliseconds to sleep after Present is called.

## Remarks

Value is set with [ID3D10Debug::SetPresentPerRenderOpDelay](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10debug-setpresentperrenderopdelay).

## See also

[ID3D10Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10debug)