# ID3D10Texture3D::Map

## Description

Get a pointer to the data contained in a subresource, and deny GPU access to that subresource.

## Parameters

### `Subresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index number of the subresource. See [D3D10CalcSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-d3d10calcsubresource) for more details.

### `MapType` [in]

Type: **[D3D10_MAP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map)**

Specifies the CPU's read and write permissions for a resource. For possible values, see [D3D10_MAP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map).

### `MapFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Flag](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map_flag) that specifies what the CPU should do when the GPU is busy. This flag is optional.

### `pMappedTex3D` [out]

Type: **[D3D10_MAPPED_TEXTURE3D](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_mapped_texture3d)***

Pointer to a structure ([D3D10_MAPPED_TEXTURE3D](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_mapped_texture3d)) that is filled in by the function and contains a pointer to the resource data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it returns S_OK. All of the Map methods have identical return values and operating restrictions. These are listed in the remarks section of [ID3D10Texture1D::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture1d-map).

## See also

[ID3D10Texture3D Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10texture3d)