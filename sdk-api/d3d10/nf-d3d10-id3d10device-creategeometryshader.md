# ID3D10Device::CreateGeometryShader

## Description

Create a geometry shader.

## Parameters

### `pShaderBytecode` [in]

Type: **const void***

A pointer to the compiled shader. To get this pointer see [Getting a Pointer to a Compiled Shader](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-using-shaders-10).

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the compiled geometry shader.

### `ppGeometryShader` [out]

Type: **[ID3D10GeometryShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10geometryshader)****

Address of a pointer to an [ID3D10GeometryShader Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10geometryshader). If this is **NULL**, all other parameters will be validated, and if all parameters pass validation this API will return S_FALSE instead of S_OK.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Once created, the shader can be set to the device by calling [ID3D10Device::GSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gssetshader).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)