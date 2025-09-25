# ID3D10Texture1D::Unmap

## Description

Invalidate the pointer to a resource that was retrieved by [ID3D10Texture1D::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture1d-map), and re-enable the GPU's access to that resource.

## Parameters

### `Subresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to be unmapped. See [D3D10CalcSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-d3d10calcsubresource) for more details.

## Remarks

A subresource must be mapped before Unmap is called.

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>Unmap in Direct3D 10 is analogous to resource Unlock in Direct3D 9. |

## See also

[ID3D10Texture1D Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10texture1d)