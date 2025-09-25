# D3D11_BUFFER_SRV structure

## Description

Specifies the elements in a buffer resource to use in a shader-resource view.

## Members

### `FirstElement`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first element to access.

### `ElementOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset of the first element in the view to access, relative to element 0.

### `NumElements`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The total number of elements in the view.

### `ElementWidth`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width of each element (in bytes).
This can be determined from the format stored in the shader-resource-view description.

## Remarks

The **D3D11_BUFFER_SRV** structure is a member of the [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_shader_resource_view_desc) structure, which represents a shader-resource view description. You can create a shader-resource view by calling the [ID3D11Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createshaderresourceview) method.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)