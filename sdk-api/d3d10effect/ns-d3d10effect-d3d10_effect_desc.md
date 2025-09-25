# D3D10_EFFECT_DESC structure

## Description

Describes an effect.

## Members

### `IsChildEffect`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the effect is a [child effect](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-effects-performance); otherwise **FALSE**.

### `ConstantBuffers`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of constant buffers.

### `SharedConstantBuffers`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of constant buffers shared in an effect pool.

### `GlobalVariables`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of global variables.

### `SharedGlobalVariables`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of global variables shared in an effect pool.

### `Techniques`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of techniques.

## Remarks

To get an effect description, call [ID3D10Effect::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-getdesc).

## See also

[Effect Structures (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-structures)