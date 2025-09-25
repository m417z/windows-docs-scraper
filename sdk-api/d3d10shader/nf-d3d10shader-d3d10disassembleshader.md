# D3D10DisassembleShader function

## Description

This function -- which disassembles a compiled shader into a text string that contains assembly instructions and register assignments -- has been deprecated. Instead, use [D3DDisassemble](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3ddisassemble).

## Parameters

### `pShader` [in]

Type: **const void***

A pointer to the compiled shader.

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of pShader.

### `EnableColorCode` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Include HTML tags in the output to color code the result.

### `pComments` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The comment string at the top of the shader that identifies the shader constants and variables.

### `ppDisassembly` [out]

Type: **[ID3D10Blob](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)****

Address of a buffer which contains the disassembled shader.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Return value

## See also

[Shader Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-functions)