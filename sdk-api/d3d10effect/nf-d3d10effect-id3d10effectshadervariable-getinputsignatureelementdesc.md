# ID3D10EffectShaderVariable::GetInputSignatureElementDesc

## Description

Get an input-signature description.

## Parameters

### `ShaderIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based shader index.

### `Element` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based shader-element index.

### `pDesc` [in]

Type: **[D3D10_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d10shader/ns-d3d10shader-d3d10_signature_parameter_desc)***

A pointer to a parameter description (see [D3D10_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d10shader/ns-d3d10shader-d3d10_signature_parameter_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

An effect contains one or more shaders; each shader has an input and output signature; each signature contains one or more elements (or parameters). The shader index identifies the shader and the element index identifies the element (or parameter) in the shader signature.

## See also

[ID3D10EffectShaderResourceVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectshaderresourcevariable)

[ID3D10EffectShaderVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectshadervariable)