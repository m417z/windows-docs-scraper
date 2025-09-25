# ID3D10Device::ClearDepthStencilView

## Description

Clears the depth-stencil resource.

## Parameters

### `pDepthStencilView` [in]

Type: **[ID3D10DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilview)***

Pointer to the depth stencil to be cleared.

### `ClearFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Which parts of the buffer to clear. See [D3D10_CLEAR_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_clear_flag).

### `Depth` [in]

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Clear the depth buffer with this value. This value will be clamped between 0 and 1.

### `Stencil` [in]

Type: **UINT8**

Clear the stencil buffer with this value.

## Remarks

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>Unlike Direct3D 9, the full extent of the resource view is always cleared. Viewport and scissor settings are not applied. |

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)