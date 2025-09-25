# D3D10ReflectShader function

## Description

This function -- which creates a shader-reflection object for retrieving information about a compiled shader -- has been deprecated. Instead, use [D3DReflect](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dreflect).

## Parameters

### `pShaderBytecode` [in]

Type: **const void***

A pointer to the compiled shader.

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of pShaderBytecode.

### `ppReflector` [out]

Type: **[ID3D10ShaderReflection](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nn-d3d10shader-id3d10shaderreflection)****

Address of a reflection interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Return value.

## See also

[Shader Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-functions)