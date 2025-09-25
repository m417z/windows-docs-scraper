# PFND3D10DDI_IA_SETVERTEXBUFFERS callback function

## Description

The *IaSetVertexBuffers* function sets vertex buffers for an input assembler.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `StartSlot`

The starting vertex buffer to set.

### `NumBuffers` [in]

The total number of buffers to set.

### `unnamedParam4`

*phBuffers* [in]

An array of handles to the vertex buffers, beginning with the buffer that *StartBuffer* specifies.

### `unnamedParam5`

*pStrides* [in]

An array of values that indicate the sizes, in bytes, from one vertex to the next vertex for each buffer

### `unnamedParam6`

*pOffsets* [in]

An array of values that indicate the offsets, in bytes, into each vertex buffer.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *IaSetVertexBuffers* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)