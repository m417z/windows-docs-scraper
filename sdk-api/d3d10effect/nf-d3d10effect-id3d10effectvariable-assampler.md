# ID3D10EffectVariable::AsSampler

## Description

Get a sampler variable.

## Return value

Type: **[ID3D10EffectSamplerVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectsamplervariable)***

A pointer to a sampler variable. See [ID3D10EffectSamplerVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectsamplervariable).

## Remarks

AsSampler returns a version of the effect variable that has been specialized to a sampler variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain sampler data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)