# ID3D11FunctionReflection::GetResourceBindingDescByName

## Description

Gets a description of how a resource is bound to a function.

## Parameters

### `Name` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The constant-buffer name of the resource.

### `pDesc` [out]

Type: **[D3D11_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d11shader/ns-d3d11shader-d3d11_shader_input_bind_desc)***

A pointer to a [D3D11_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d11shader/ns-d3d11shader-d3d11_shader_input_bind_desc) structure that describes input binding of the resource.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

A shader consists of executable code (the compiled HLSL functions) and a set of resources that supply the shader with input data. **GetResourceBindingDescByName** gets info about how one resource in the set is bound as an input to the shader. The *Name* parameter specifies the name of the resource.

## See also

[ID3D11FunctionReflection](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11functionreflection)