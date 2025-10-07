# D3DX10CreateAsyncShaderPreprocessProcessor function

Create a data processor for a shader asynchronously.

## Parameters

*pFileName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A string that contains the shader filename.

*pDefines* \[in\]

Type: **const [**D3D\_SHADER\_MACRO**](https://learn.microsoft.com/windows/win32/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)\***

A NULL-terminated array of shader macros (see [**D3D\_SHADER\_MACRO**](https://learn.microsoft.com/windows/win32/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)); set this to **NULL** to specify no macros.

*pInclude* \[in\]

Type: **[**LPD3D10INCLUDE**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))**

A pointer to an include interface (see [**ID3D10Include Interface**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))); set this to **NULL** to specify there is no include file.

*ppShaderText* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)\*\***

Address of a pointer to a buffer that contains the ASCII text of the shader (see [**ID3D10Blob Interface**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)).

*ppErrorBuffer* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)\*\***

Address of a pointer to a buffer that contains compile errors (see [**ID3D10Blob Interface**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)).

*ppDataProcessor* \[out\]

Type: **[**ID3DX10DataProcessor**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataprocessor)\*\***

Address of a pointer to a buffer that contains the data processor created (see [**ID3DX10DataProcessor Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataprocessor)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX10Async.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

