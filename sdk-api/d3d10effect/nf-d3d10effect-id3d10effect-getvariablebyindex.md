# ID3D10Effect::GetVariableByIndex

## Description

Get a variable by index.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based index.

## Return value

Type: **[ID3D10EffectVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)***

A pointer to a [ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable).

## Remarks

An effect may contain one or more variables. Variables outside of a technique are considered global to all effects, those located inside of a technique are local to that technique. You can access any local non-static effect variable using its name or with an index.

The method returns a pointer to an [effect-variable interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable) if a variable is not found; you can call [ID3D10Effect::IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-isvalid) to verify whether or not the index exists.

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)