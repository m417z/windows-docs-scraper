# ID3D10Device::CreateShaderResourceView

## Description

Create a shader-resource [view](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-access-views) for accessing data in a resource.

## Parameters

### `pResource` [in]

Type: **[ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)***

Pointer to the [resource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) that will serve as input to a shader. This resource must have been created with the [D3D10_BIND_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag) flag.

### `pDesc` [in]

Type: **const [D3D10_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_shader_resource_view_desc)***

Pointer to a shader-resource-view description (see [D3D10_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_shader_resource_view_desc)). Set this parameter to **NULL** to create a view that accesses the entire resource (using the format the resource was created with).

### `ppSRView` [out]

Type: **[ID3D10ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview)****

Address of a pointer to an [ID3D10ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview). Set this parameter to **NULL** to validate the other input parameters (the method will return S_FALSE if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

A resource is made up of one or more [subresources](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types), a view identifies which subresources to allow the pipeline to access. In addition, each resource is bound to the pipeline using a view. A shader-resource view is designed to bind any buffer or texture resource to the [shader stages](https://learn.microsoft.com/previous-versions/bb205146(v=vs.85)) using the following API methods: [VSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vssetshaderresources), [GSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gssetshaderresources) and [PSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-pssetshaderresources).

Since a view is fully typed, this means that typeless resources become fully typed when bound to the pipeline.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)