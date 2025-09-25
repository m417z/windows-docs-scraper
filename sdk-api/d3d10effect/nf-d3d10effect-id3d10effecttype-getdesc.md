# ID3D10EffectType::GetDesc

## Description

Get an effect-type description.

## Parameters

### `pDesc` [in]

Type: **[D3D10_EFFECT_TYPE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_effect_type_desc)***

A pointer to an effect-type description. See [D3D10_EFFECT_TYPE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_effect_type_desc).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

The effect-variable description contains data about the name, annotations, semantic, flags and buffer offset of the effect type.

## See also

[ID3D10EffectType Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effecttype)