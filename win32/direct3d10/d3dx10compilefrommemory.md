# D3DX10CompileFromMemory function

> [!Note]
> Instead of using this legacy function, we recommend that you compile offline by using the Fxc.exe command-line compiler or use the [**D3DCompile**](https://learn.microsoft.com/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3dcompile) API.

Compile a shader or an effect that is loaded in memory.

## Parameters

*pSrcData* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the shader in memory.

*SrcDataLen* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the shader in memory.

*pFileName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The name of the file that contains the shader code.

*pDefines* \[in\]

Type: **const [**D3D\_SHADER\_MACRO**](https://learn.microsoft.com/windows/win32/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)\***

Optional. Pointer to an array of macro definitions (see [**D3D\_SHADER\_MACRO**](https://learn.microsoft.com/windows/win32/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)). The last structure in the array serves as a terminator and must have all members set to 0. If not used, set *pDefines* to **NULL**.

*pInclude* \[in\]

Type: **[**LPD3D10INCLUDE**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))**

Optional. Pointer to an [**ID3D10Include Interface**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85)) interface for handling include files. Setting this to **NULL** will cause a compile error if a shader contains a \#include.

*pFunctionName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Name of the shader-entry point function where shader execution begins. When you compile an effect, **D3DX10CompileFromMemory** ignores *pFunctionName*; we recommend that you set *pFunctionName* to **NULL** because it is good programming practice to set a pointer parameter to **NULL** if the called function will not use it.

*pProfile* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A string that specifies the shader model; can be any profile in [shader model 2](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-sm2), [shader model 3](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-sm3), or [shader model 4](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-sm4).

*Flags1* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

[Shader compile flags](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-shader).

*Flags2* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

[Effect compile flags](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-effect-constants). When you compile a shader and not an effect file, **D3DX10CompileFromMemory** ignores *Flags2*; we recommend that you set *Flags2* to zero because it is good programming practice to set a nonpointer parameter to zero if the called function will not use it.

*pPump* \[in\]

Type: **[**ID3DX10ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump)\***

A pointer to a thread pump interface (see [**ID3DX10ThreadPump Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump)). Use **NULL** to specify that this function should not return until it is completed.

*ppShader* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)\*\***

A pointer to an [**ID3D10Blob Interface**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob) which contains the compiled shader, as well as any embedded debug and symbol-table information.

*ppErrorMsgs* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob)\*\***

A pointer to an [**ID3D10Blob Interface**](https://learn.microsoft.com/windows/win32/api/D3DCommon/nn-d3dcommon-id3d10blob) which contains a listing of errors and warnings that occurred during compilation. These errors and warnings are identical to the debug output from a debugger.

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX10Async.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

