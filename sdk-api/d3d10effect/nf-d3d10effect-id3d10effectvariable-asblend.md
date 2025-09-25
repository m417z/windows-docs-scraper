# ID3D10EffectVariable::AsBlend

## Description

Get a effect-blend variable.

## Return value

Type: **[ID3D10EffectBlendVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectblendvariable)***

A pointer to an effect blend variable. See [ID3D10EffectBlendVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectblendvariable).

## Remarks

AsBlend returns a version of the effect variable that has been specialized to an effect-blend variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain effect-blend data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)