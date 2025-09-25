# ID3D10EffectVariable::AsDepthStencil

## Description

Get a depth-stencil variable.

## Return value

Type: **[ID3D10EffectDepthStencilVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectdepthstencilvariable)***

A pointer to a depth-stencil variable. See [ID3D10EffectDepthStencilVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectdepthstencilvariable).

## Remarks

AsDepthStencil returns a version of the effect variable that has been specialized to a depth-stencil variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain depth-stencil data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)