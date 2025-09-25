# ID3D10EffectVariable::AsShader

## Description

Get a shader variable.

## Return value

Type: **[ID3D10EffectShaderVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectshadervariable)***

A pointer to a shader variable. See [ID3D10EffectShaderVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectshadervariable).

## Remarks

AsShader returns a version of the effect variable that has been specialized to a shader variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain shader data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)