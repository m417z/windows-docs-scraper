# ID3D10EffectVariable::AsString

## Description

Get a string variable.

## Return value

Type: **[ID3D10EffectStringVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectstringvariable)***

A pointer to a string variable. See [ID3D10EffectStringVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectstringvariable).

## Remarks

AsString returns a version of the effect variable that has been specialized to a string variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain string data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)