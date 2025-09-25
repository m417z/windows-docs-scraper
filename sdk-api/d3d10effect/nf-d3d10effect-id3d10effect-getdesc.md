# ID3D10Effect::GetDesc

## Description

Get an effect description.

## Parameters

### `pDesc` [in, out]

Type: **[D3D10_EFFECT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_effect_desc)***

A pointer to an effect description (see [D3D10_EFFECT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_effect_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

An effect description contains basic information about an effect such as the techniques it contains and the constant buffer resources it requires.

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)