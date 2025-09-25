# ID3D10ShaderReflection1::IsLevel9Shader

## Description

Indicates whether a shader was compiled in Direct3D 10 on Direct3D 9 mode.

## Parameters

### `pbLevel9Shader` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a BOOL variable that will be set true if the shader was compiled in Direct3D 10 on Direct3D 9 mode; otherwise false.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This method requires Windows Vista Service Pack 1.

## See also

[ID3D10ShaderReflection1 Interface](https://learn.microsoft.com/windows/desktop/api/d3d10_1shader/nn-d3d10_1shader-id3d10shaderreflection1)