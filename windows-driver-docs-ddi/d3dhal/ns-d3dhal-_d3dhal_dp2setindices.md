# _D3DHAL_DP2SETINDICES structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2SETINDICES structure is used to set the current index buffer for [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwVBHandle`

Specifies the surface handle associated with this surface through a call to [D3dCreateSurfaceEx](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurfaceex).

### `dwStride`

Specifies the size of the indices contained in the index buffer and has the value 2 if the indices are 16-bit, or 4 if the indices are 32-bit quantities.

## Remarks

A handle value of zero is valid and indicates that the current index buffer is cleared. Subsequent attempts to draw indexed primitives (before a new current index buffer is established via another D3DDP2OP_SETINDICES token) should be handled by the driver such that a crash does not occur. The debug version of your driver should display informative messages to the debug output stream when this error condition is detected.

## See also

[D3dCreateSurfaceEx](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurfaceex)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)