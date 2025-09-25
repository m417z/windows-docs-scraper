# ID3D10EffectVariable::AsRenderTargetView

## Description

Get a render-target-view variable.

## Return value

Type: **[ID3D10EffectRenderTargetViewVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectrendertargetviewvariable)***

A pointer to a render-target-view variable. See [ID3D10EffectRenderTargetViewVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectrendertargetviewvariable).

## Remarks

This method returns a version of the effect variable that has been specialized to a render-target-view variable. Similar to a cast, this specialization will return an invalid object if the effect variable does not contain render-target-view data.

Applications can test the returned object for validity by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)