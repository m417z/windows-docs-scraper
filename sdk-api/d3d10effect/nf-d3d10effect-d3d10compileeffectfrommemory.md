# D3D10CompileEffectFromMemory function

## Description

Compile an effect.

**Note** Use [D3DX10CompileFromMemory](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10compilefrommemory) instead of this function.

## Parameters

### `pData` [in]

Type: **void***

A pointer to effect data; either ASCII [HLSL](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-reference) code or a compiled effect.

### `DataLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of *pData*.

### `pSrcFileName` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the effect file.

### `pDefines` [in]

Type: **const [D3D10_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)***

Optional. An array of NULL-terminated macro definitions (see [D3D10_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)).

### `pInclude` [in]

Type: **[ID3D10Include](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))***

Optional. A pointer to an [ID3D10Include Interface](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85)) for handling include files. Setting this to **NULL** will cause a compile error if a shader contains a #include.

### `HLSLFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shader [compile options](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-shader).

### `FXFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Effect [compile options](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-constants).

### `ppCompiledEffect` [out]

Type: **[ID3D10Blob](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)****

The address of a [ID3D10Blob Interface](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob) that contains the compiled effect.

### `ppErrors` [out]

Type: **[ID3D10Blob](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)****

Optional. A pointer to an [ID3D10Blob Interface](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob) that contains compiler error messages, or **NULL** if there were no errors.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This function uses the version of the HLSL compiler released in the November 2006 DirectX SDK.

For an example, see [Compile an Effect (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-effects-compile).

## See also

[Effect Functions (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-functions)