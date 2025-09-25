# D3D10_PASS_DESC structure

## Description

Describes an effect pass, which contains pipeline state.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that contains the name of the pass; otherwise **NULL**.

### `Annotations`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of annotations.

### `pIAInputSignature`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the input signature or the vertex shader; otherwise **NULL**.

### `IAInputSignatureSize`

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the input signature (in bytes).

### `StencilRef`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The stencil-reference value used in the depth-stencil state (see [Configuring Depth-Stencil Functionality (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-depth-stencil)).

### `SampleMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The sample mask for the blend state (see [Configuring Blending Functionality (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state)).

### `BlendFactor`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The per-component blend factors (RGBA) for the blend state (see [Configuring Blending Functionality (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state)).

## Remarks

Get a pass description by calling [ID3D10EffectPass::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectpass-getdesc); an effect technique contains one or more passes.

## See also

[Effect Structures (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-structures)