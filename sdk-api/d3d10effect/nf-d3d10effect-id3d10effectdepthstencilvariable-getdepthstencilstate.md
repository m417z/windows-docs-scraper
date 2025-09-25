# ID3D10EffectDepthStencilVariable::GetDepthStencilState

## Description

Get a pointer to a depth-stencil interface.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into an array of depth-stencil interfaces. If there is only one depth-stencil interface, use 0.

### `ppDepthStencilState` [out]

Type: **[ID3D10DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilstate)****

The address of a pointer to a blend-state interface (see [ID3D10DepthStencilState Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectDepthStencilVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectdepthstencilvariable)