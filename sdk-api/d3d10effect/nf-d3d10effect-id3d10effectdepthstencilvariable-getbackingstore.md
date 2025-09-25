# ID3D10EffectDepthStencilVariable::GetBackingStore

## Description

Get a pointer to a variable that contains depth-stencil state.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into an array of depth-stencil-state descriptions. If there is only one depth-stencil variable in the effect, use 0.

### `pDepthStencilDesc` [in]

Type: **[D3D10_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencil_desc)***

A pointer to a depth-stencil-state description (see [D3D10_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencil_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Effect variables are saved in memory in the backing store; when a technique is applied, the values in the backing store are copied to the device. Backing store data can used to recreate the variable when necessary.

## See also

[ID3D10EffectDepthStencilVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectdepthstencilvariable)