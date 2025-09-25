# ID3D10Buffer::Unmap

## Description

Invalidate the pointer to the resource retrieved by [ID3D10Buffer::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10buffer-map) and reenable GPU access to the resource.

## Remarks

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>Unmap() in Direct3D 10 is analogous to resource Unlock() in Direct3D 9. |

## See also

[ID3D10Buffer Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)