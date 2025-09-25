# ID3D11Device::CreateShaderResourceView

## Description

Create a shader-resource view for accessing data in a resource.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

Pointer to the resource that will serve as input to a shader. This resource must have been created with the [D3D11_BIND_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) flag.

### `pDesc` [in, optional]

Type: **const [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_shader_resource_view_desc)***

Pointer to a shader-resource view description (see [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_shader_resource_view_desc)). Set this parameter to **NULL** to create a
view that accesses the entire resource (using the format the resource was created with).

### `ppSRView` [out, optional]

Type: **[ID3D11ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11shaderresourceview)****

Address of a pointer to an [ID3D11ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11shaderresourceview). Set this parameter to **NULL** to validate the
other input parameters (the method will return **S_FALSE** if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

A resource is made up of one or more subresources; a view identifies which subresources to allow the pipeline to access. In addition, each resource is
bound to the pipeline using a view. A shader-resource view is designed to bind any buffer or texture resource to the shader stages using the following
API methods: [ID3D11DeviceContext::VSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vssetshaderresources), [ID3D11DeviceContext::GSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gssetshaderresources) and [ID3D11DeviceContext::PSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-pssetshaderresources).

Because a view is fully typed, this means that typeless resources become fully typed when bound to the pipeline.

**Note** To successfully create a shader-resource view from a typeless buffer (for example, [DXGI_FORMAT_R32G32B32A32_TYPELESS](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)), you must set the [D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag when you create the buffer.

The Direct3D 11.1 runtime, which is available starting with Windows 8, allows you to use **CreateShaderResourceView** for the following new purpose.

You can create shader-resource views of video resources so that Direct3D shaders can process those shader-resource views. These video resources are either [Texture2D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2d) or [Texture2DArray](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2darray). The value in the **ViewDimension** member of the [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_shader_resource_view_desc) structure for a created shader-resource view must match the type of video resource, D3D11_SRV_DIMENSION_TEXTURE2D for Texture2D and D3D11_SRV_DIMENSION_TEXTURE2DARRAY for Texture2DArray. Additionally, the format of the underlying video resource restricts the formats that the view can use. The video resource format values on the [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) reference page specify the format values that views are restricted to.

The runtime read+write conflict prevention logic (which stops a resource from being bound as an SRV and RTV or UAV at the same time) treats views of different parts of the same video surface as conflicting for simplicity. Therefore, the runtime does not allow an application to read from luma while the application simultaneously renders to chroma in the same surface even though the hardware might allow these simultaneous operations.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)