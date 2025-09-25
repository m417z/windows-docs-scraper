# D3D10_EFFECT_VARIABLE_DESC structure

## Description

Describes an effect variable.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that contains the variable name.

### `Semantic`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The semantic attached to the variable; otherwise **NULL**.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional [flags](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-constants) for effect variables.

### `Annotations`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of annotations; otherwise 0.

### `BufferOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset between the beginning of the constant buffer and this variable; otherwise 0.

### `ExplicitBindPoint`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The register that this variable is bound to. To bind a variable explicitly use the D3D10_EFFECT_VARIABLE_EXPLICIT_BIND_POINT flag.

## Remarks

To get an effect-variable description, call [ID3D10EffectVariable::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-getdesc).

## See also

[Effect Structures (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-structures)