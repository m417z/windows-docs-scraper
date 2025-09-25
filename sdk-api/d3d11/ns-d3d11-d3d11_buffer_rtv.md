# D3D11_BUFFER_RTV structure

## Description

Specifies the elements in a buffer resource to use in a render-target view.

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

The width of each element (in bytes). This can be determined from the format stored in the render-target-view description.

## Remarks

A render-target view is a member of a render-target-view description (see [D3D11_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_view_desc)). Create a render-target view by calling [ID3D11Device::CreateRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createrendertargetview).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)