# ID3D10EffectVariable::AsDepthStencilView

## Description

Get a depth-stencil-view variable.

## Return value

Type: **[ID3D10EffectDepthStencilViewVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectdepthstencilviewvariable)***

A pointer to a depth-stencil-view variable. See [ID3D10EffectDepthStencilViewVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectdepthstencilviewvariable).

## Remarks

This method returns a version of the effect variable that has been specialized to a depth-stencil-view variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain depth-stencil-view data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)