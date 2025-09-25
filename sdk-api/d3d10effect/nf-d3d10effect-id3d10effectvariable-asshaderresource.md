# ID3D10EffectVariable::AsShaderResource

## Description

Get a shader-resource variable.

## Return value

Type: **[ID3D10EffectShaderResourceVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectshaderresourcevariable)***

A pointer to a shader-resource variable. See [ID3D10EffectShaderResourceVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectshaderresourcevariable).

## Remarks

AsShaderResource returns a version of the effect variable that has been specialized to a shader-resource variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain shader-resource data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)