# ID3D10Texture1D::Map

## Description

Get a pointer to the data contained in a subresource, and deny the GPU access to that subresource.

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

### `ppData` [out]

Type: **void****

Pointer to the texture resource data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it returns S_OK. For other restrictions, and a listing of error values that can be returned by any of the **Map** methods, see Remarks.

## Remarks

###

Mapping a texture enables the CPU to directly access the underlying data in the subresource of a texture. For the method to succeed, the texture being mapped must be created with the appropriate flags (see [D3D10_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_cpu_access_flag)), and its specified usage (see [D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage)) must be either D3D10_USAGE_DYNAMIC or D3D10_USAGE_STAGING.

Common failures of **Map** methods are indicated by the following return values:

| Item | Description |
| --- | --- |
| DXGI_ERROR_WAS_STILL_DRAWING | If *MapFlags* specifies D3D10_MAP_FLAG_DO_NOT_WAIT and the GPU is not yet finished with the resource, **Map** returns DXGI_ERROR_WAS_STILL_DRAWING. |
| DXGI_ERROR_DEVICE_REMOVED | **Map** returns DXGI_ERROR_DEVICE_REMOVED if *MapType* allows any CPU read access and the video card has been removed. |

For more information about the preceding return values, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

**Map** has the following restrictions:

* A single subresource cannot be mapped multiple times; in other words, do not call **Map** on a subresource that is already mapped.
* Any subresource that is bound to the pipeline must be unmapped before any render operation (that is, before [ID3D10Device::Draw](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-draw)) can be executed.

Applications must cast the void pData pointer to the appropriate type to meaningfully access the underlying subresource data. For example, the following code demonstrates how to read each texel of a 1D subresource. It is assumed that the texture was created using [DXGI_FORMAT_R32G32B32A32_FLOAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) and that pData is the pointer to the texture resource data output from a successful call to this method.

```

FLOAT* pTexels = (FLOAT*)pData;
for( UINT col = 0; col < width; col++ )
{
  pTexels[col*4 + 0]; // Alpha
  pTexels[col*4 + 1]; // Blue
  pTexels[col*4 + 2]; // Green
  pTexels[col*4 + 3]; // Red
}

```

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>**Map** in Direct3D 10 is analogous to resource [Lock](https://learn.microsoft.com/windows/desktop/direct3d9/locking-resources) in Direct3D 9. |

## See also

[ID3D10Texture1D Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10texture1d)