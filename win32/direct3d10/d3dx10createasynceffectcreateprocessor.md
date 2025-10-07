# D3DX10CreateAsyncEffectCreateProcessor function

Create an effect pool asynchronously.

## Parameters

*pFileName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A string that contains the effect filename.

*pDefines* \[in\]

Type: **const [**D3D\_SHADER\_MACRO**](https://learn.microsoft.com/windows/win32/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)\***

A NULL-terminated array of shader macros (see [**D3D\_SHADER\_MACRO**](https://learn.microsoft.com/windows/win32/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)); set this to **NULL** to specify no macros.

*pInclude* \[in\]

Type: **[**LPD3D10INCLUDE**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))**

A pointer to an include interface (see [**ID3D10Include Interface**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))); set this to **NULL** to specify there is no include file.

*pProfile* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A string that specifies the [shader profile](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-models) or shader model.

*Flags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

HLSL compile options (see [Shader Flags](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-effect-constants)).

*FXFlags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Effect compile options (see [Compile and Effect Flags](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-effect-constants)).

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/win32/api/D3D10/nn-d3d10-id3d10device)\***

A pointer to the device (see [**ID3D10Device Interface**](https://learn.microsoft.com/windows/win32/api/D3D10/nn-d3d10-id3d10device)) that will use the resources.

*pPool* \[in\]

Type: **[**ID3D10EffectPool**](https://learn.microsoft.com/windows/win32/api/D3D10Effect/nn-d3d10effect-id3d10effectpool)\***

A pointer to an effect pool (see [**ID3D10EffectPool Interface**](https://learn.microsoft.com/windows/win32/api/D3D10Effect/nn-d3d10effect-id3d10effectpool)) for sharing variables between effects.

*ppErrorBuffer* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)\*\***

The address of a pointer to memory (see [**ID3D10Blob Interface**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)) that contains effect compile errors, if there were any.

*ppProcessor* \[out\]

Type: **[**ID3DX10DataProcessor**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataprocessor)\*\***

The address of a pointer to the asynchronous-data processor (see [**ID3DX10DataProcessor Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataprocessor)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX10Async.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

