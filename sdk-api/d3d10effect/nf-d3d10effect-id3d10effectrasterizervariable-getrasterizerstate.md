# ID3D10EffectRasterizerVariable::GetRasterizerState

## Description

Get a pointer to a rasterizer interface.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into an array of rasterizer interfaces. If there is only one rasterizer interface, use 0.

### `ppRasterizerState` [out]

Type: **[ID3D10RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rasterizerstate)****

The address of a pointer to a rasterizer interface (see [ID3D10RasterizerState Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rasterizerstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectRasterizerVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectrasterizervariable)