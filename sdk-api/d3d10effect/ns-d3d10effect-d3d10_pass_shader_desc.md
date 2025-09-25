# D3D10_PASS_SHADER_DESC structure

## Description

Describes an effect variable that contains a shader.

## Members

### `pShaderVariable`

Type: **[ID3D10EffectShaderVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectshadervariable)***

A pointer to the variable that the shader came from. If it is an inline shader assignment, the returned interface will be an anonymous shader variable, which is not retrievable any other way. Its name in the variable description will be "$Anonymous". If there is no assignment of this type in the pass block, this will point to a shader variable that returns false when IsValid is called.

### `ShaderIndex`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based array index; otherwise 0.

## Remarks

To get a shader description, call a method like [ID3D10EffectPass::GetVertexShaderDesc](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectpass-getvertexshaderdesc).

## See also

[Effect Structures (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-structures)