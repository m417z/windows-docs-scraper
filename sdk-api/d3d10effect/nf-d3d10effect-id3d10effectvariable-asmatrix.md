# ID3D10EffectVariable::AsMatrix

## Description

Get a matrix variable.

## Return value

Type: **[ID3D10EffectMatrixVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectmatrixvariable)***

A pointer to a matrix variable. See [ID3D10EffectMatrixVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectmatrixvariable).

## Remarks

AsMatrix returns a version of the effect variable that has been specialized to a matrix variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain matrix data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)