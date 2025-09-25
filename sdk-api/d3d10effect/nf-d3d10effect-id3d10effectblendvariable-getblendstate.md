# ID3D10EffectBlendVariable::GetBlendState

## Description

Get a pointer to a blend-state interface.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into an array of blend-state interfaces. If there is only one blend-state interface, use 0.

### `ppBlendState` [out]

Type: **[ID3D10BlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10blendstate)****

The address of a pointer to a blend-state interface (see [ID3D10BlendState Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10blendstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectBlendVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectblendvariable)