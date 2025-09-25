# ID3D10ShaderReflection1::GetResourceBindingDescByName

## Description

Gets a resource binding description by name.

## Parameters

### `Name` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a string containing the variable name.

### `pDesc`

Type: **[D3D10_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d10shader/ns-d3d10shader-d3d10_shader_input_bind_desc)***

Pointer to a [D3D10_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d10shader/ns-d3d10shader-d3d10_shader_input_bind_desc) structure that will be populated with resource binding information.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This method requires Windows Vista Service Pack 1.

## See also

[ID3D10ShaderReflection1 Interface](https://learn.microsoft.com/windows/desktop/api/d3d10_1shader/nn-d3d10_1shader-id3d10shaderreflection1)