# D3D10GetOutputSignatureBlob function

## Description

Get a buffer that contains shader-output signatures.

## Parameters

### `pShaderBytecode` [in]

Type: **const void***

A pointer to the compiled shader. To get this pointer see [Getting a Pointer to a Compiled Shader](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-using-shaders-10).

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the shader bytecode in bytes.

### `ppSignatureBlob` [out]

Type: **[ID3D10Blob](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)****

The address of a pointer to the buffer (see [ID3D10Blob Interface](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)

[Shader Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-functions)