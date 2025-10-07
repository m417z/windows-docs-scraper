# D3DX11CreateAsyncCompilerProcessor function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps. See Remarks.

Create an asynchronous-data processor for a shader.

## Parameters

*pFileName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that contains the shader filename.

*pDefines* \[in\]

Type: **const D3D11\_SHADER\_MACRO\***

A NULL-terminated array of shader macros; set this to **NULL** to specify no macros.

*pInclude* \[in\]

Type: **[**LPD3D10INCLUDE**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))**

A pointer to an include interface. This parameter can be **NULL**.

*pFunctionName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the shader-entry point function where shader execution begins. When you compile an effect, **D3DX11CreateAsyncCompilerProcessor** ignores *pFunctionName*; we recommend that you set *pFunctionName* to **NULL** because it is good programming practice to set a pointer parameter to **NULL** if the called function will not use it..

*pProfile* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that specifies the shader profile or shader model; can be any profile in shader model 2, shader model 3, shader model 4, or shader model 5. The profile can also be for effect type (for example, fx\_4\_1).

*Flags1* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shader compile flags.

*Flags2* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Effect compile flags. When you compile a shader and not an effect file, **D3DX11CreateAsyncCompilerProcessor** ignores *Flags2*; we recommend that you set *Flags2* to zero because it is good programming practice to set a nonpointer parameter to zero if the called function will not use it.

*ppCompiledShader* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)\*\***

Address of a pointer to the compiled effect.

*ppErrorBuffer* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)\*\***

Address of a pointer to compile errors.

*ppDataProcessor* \[out\]

Type: **[**ID3DX11DataProcessor**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11dataprocessor)\*\***

Address of a pointer to a buffer that contains the data processor created (see [**ID3DX11DataProcessor Interface**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11dataprocessor)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

There s no implementation of the async loader outside of D3DX 10, and D3DX 11.

For Windows Store apps, the DirectX samples (for example, the [Direct3D tutorial sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Platform%20Sample/Direct3D%20tutorial%20sample)) include the **BasicLoader** module that uses the Windows Runtime asynchronous programming model ([**AsyncBase**](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2012/br244878(v=vs.110))).

For Win32 desktop apps, you can use the [Concurrency Runtime](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/ee207192(v=vs.100)) to implement something similar to the Windows Runtime asynchronous programming model.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX11async.h |
| Library<br> | D3DX11.lib |

## See also

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-functions)

