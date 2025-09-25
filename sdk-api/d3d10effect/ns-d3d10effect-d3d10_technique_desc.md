# D3D10_TECHNIQUE_DESC structure

## Description

Describes an effect technique.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that contains the technique name; otherwise **NULL**.

### `Passes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of passes in the technique.

### `Annotations`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of annotations.

## Remarks

To get a technique, call [ID3D10EffectTechnique::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effecttechnique-getdesc).

## See also

[Effect Structures (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-structures)