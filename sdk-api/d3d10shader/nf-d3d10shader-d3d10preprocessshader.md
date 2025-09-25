# D3D10PreprocessShader function

## Description

Generate a shader-text string that contains the shader tokens that would be found in a compiled shader.

## Parameters

### `pSrcData` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string containing the shader source code.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of pSrcData, in bytes.

### `pFileName` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the file that contains the shader code.

### `pDefines` [in]

Type: **const [D3D10_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)***

Optional. Pointer to an array of macro definitions (see [D3D10_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)).
The last structure in the array serves as a terminator and must have all members set to 0.
If not used, set *pDefines* to **NULL**.

### `pInclude` [in]

Type: **[LPD3D10INCLUDE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))**

Optional. Pointer to an [ID3D10Include Interface](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85)) interface for handling include files. Setting this to **NULL** will cause a compile error if a shader contains a #include.

### `ppShaderText` [out]

Type: **[ID3D10Blob](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)****

A pointer to a buffer that receives a pointer to an [ID3D10Blob Interface](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob) that contains a single string containing shader-tokens.

### `ppErrorMsgs` [out]

Type: **[ID3D10Blob](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)****

A pointer to a buffer that receives a pointer to an [ID3D10Blob Interface](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob) that contains a listing of errors and warnings that occurred during compilation. These errors and warnings are identical to the debug output from a debugger.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Use this function to generate a shader-token stream, which is the compiled output of the shader compiler.

## See also

[Shader Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-functions)