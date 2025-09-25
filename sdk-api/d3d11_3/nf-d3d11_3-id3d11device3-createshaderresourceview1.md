# ID3D11Device3::CreateShaderResourceView1

## Description

Creates a shader-resource view for accessing data in a resource.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

Pointer to the resource that will serve as input to a shader. This resource must have been created with the [D3D11_BIND_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) flag.

### `pDesc1` [in, optional]

Type: **const [D3D11_SHADER_RESOURCE_VIEW_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_shader_resource_view_desc1)***

A pointer to a [D3D11_SHADER_RESOURCE_VIEW_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_shader_resource_view_desc1) structure that describes a shader-resource view. Set this parameter to **NULL** to create a
view that accesses the entire resource (using the format the resource was created with).

### `ppSRView1` [out, optional]

Type: **[ID3D11ShaderResourceView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11shaderresourceview1)****

A pointer to a memory block that receives a pointer to a [ID3D11ShaderResourceView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11shaderresourceview1) interface for the created shader-resource view. Set this parameter to **NULL** to validate the other input parameters (the method will return **S_FALSE** if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns E_OUTOFMEMORY if there is insufficient memory to create the shader-resource view. See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## See also

[ID3D11Device3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11device3)