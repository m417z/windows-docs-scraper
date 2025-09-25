# ID3D10Effect::GetTechniqueByIndex

## Description

Get a technique by index.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based index.

## Return value

Type: **[ID3D10EffectTechnique](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effecttechnique)***

A pointer to an [ID3D10EffectTechnique Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effecttechnique).

## Remarks

An effect contains one or more techniques; each technique contains one or more passes. You can access a technique using its name or with an index.
For more about techniques, see [techniques and passes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-effects-organize).

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)