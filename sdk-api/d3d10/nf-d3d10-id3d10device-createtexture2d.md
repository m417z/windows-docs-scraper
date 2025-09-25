# ID3D10Device::CreateTexture2D

## Description

Create an array of 2D textures (see [Texture2D](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types)).

## Parameters

### `pDesc` [in]

Type: **const [D3D10_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture2d_desc)***

Pointer to a 2D texture description (see [D3D10_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture2d_desc)). To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.

### `pInitialData` [in]

Type: **const [D3D10_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_subresource_data)***

Pointer to an array of [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) descriptions (see [D3D10_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_subresource_data)); one for each subresource (ordered by texture array index, then mip level). Applications may not specify **NULL** for pInitialData when creating IMMUTABLE resources (see [D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage)). If the resource is multisampled, pInitialData must be **NULL** because multisampled resources cannot be initialized with data when they are created.

### `ppTexture2D` [out]

Type: **[ID3D10Texture2D](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10texture2d)****

Address of a pointer to the created texture (see [ID3D10Texture2D Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10texture2d)). Set this parameter to **NULL** to validate the other input parameters (the method will return S_FALSE if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return code is S_OK. See [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues) for failing error codes.

## Remarks

CreateTexture2D creates a 2D texture resource, which contains an array of 1D textures. The number of textures is specified in the texture description. All textures in a resource must have the same format, size, and number of mipmap levels.

All resources are made up of one or more [subresources](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types). To load data into the texture, applications may supply the data initially as part of [D3D10_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_subresource_data) structure pointed to by pInitialData, or it may use one of the [Texturing Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing) supplied by the SDK.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)