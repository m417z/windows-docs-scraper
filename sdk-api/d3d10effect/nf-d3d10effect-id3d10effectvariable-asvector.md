# ID3D10EffectVariable::AsVector

## Description

Get a vector variable.

## Return value

Type: **[ID3D10EffectVectorVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvectorvariable)***

A pointer to a vector variable. See [ID3D10EffectVectorVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvectorvariable).

## Remarks

AsVector returns a version of the effect variable that has been specialized to a vector variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain vector data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)