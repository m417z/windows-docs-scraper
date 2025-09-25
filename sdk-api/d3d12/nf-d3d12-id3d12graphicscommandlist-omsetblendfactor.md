# ID3D12GraphicsCommandList::OMSetBlendFactor

## Description

Sets the blend factor that modulate values for a pixel shader, render target, or both.

## Parameters

### `BlendFactor` [in, optional]

Type: **const FLOAT[4]**

Array of blend factors, one for each RGBA component.

## Remarks

If you created the blend-state object with [D3D12_BLEND_BLEND_FACTOR](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_blend) or **D3D12_BLEND_INV_BLEND_FACTOR**, then the blending stage uses the non-NULL array of blend factors. Otherwise,the blending stage doesn't use the non-NULL array of blend factors; the runtime stores the blend factors.

If you pass NULL, then the runtime uses or stores a blend factor equal to `{ 1, 1, 1, 1 }`.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)