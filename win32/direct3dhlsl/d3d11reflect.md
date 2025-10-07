# D3D11Reflect function

Gets a pointer to a reflection interface.

## Parameters

*pSrcData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to source data as compiled HLSL code.

*SrcDataSize* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of *pSrcData*.

*ppReflector* \[out\]

Type: **[**ID3D11ShaderReflection**](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection)\*\***

The address of a pointer to the [**ID3D11ShaderReflection**](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection) interface.

## Return value

Type: **[**HRESULT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the return codes described in the topic [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The inline **D3D11Reflect** compiler function is a wrapper for the [**D3DReflect**](https://learn.microsoft.com/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3dreflect) compiler function. **D3D11Reflect** can retrieve only a [**ID3D11ShaderReflection**](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection) interface from a shader. **D3DReflect** can retrieve a **ID3D11ShaderReflection** interface or a Direct3D 10 or Direct3D 10.1 reflection interface, for example, [**ID3D10ShaderReflection**](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nn-d3d10shader-id3d10shaderreflection).

Shader code contains metadata that can be inspected using the reflection APIs.

The following code shows how to retrieve a [**ID3D11ShaderReflection**](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection) interface from a shader.

```C++
pd3dDevice->CreatePixelShader( pPixelShaderBuffer->GetBufferPointer(),
                               pPixelShaderBuffer->GetBufferSize(), g_pPSClassLinkage, &g_pPixelShader );

ID3D11ShaderReflection* pReflector = NULL;
D3D11Reflect( pPixelShaderBuffer->GetBufferPointer(), pPixelShaderBuffer->GetBufferSize(),
            &pReflector);
```

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------------|
| Header<br> | D3DCompiler.inl |
| Library<br> | D3dcompiler\_47.lib |
| DLL<br> | D3dcompiler\_47.dll |

## See also

[Functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)

