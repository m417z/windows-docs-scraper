# D3DX10ReflectShader function

This function -- which creates a shader-reflection object for retrieving information about a compiled shader -- no longer exists. Instead, use [**D3DReflect**](https://learn.microsoft.com/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3dreflect) or [**D3D11Reflect**](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11reflect).

## Parameters

*pShaderBytecode* \[in\]

Type: **const void\***

A pointer to the compiled shader. To get this pointer see [Getting a Pointer to a Compiled Shader](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-using-shaders-10).

*BytecodeLength* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Length of pShaderBytecode.

*ppReflector* \[out\]

Type: **[**ID3D10ShaderReflection1**](https://learn.microsoft.com/windows/desktop/api/D3D10_1Shader/nn-d3d10_1shader-id3d10shaderreflection1)\*\***

Address of a shader reflection interface (see [**ID3D10ShaderReflection1 Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10_1Shader/nn-d3d10_1shader-id3d10shaderreflection1).)

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Here is an example of creating a shader-reflection object. The example assumes you start with a compiled shader (shown as

```
pVSBuf
```

which you can see in [HLSLWithoutFX10 Sample](https://msdn.microsoft.com/library/Ee416414(v=VS.85).aspx)).

```
ID3D10ShaderReflection1* pIShaderReflection1 = NULL;
D3D10_SHADER_DESC desc;
hr = D3D10ReflectShader( (void*) pVSBuf->GetBufferPointer(), pVSBuf->GetBufferSize(),
    &pIShaderReflection1 );
if( pIShaderReflection1 )
{
    pIShaderReflection1->GetDesc( &desc );
}
```

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

