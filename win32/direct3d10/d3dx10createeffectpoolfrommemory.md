# D3DX10CreateEffectPoolFromMemory function

Create an effect pool from an effect in memory.

## Parameters

*pData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A pointer to the effect.

*DataLength* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the effect.

*pSrcFileName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The name of the effect file.

*pDefines* \[in\]

Type: **const [**D3D\_SHADER\_MACRO**](https://learn.microsoft.com/windows/win32/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)\***

A NULL-terminated array of shader macros (see [**D3D\_SHADER\_MACRO**](https://learn.microsoft.com/windows/win32/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)); set this to **NULL** to specify no macros.

*pInclude* \[in\]

Type: **[**ID3D10Include**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))\***

A pointer to an include interface (see [**ID3D10Include Interface**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))). This parameter can be **NULL**.

*pProfile* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A string that specifies the [shader profile](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-models), or shader model.

*HLSLFlags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

HLSL compile options (see [D3D10\_SHADER Constants](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-shader)).

*FXFlags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Effect compile options (see [Compile and Effect Flags](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-effect-constants)).

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/win32/api/D3D10/nn-d3d10-id3d10device)\***

A pointer to the device (see [**ID3D10Device Interface**](https://learn.microsoft.com/windows/win32/api/D3D10/nn-d3d10-id3d10device)) that will use the resources.

*pPump* \[in\]

Type: **[**ID3DX10ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump)\***

A pointer to a thread pump interface (see [**ID3DX10ThreadPump Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump)). Use **NULL** to specify that this function should not return until it is completed.

*ppEffectPool* \[out\]

Type: **[**ID3D10EffectPool**](https://learn.microsoft.com/windows/win32/api/D3D10Effect/nn-d3d10effect-id3d10effectpool)\*\***

The address of a pointer to the effect pool (see [**ID3D10EffectPool Interface**](https://learn.microsoft.com/windows/win32/api/D3D10Effect/nn-d3d10effect-id3d10effectpool)).

*ppErrors* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)\*\***

The address of a pointer to memory (see [**ID3D10Blob Interface**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)) that contains effect compile errors, if there were any.

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX10Async.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

