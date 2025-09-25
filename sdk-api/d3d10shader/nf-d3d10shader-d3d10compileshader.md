# D3D10CompileShader function

## Description

Compile an [HLSL](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-reference) shader.

**Note** Use [D3DX10CompileFromMemory](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10compilefrommemory) instead of this function.

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

Type: **[LPD3D10INCLUDE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))***

Optional. Pointer to an [ID3D10Include Interface](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85)) interface for handling include files. Setting this to **NULL** will cause a compile error if a shader contains a #include.

### `pFunctionName` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the shader-entry point function where shader execution begins.

### `pProfile` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that specifies the [shader profile](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-models) or shader model.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shader [compile options](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-shader).

### `ppShader` [out]

Type: **[ID3D10Blob](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)****

A pointer to an [ID3D10Blob Interface](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob) that contains the compiled shader, as well as any embedded debug and symbol-table information.

### `ppErrorMsgs` [out]

Type: **[ID3D10Blob](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)****

A pointer to an [ID3D10Blob Interface](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob) that contains a listing of errors and warnings that occurred during compilation. These errors and warnings are identical to the debug output from a debugger.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This function uses the version of the HLSL compiler released in the November 2006 DirectX SDK.

This function implements two ways to supply the input shader information. Either use *pSrcData* and *SrcDataLen* to specify a string that contains the shader HLSL code (and set *pFileName* to **NULL**) or use *pFileName* to specify the name of a shader or effect file (and set *pSrcData* to **NULL**).

To setup a programmable-pipeline stage, compile a shader and then bind the shader to the appropriate pipeline stage. For instance, here is an example compiling a geometry shader (see [Compile a Geometry Shader](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-stream-stage-getting-started)).

This function, D3D10CompileShader, calls the version of the shader compiler that is shipped each time the operating system releases. A more up-to-date version of the shader compiler ships when the DirectX SDK ships, which can be accessed from D3DX by calling a version of the shader compiler entry-point function such as [D3DX10CompileFromFile](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10compilefromfile). It is preferable to use the D3DX entry-point functions to ensure the latest version of the shader compiler will be used if you will be redistributing the DirectX redistributable libraries.

## See also

[Shader Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-functions)