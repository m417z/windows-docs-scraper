# D3DX11CompileFromMemory function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you compile offline by using the Fxc.exe command-line compiler or use one of the HLSL compile APIs, like the [**D3DCompile**](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile) API.

Compile a shader or an effect that is loaded in memory.

## Parameters

*pSrcData* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the shader in memory.

*SrcDataLen* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the shader in memory.

*pFileName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the file that contains the shader code.

*pDefines* \[in\]

Type: **const [**D3D10\_SHADER\_MACRO**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)\***

Optional. Pointer to an array of macro definitions (see [**D3D10\_SHADER\_MACRO**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)). The last structure in the array serves as a terminator and must have all members set to 0. If not used, set *pDefines* to **NULL**.

*pInclude* \[in\]

Type: **[**LPD3D10INCLUDE**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))**

Optional. Pointer to an interface for handling include files. Setting this to **NULL** will cause a compile error if a shader contains a \#include.

*pFunctionName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the shader-entry point function where shader execution begins. When you compile an effect, **D3DX11CompileFromMemory** ignores *pFunctionName*; we recommend that you set *pFunctionName* to **NULL** because it is good programming practice to set a pointer parameter to **NULL** if the called function will not use it.

*pProfile* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that specifies the shader model; can be any profile in shader model 2, shader model 3, shader model 4, or shader model 5. The profile can also be for effect type (for example, fx\_4\_1).

*Flags1* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shader [**compile flags**](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-constants).

*Flags2* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Effect [**compile flags**](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-effect-constants). When you compile a shader and not an effect file, **D3DX11CompileFromMemory** ignores *Flags2*; we recommend that you set *Flags2* to zero because it is good programming practice to set a nonpointer parameter to zero if the called function will not use it.

*pPump* \[in\]

Type: **[**ID3DX11ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump)\***

A pointer to a thread pump interface (see [**ID3DX11ThreadPump Interface**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump)). Use **NULL** to specify that this function should not return until it is completed.

*ppShader* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)\*\***

A pointer to memory which contains the compiled shader, as well as any embedded debug and symbol-table information.

*ppErrorMsgs* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)\*\***

A pointer to memory which contains a listing of errors and warnings that occurred during compilation. These errors and warnings are identical to the debug output from a debugger.

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

**D3DX11CompileFromMemory** returns E\_INVALIDARG if you supply non-**NULL** to the *pHResult* parameter when you supply **NULL** to the *pPump* parameter. For more information about this situation, see Remarks.

## Remarks

For more information about **D3DX11CompileFromMemory**, see [**D3DCompile**](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile).

You must supply **NULL** to the *pHResult* parameter if you also supply **NULL** to the *pPump* parameter. Otherwise, you cannot subsequently create a shader by using the compiled shader code that **D3DX11CompileFromMemory** returns in the memory that the *ppShader* parameter points to. To create a shader from complied shader code, you call one of the following [**ID3D11Device**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11device) interface methods:

- [**CreateComputeShader**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-id3d11device-createcomputeshader)
- [**CreateDomainShader**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-id3d11device-createdomainshader)
- [**CreateGeometryShader**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-id3d11device-creategeometryshader)
- [**CreateGeometryShaderWithStreamOutput**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-id3d11device-creategeometryshaderwithstreamoutput)
- [**CreateHullShader**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-id3d11device-createhullshader)
- [**CreatePixelShader**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-id3d11device-createpixelshader)
- [**CreateVertexShader**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-id3d11device-createvertexshader)

In addition, if you supply a non-**NULL** value to *pHResult* when you supply **NULL** to *pPump*, **D3DX11CompileFromMemory** returns the E\_INVALIDARG error code.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX11async.h |
| Library<br> | D3DX11.lib |

## See also

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-functions)

