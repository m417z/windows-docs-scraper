# D3DX11\_TEXTURE\_LOAD\_INFO structure

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

Describes parameters used to load a texture from another texture.

## Members

**pSrcBox**

Type: **[**D3D11\_BOX**](https://learn.microsoft.com/windows/desktop/api/D3D11/ns-d3d11-d3d11_box)\***

Source texture box (see [**D3D11\_BOX**](https://learn.microsoft.com/windows/desktop/api/D3D11/ns-d3d11-d3d11_box)).

**pDstBox**

Type: **[**D3D11\_BOX**](https://learn.microsoft.com/windows/desktop/api/D3D11/ns-d3d11-d3d11_box)\***

Destination texture box (see [**D3D11\_BOX**](https://learn.microsoft.com/windows/desktop/api/D3D11/ns-d3d11-d3d11_box)).

**SrcFirstMip**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Source texture mipmap level, see [**D3D11CalcSubresource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-d3d11calcsubresource) for more detail.

**DstFirstMip**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Destination texture mipmap level, see [**D3D11CalcSubresource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-d3d11calcsubresource) for more detail.

**NumMips**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of mipmap levels in the source texture.

**SrcFirstElement**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

First element of the source texture.

**DstFirstElement**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

First element of the destination texture.

**NumElements**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of elements to load.

**Filter**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Filtering options during resampling (see [**D3DX11\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-filter-flag)).

**MipFilter**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Filtering options when generating mip levels (see [**D3DX11\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-filter-flag)).

## Remarks

This structure is used in a call to [**D3DX11LoadTextureFromTexture**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11loadtexturefromtexture).

The default values are:

```
    pSrcBox = NULL;
    pDstBox = NULL;
    SrcFirstMip = 0;
    DstFirstMip = 0;
    NumMips = D3DX11_DEFAULT;
    SrcFirstElement = 0;
    DstFirstElement = 0;
    NumElements = D3DX11_DEFAULT;
    Filter = D3DX11_DEFAULT;
    MipFilter = D3DX11_DEFAULT;
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-structures)

