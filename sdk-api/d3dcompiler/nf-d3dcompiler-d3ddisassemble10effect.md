# D3DDisassemble10Effect function

## Description

Disassembles compiled HLSL code from a Direct3D10 effect.

## Parameters

### `pEffect` [in]

Type: **[ID3D10Effect](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)***

A pointer to source data as compiled HLSL code.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shader [compile options](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-shader).

### `ppDisassembly` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a buffer that receives the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that contains disassembly text.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)