# D3DX11\_IMAGE\_LOAD\_INFO structure

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

Optionally provide information to texture loader APIs to control how textures get loaded. A value of D3DX11\_DEFAULT for any of these parameters will cause D3DX to automatically use the value from the source file.

## Members

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The target width of the texture. If the actual width of the texture is larger or smaller than this value then the texture will be scaled up or down to fit this target width.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The target height of the texture. If the actual height of the texture is larger or smaller than this value then the texture will be scaled up or down to fit this target height.

**Depth**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The depth of the texture. This only applies to volume textures.

**FirstMipLevel**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The highest resolution mipmap level of the texture. If this is greater than 0, then after the texture is loaded FirstMipLevel will be mapped to mipmap level 0.

**MipLevels**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of mipmap levels in the texture. See the remarks in [**D3D11\_TEX1D\_SRV**](https://learn.microsoft.com/windows/desktop/api/D3D11/ns-d3d11-d3d11_tex1d_srv). Using 0 or D3DX11\_DEFAULT will cause a full mipmap chain to be created.

**Usage**

Type: **[**D3D11\_USAGE**](https://learn.microsoft.com/windows/desktop/api/D3D11/ne-d3d11-d3d11_usage)**

The way the texture resource is intended to be used. See [**D3D11\_USAGE**](https://learn.microsoft.com/windows/desktop/api/D3D11/ne-d3d11-d3d11_usage).

**BindFlags**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The pipeline stages that the texture will be allowed to bind to. See [**D3D11\_BIND\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D11/ne-d3d11-d3d11_bind_flag).

**CpuAccessFlags**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The access permissions the cpu will have for the texture resource. See [**D3D11\_CPU\_ACCESS\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D11/ne-d3d11-d3d11_cpu_access_flag).

**MiscFlags**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Miscellaneous resource properties (see [**D3D11\_RESOURCE\_MISC\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D11/ne-d3d11-d3d11_resource_misc_flag)).

**Format**

Type: **[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration indicating the format the texture will be in after it is loaded.

**Filter**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Filter the texture using the specified filter (only when resampling). See [**D3DX11\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-filter-flag).

**MipFilter**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Filter the texture mip levels using the specified filter (only if generating mipmaps). Valid values are D3DX11\_FILTER\_NONE, D3DX11\_FILTER\_POINT, D3DX11\_FILTER\_LINEAR, or D3DX11\_FILTER\_TRIANGLE. See [**D3DX11\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-filter-flag).

**pSrcInfo**

Type: **[**D3DX11\_IMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-info)\***

Information about the original image. See [**D3DX11\_IMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-info). Can be obtained with [**D3DX11GetImageInfoFromFile**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11getimageinfofromfile), [**D3DX11GetImageInfoFromMemory**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11getimageinfofrommemory), or [**D3DX11GetImageInfoFromResource**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11getimageinfofromresource).

## Remarks

When initializing the structure, you may set any member to D3DX11\_DEFAULT and D3DX will initialize it with a default value from the source texture when the texture is loaded.

This structure can be used by APIs that:

- Create resources, such as [**D3DX11CreateTextureFromFile**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11createtexturefromfile) and [**D3DX11CreateShaderResourceViewFromFile**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11createshaderresourceviewfromfile).
- Create data processors, such as [**D3DX11CreateAsyncTextureInfoProcessor**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11createasynctextureinfoprocessor) or [**D3DX11CreateAsyncShaderResourceViewProcessor**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11createasyncshaderresourceviewprocessor).

The default values are:

```
    Width = D3DX11_DEFAULT;
    Height = D3DX11_DEFAULT;
    Depth = D3DX11_DEFAULT;
    FirstMipLevel = D3DX11_DEFAULT;
    MipLevels = D3DX11_DEFAULT;
    Usage = (D3D11_USAGE) D3DX11_DEFAULT;
    BindFlags = D3DX11_DEFAULT;
    CpuAccessFlags = D3DX11_DEFAULT;
    MiscFlags = D3DX11_DEFAULT;
    Format = DXGI_FORMAT_FROM_FILE;
    Filter = D3DX11_DEFAULT;
    MipFilter = D3DX11_DEFAULT;
    pSrcInfo = NULL;
```

Here is a brief example that uses this structure to supply the pixel format when loading a texture. For the complete code, see HDRFormats10.cpp in [HDRToneMappingCS11 Sample](https://msdn.microsoft.com/library/Ee416569(v=VS.85).aspx).

```
ID3D11ShaderResourceView* pCubeRV = NULL;
WCHAR strPath[MAX_PATH];
D3DX11_IMAGE_LOAD_INFO LoadInfo;

    DXUTFindDXSDKMediaFileCch( strPath, MAX_PATH,
        L"Light Probes\\uffizi_cross.dds" );

    LoadInfo.Format = DXGI_FORMAT_R16G16B16A16_FLOAT;

    hr = D3DX11CreateShaderResourceViewFromFile( pd3dDevice, strPath,
        &LoadInfo, NULL, &pCubeRV, NULL );
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-structures)

