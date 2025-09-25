# ID3D10EffectVariable::AsConstantBuffer

## Description

Get a constant buffer.

## Return value

Type: **[ID3D10EffectConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectconstantbuffer)***

A pointer to a constant buffer. See [ID3D10EffectConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectconstantbuffer).

## Remarks

AsConstantBuffer returns a version of the effect variable that has been specialized to a constant buffer. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain constant buffer data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)