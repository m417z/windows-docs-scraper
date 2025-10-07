# D3DX10\_IMAGE\_LOAD\_INFO structure

Optionally provide information to texture loader APIs to control how textures get loaded. A value of D3DX10\_DEFAULT for any of these parameters will cause D3DX to automatically use the value from the source file.

## Members

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The target width of the texture. If the actual width of the texture is larger or smaller than this value then the texture will be scaled up or down to fit this target width.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The target height of the texture. If the actual height of the texture is larger or smaller than this value then the texture will be scaled up or down to fit this target height.

**Depth**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The depth of the texture. This only applies to volume textures.

**FirstMipLevel**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The highest resolution mipmap level of the texture. If this is greater than 0, then after the texture is loaded FirstMipLevel will be mapped to mipmap level 0.

**MipLevels**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum number of mipmap levels that the texture will have. Using 0 or D3DX10\_DEFAULT will cause a full mipmap chain to be created.

**Usage**

Type: **[**D3D10\_USAGE**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_usage)**

The way the texture resource is intended to be used. See [**D3D10\_USAGE**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_usage).

**BindFlags**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The pipeline stages that the texture will be allowed to bind to. See [**D3D10\_BIND\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_bind_flag).

**CpuAccessFlags**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The access permissions the cpu will have for the texture resource. See [**D3D10\_CPU\_ACCESS\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_cpu_access_flag).

**MiscFlags**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Miscellaneous resource properties (see [**D3D10\_RESOURCE\_MISC\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_resource_misc_flag)).

**Format**

Type: **[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The format the texture will be in after it is loaded. See [**DXGI\_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format).

**Filter**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Filter the texture using the specified filter (only when resampling). See [**D3DX10\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-filter-flag).

**MipFilter**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Filter the texture mip levels using the specified filter (only if generating mipmaps). Valid values are D3DX10\_FILTER\_NONE, D3DX10\_FILTER\_POINT, D3DX10\_FILTER\_LINEAR, or D3DX10\_FILTER\_TRIANGLE. See [**D3DX10\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-filter-flag).

**pSrcInfo**

Type: **[**D3DX10\_IMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-info)\***

Information about the original image. See [**D3DX10\_IMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-info). Can be obtained with [**D3DX10GetImageInfoFromFile**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10getimageinfofromfile), [**D3DX10GetImageInfoFromMemory**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10getimageinfofrommemory), or [**D3DX10GetImageInfoFromResource**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10getimageinfofromresource).

## Remarks

When initializing the structure, you may set any member to D3DX10\_DEFAULT and D3DX will initialize it with a default value from the source texture when the texture is loaded.

This structure can be used by APIs that:

- Create resources, such as [**D3DX10CreateTextureFromFile**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10createtexturefromfile) and [**D3DX10CreateShaderResourceViewFromFile**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10createshaderresourceviewfromfile).
- Create data processors, such as [**D3DX10CreateAsyncTextureInfoProcessor**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10createasynctextureinfoprocessor) or [**D3DX10CreateAsyncShaderResourceViewProcessor**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10createasyncshaderresourceviewprocessor).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

