## Description

Creates a [2D texture](https://learn.microsoft.com/windows/win32/direct3d11/overviews-direct3d-11-resources-textures-intro).

## Parameters

### `pDesc1` [in]

Type: **const [D3D11_TEXTURE2D_DESC1](https://learn.microsoft.com/windows/win32/api/d3d11_3/ns-d3d11_3-d3d11_texture2d_desc1)***

A pointer to a [D3D11_TEXTURE2D_DESC1](https://learn.microsoft.com/windows/win32/api/d3d11_3/ns-d3d11_3-d3d11_texture2d_desc1) structure that describes a 2D texture resource. To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.

### `pInitialData` [in, optional]

Type: **const [D3D11_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_subresource_data)***

 A pointer to an array of [D3D11_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_subresource_data) structures that describe subresources for the 2D texture resource. Applications can't specify **NULL** for *pInitialData* when creating IMMUTABLE resources (see [D3D11_USAGE](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_usage)). If the resource is multisampled, *pInitialData* must be **NULL** because multisampled resources can't be initialized with data when they're created.

If you don't pass anything to *pInitialData*, the initial content of the memory for the resource is undefined. In this case, you need to write the resource content some other way before the resource is read.

You can determine the size of this array from values in the **MipLevels** and **ArraySize** members of the **D3D11_TEXTURE2D_DESC1** structure to which *pDesc1* points by using the following calculation:

MipLevels * ArraySize

For more info about this array size, see Remarks.

### `ppTexture2D` [out, optional]

Type: **[ID3D11Texture2D1](https://learn.microsoft.com/windows/win32/api/d3d11_3/nn-d3d11_3-id3d11texture2d1)****

A pointer to a memory block that receives a pointer to a [ID3D11Texture2D1](https://learn.microsoft.com/windows/win32/api/d3d11_3/nn-d3d11_3-id3d11texture2d1) interface for the created texture. Set this parameter to **NULL** to validate the other input parameters (the method will return **S_FALSE** if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return code is **S_OK**. See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues) for failing error codes.

## Remarks

**CreateTexture2D1** creates a 2D texture resource, which can contain a number of 2D subresources. The number of subresources is specified in the texture description. All textures in a resource must have the same format, size, and number of mipmap levels.

All resources are made up of one or more subresources. To load data into the texture, applications can supply the data initially as an array of [D3D11_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_subresource_data) structures pointed to by *pInitialData*, or they can use one of the D3DX texture functions such as [D3DX11CreateTextureFromFile](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11createtexturefromfile).

For a 32 x 32 texture with a full mipmap chain, the *pInitialData* array has the following 6 elements:

* pInitialData[0] = 32x32
* pInitialData[1] = 16x16
* pInitialData[2] = 8x8
* pInitialData[3] = 4x4
* pInitialData[4] = 2x2
* pInitialData[5] = 1x1

## See also

[ID3D11Device3](https://learn.microsoft.com/windows/win32/api/d3d11_3/nn-d3d11_3-id3d11device3)