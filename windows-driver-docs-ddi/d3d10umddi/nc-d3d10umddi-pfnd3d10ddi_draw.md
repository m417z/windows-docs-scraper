# PFND3D10DDI_DRAW callback function

## Description

The **pfnDraw** function draws non-indexed primitives.

## Parameters

### `unnamedParam1`

[in] **hDevice**: A handle to the display device (graphics context).

### `unnamedParam2`

[in] **VertexCount**: The number of vertices in the vertex buffer that vertices are read from to draw the primitives.

### `unnamedParam3`

[in] **StartVertexLocation**: The first vertex in the vertex buffer that vertices are read from to draw the primitives.

## Remarks

The driver can use the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The only error a driver should encounter is D3DDDIERR_DEVICEREMOVED. If the driver passes a different error to **pfnSetErrorCb**, the Direct3D runtime will determine that the error is critical.

Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED. However, if device removal interfered with the **pfnDraw** operation (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[**D3D10DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)