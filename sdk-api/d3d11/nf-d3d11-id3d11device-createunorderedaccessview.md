# ID3D11Device::CreateUnorderedAccessView

## Description

Creates a view for accessing an [unordered access](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-cs-resources) resource.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

Pointer to an [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) that represents a resources that will serve as an input to a shader.

### `pDesc` [in, optional]

Type: **const [D3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_unordered_access_view_desc)***

Pointer to an [D3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_unordered_access_view_desc) that represents a shader-resource view description. Set this parameter to **NULL** to create a view that accesses the entire resource (using the format the resource was created with).

### `ppUAView` [out, optional]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)****

Address of a pointer to an [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview) that represents an unordered-access view. Set this parameter to **NULL** to validate the other input parameters (the method will return S_FALSE if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The Direct3D 11.1 runtime, which is available starting with Windows 8, allows you to use **CreateUnorderedAccessView** for the following new purpose.

You can create unordered-access views of video resources so that Direct3D shaders can process those unordered-access views. These video resources are either [Texture2D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2d) or [Texture2DArray](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2darray). The value in the **ViewDimension** member of the [D3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_unordered_access_view_desc) structure for a created unordered-access view must match the type of video resource, D3D11_UAV_DIMENSION_TEXTURE2D for Texture2D and D3D11_UAV_DIMENSION_TEXTURE2DARRAY for Texture2DArray. Additionally, the format of the underlying video resource restricts the formats that the view can use. The video resource format values on the [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) reference page specify the format values that views are restricted to.

The runtime read+write conflict prevention logic (which stops a resource from being bound as an SRV and RTV or UAV at the same time) treats views of different parts of the same video surface as conflicting for simplicity. Therefore, the runtime does not allow an application to read from luma while the application simultaneously renders to chroma in the same surface even though the hardware might allow these simultaneous operations.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)