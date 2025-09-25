# ID3D11DeviceContext::ClearDepthStencilView

## Description

Clears the depth-stencil resource.

## Parameters

### `pDepthStencilView` [in]

Type: **[ID3D11DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilview)***

Pointer to the depth stencil to be cleared.

### `ClearFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identify the type of data to clear (see [D3D11_CLEAR_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_clear_flag)).

### `Depth` [in]

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Clear the depth buffer with this value. This value will be clamped between 0 and 1.

### `Stencil` [in]

Type: **UINT8**

Clear the stencil buffer with this value.

## Remarks

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 11/10:<br><br>Unlike Direct3D 9, the full extent of the resource view is always cleared. Viewport and scissor settings are not applied. |

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)