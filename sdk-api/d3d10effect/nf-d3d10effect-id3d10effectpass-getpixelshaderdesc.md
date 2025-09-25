# ID3D10EffectPass::GetPixelShaderDesc

## Description

Get a pixel-shader description.

## Parameters

### `pDesc` [in]

Type: **[D3D10_PASS_SHADER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_pass_shader_desc)***

A pointer to a pixel-shader description (see [D3D10_PASS_SHADER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_pass_shader_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

An effect pass can contain render state assignments and shader object assignments.

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)

[ID3D10EffectPass](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectpass)