# DDS\_HEADER\_DXT10 structure

DDS header extension to handle resource arrays, DXGI pixel formats that don't map to the legacy Microsoft DirectDraw pixel format structures, and additional metadata.

## Members

**dxgiFormat**

Type: **[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The surface pixel format (see [**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)).

**resourceDimension**

Type: **[**D3D10\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_resource_dimension)**

Identifies the type of resource. The following values for this member are a subset of the values in the [**D3D10\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_resource_dimension) or [**D3D11\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_dimension) enumeration:

| Type | Description | Value |
|-------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------|
| DDS\_DIMENSION\_TEXTURE1D (D3D10\_RESOURCE\_DIMENSION\_TEXTURE1D) | Resource is a [1D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types). The **dwWidth** member of [**DDS\_HEADER**](https://learn.microsoft.com/windows/win32/direct3ddds/dds-header) specifies the size of the texture. Typically, you set the **dwHeight** member of **DDS\_HEADER** to 1; you also must set the DDSD\_HEIGHT flag in the **dwFlags** member of **DDS\_HEADER**. | 2 |
| DDS\_DIMENSION\_TEXTURE2D (D3D10\_RESOURCE\_DIMENSION\_TEXTURE2D) | Resource is a [2D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) with an area specified by the **dwWidth** and **dwHeight** members of [**DDS\_HEADER**](https://learn.microsoft.com/windows/win32/direct3ddds/dds-header). You can also use this type to identify a cube-map texture. For more information about how to identify a cube-map texture, see **miscFlag** and **arraySize** members. | 3 |
| DDS\_DIMENSION\_TEXTURE3D (D3D10\_RESOURCE\_DIMENSION\_TEXTURE3D) | Resource is a [3D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) with a volume specified by the **dwWidth**, **dwHeight**, and **dwDepth** members of [**DDS\_HEADER**](https://learn.microsoft.com/windows/win32/direct3ddds/dds-header). You also must set the DDSD\_DEPTH flag in the **dwFlags** member of **DDS\_HEADER**. | 4 |

**miscFlag**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies other, less common options for resources. The following value for this member is a subset of the values in the [**D3D10\_RESOURCE\_MISC\_FLAG**](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_resource_misc_flag) or [**D3D11\_RESOURCE\_MISC\_FLAG**](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) enumeration:

| Type | Description | Value |
|----------------------------------|--------------------------------------------------------------------------------------------------------------|-------|
| DDS\_RESOURCE\_MISC\_TEXTURECUBE | Indicates a [2D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) is a cube-map texture. | 0x4 |

**arraySize**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the array.

For a [2D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) that is also a cube-map texture, this number represents the number of cubes. This number is the same as the number in the **NumCubes** member of [**D3D10\_TEXCUBE\_ARRAY\_SRV1**](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ns-d3d10_1-d3d10_texcube_array_srv1) or [**D3D11\_TEXCUBE\_ARRAY\_SRV**](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texcube_array_srv)). In this case, the DDS file contains **arraySize**\*6 2D textures. For more information about this case, see the **miscFlag** description.

For a [3D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types), you must set this number to 1.

**miscFlags2**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Contains additional metadata (formerly was reserved). The lower 3 bits indicate the alpha mode of the associated resource. The upper 29 bits are reserved and are typically 0.

| Type | Description | Value |
|---------------------------------|------------------------------------------------------------------------------------------------------------------------------------------|-------|
| DDS\_ALPHA\_MODE\_UNKNOWN | Alpha channel content is unknown. This is the value for legacy files, which typically is assumed to be 'straight' alpha. | 0x0 |
| DDS\_ALPHA\_MODE\_STRAIGHT | Any alpha channel content is presumed to use straight alpha. | 0x1 |
| DDS\_ALPHA\_MODE\_PREMULTIPLIED | Any alpha channel content is using premultiplied alpha. The only legacy file formats that indicate this information are 'DX2' and 'DX4'. | 0x2 |
| DDS\_ALPHA\_MODE\_OPAQUE | Any alpha channel content is all set to fully opaque. | 0x3 |
| DDS\_ALPHA\_MODE\_CUSTOM | Any alpha channel content is being used as a 4th channel and is not intended to represent transparency (straight or premultiplied). | 0x4 |

> [!Note]
> The legacy D3DX 10 and [D3DX 11](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3dx11) utility libraries will fail to load any .DDS file with **miscFlags2** not equal to zero.

## Remarks

Use this structure together with a [**DDS\_HEADER**](https://learn.microsoft.com/windows/win32/direct3ddds/dds-header) to store a resource array in a DDS file. For more info, see [texture arrays](https://learn.microsoft.com/windows/win32/direct3ddds/dx-graphics-dds-pguide).

This header is present if the **dwFourCC** member of the [**DDS\_PIXELFORMAT**](https://learn.microsoft.com/windows/win32/direct3ddds/dds-pixelformat) structure is set to 'DX10'.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------|
| Header<br> | Dds.h |

## See also

[Reference for DDS](https://learn.microsoft.com/windows/win32/direct3ddds/dx-graphics-dds-reference)

