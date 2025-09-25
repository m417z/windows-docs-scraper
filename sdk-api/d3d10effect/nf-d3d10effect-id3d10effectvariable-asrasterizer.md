# ID3D10EffectVariable::AsRasterizer

## Description

Get a rasterizer variable.

## Return value

Type: **[ID3D10EffectRasterizerVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectrasterizervariable)***

A pointer to a rasterizer variable. See [ID3D10EffectRasterizerVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectrasterizervariable).

## Remarks

AsRasterizer returns a version of the effect variable that has been specialized to a rasterizer variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain rasterizer data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)