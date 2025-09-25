# ID3D10EffectVariable::AsScalar

## Description

Get a scalar variable.

## Return value

Type: **[ID3D10EffectScalarVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectscalarvariable)***

A pointer to a scalar variable. See [ID3D10EffectScalarVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectscalarvariable).

## Remarks

AsScalar returns a version of the effect variable that has been specialized to a scalar variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain scalar data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)