# ID3D10EffectPass::GetDesc

## Description

Get a pass description.

## Parameters

### `pDesc` [in]

Type: **[D3D10_PASS_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_pass_desc)***

A pointer to a pass description (see [D3D10_PASS_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_pass_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

A pass is a block of code that sets render state and shaders (which in turn sets constant buffers, samplers and textures). An effect technique contains one or more passes. See [techniques and passes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-effects-organize).

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)

[ID3D10EffectPass](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectpass)