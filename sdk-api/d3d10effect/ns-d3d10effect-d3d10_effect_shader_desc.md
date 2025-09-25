# D3D10_EFFECT_SHADER_DESC structure

## Description

Describes an effect shader.

## Members

### `pInputSignature`

Type: **const [BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Passed into CreateInputLayout. Only valid on a vertex shader or geometry shader. See [ID3D10Device_CreateInputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createinputlayout).

### `IsInline`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** is the shader is defined inline; otherwise **FALSE**.

### `pBytecode`

Type: **const [BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the compiled shader.

### `BytecodeLength`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The length of pBytecode.

### `SODecl`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that contains a declaration of the [stream output](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-pipeline-stages)  from a geometry shader.

### `NumInputSignatureEntries`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of entries in the input signature.

### `NumOutputSignatureEntries`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of entries in the output signature.

## Remarks

To get an effect-shader description, call [ID3D10EffectShaderVariable::GetShaderDesc](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectshadervariable-getshaderdesc).

## See also

[Effect Structures (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-structures)