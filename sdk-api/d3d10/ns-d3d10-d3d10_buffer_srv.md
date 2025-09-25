# D3D10_BUFFER_SRV structure

## Description

Specifies the elements in a [buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) resource to use in a shader-resource view.

## Members

### `FirstElement`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bytes between the beginning of the buffer and the first element to access.

### `ElementOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset of the first element in the view to access, relative to element 0.

### `NumElements`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The total number of elements in the view.

### `ElementWidth`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width of each element (in bytes). This can be determined from the format stored in the shader-resource-view description.

## Remarks

The **D3D10_BUFFER_SRV** structure is a member of the [D3D10_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_shader_resource_view_desc) structure, which represents a shader-resource view description. You can create a shader-resource view by calling the [ID3D10Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createshaderresourceview) method.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)