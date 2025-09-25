# ID3D11Device::CreateTexture3D

## Description

Create a single [3D texture](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-textures-intro).

## Parameters

### `pDesc` [in]

Type: **const [D3D11_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture3d_desc)***

A pointer to a [D3D11_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture3d_desc) structure that describes a 3D texture resource. To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.

### `pInitialData` [in, optional]

Type: **const [D3D11_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_subresource_data)***

A pointer to an array of [D3D11_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_subresource_data) structures that describe subresources for the 3D texture resource. Applications cannot specify **NULL** for *pInitialData* when creating IMMUTABLE resources (see [D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage)). If the resource is multisampled, *pInitialData* must be **NULL** because multisampled resources cannot be initialized with data when they are created.

If you don't pass anything to *pInitialData*, the initial content of the memory for the resource is undefined. In this case, you need to write the resource content some other way before the resource is read.

You can determine the size of this array from the value in the **MipLevels** member of the [D3D11_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture3d_desc) structure to which *pDesc* points. Arrays of 3D volume textures are not supported.

For more information about this array size, see Remarks.

### `ppTexture3D` [out, optional]

Type: **[ID3D11Texture3D](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11texture3d)****

A pointer to a buffer that receives a pointer to a [ID3D11Texture3D](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11texture3d) interface for the created texture. Set this parameter to **NULL** to validate the other input parameters (the method will return S_FALSE if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return code is S_OK. See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for failing error codes.

## Remarks

**CreateTexture3D** creates a 3D texture resource, which can contain a number of 3D subresources. The number of textures is specified in the texture description. All textures in a resource must have the same format, size, and number of mipmap levels.

All resources are made up of one or more subresources. To load data into the texture, applications can supply the data initially as an array of [D3D11_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_subresource_data) structures pointed to by *pInitialData*, or they can use one of the D3DX texture functions such as [D3DX11CreateTextureFromFile](https://learn.microsoft.com/windows/desktop/direct3d11/d3dx11createtexturefromfile).

Each element of *pInitialData* provides all of the slices that are defined for a given miplevel. For example, for a 32 x 32 x 4 volume texture with a full mipmap chain, the array has the following 6 elements:

* pInitialData[0] = 32x32 with 4 slices
* pInitialData[1] = 16x16 with 2 slices
* pInitialData[2] = 8x8 with 1 slice
* pInitialData[3] = 4x4
  with 1 slice
* pInitialData[4] = 2x2
  with 1 slice
* pInitialData[5] = 1x1
  with 1 slice

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)