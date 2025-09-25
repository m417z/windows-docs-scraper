# PFND3D10DDI_DRAWINDEXED callback function

## Description

The **pfnDrawIndexed** function draws indexed primitives.

## Parameters

### `unnamedParam1`

[in] **hDevice**: A handle to the display device (graphics context).

### `unnamedParam2`

[in] **IndexCount**: The number of indices in the index buffer that identify the vertex buffer vertices to draw.

### `unnamedParam3`

[in] **StartIndexLocation**: The location of the first index to read from the index buffer.

### `unnamedParam4`

[in] **BaseVertexLocation**: The value added to each index before reading a vertex from the vertex buffer.

## Remarks

For an example on how to use indices and vertices, see [Understand the Direct3D 11 rendering pipeline](https://learn.microsoft.com/windows/win32/direct3dgetstarted/understand-the-directx-11-2-graphics-pipeline).

The driver can use the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The only error a driver should encounter is D3DDDIERR_DEVICEREMOVED. If the driver passes a different error to **pfnSetErrorCb**, the Direct3D runtime will determine that the error is critical.

Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED. However, if device removal interfered with the **pfnDrawIndexed** operation (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[**D3D10DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)