# D3DReflect function

## Description

Gets a pointer to a reflection interface.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to source data as compiled HLSL code.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of *pSrcData*.

### `pInterface` [in]

Type: **REFIID**

The reference GUID of the COM interface to use. For example, **IID_ID3D11ShaderReflection**.

### `ppReflector` [out]

Type: **void****

A pointer to a reflection interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

Shader code contains metadata that can be inspected using the reflection APIs.

The following code illustrates retrieving a [ID3D11ShaderReflection](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection) Interface from a shader.

```cpp

pd3dDevice->CreatePixelShader( pPixelShaderBuffer->GetBufferPointer(),
                               pPixelShaderBuffer->GetBufferSize(), g_pPSClassLinkage, &g_pPixelShader );

ID3D11ShaderReflection* pReflector = NULL;
D3DReflect( pPixelShaderBuffer->GetBufferPointer(), pPixelShaderBuffer->GetBufferSize(),
            IID_ID3D11ShaderReflection, (void**) &pReflector);

```

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)