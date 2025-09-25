# PFND3D10DDI_SETCONSTANTBUFFERS callback function

## Description

The **CsSetConstantBuffers** function sets constant buffers for a compute shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `StartSlot` [in]

The starting constant buffer to set.

### `NumBuffers` [in]

The total number of buffers to set.

### `unnamedParam4`

*phBuffers* [in]

An array of handles to the constant buffers, beginning with the buffer that **StartBuffer** specifies.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

Buffers that the **CsSetConstantBuffers** function specifies are created with the D3D10_BIND_CONSTANT_BUFFER flag.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of **CsSetConstantBuffers** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

The **VsSetConstantBuffers** function sets constant buffers for a vertex shader.

The **GsSetConstantBuffers** function sets constant buffers for a geometry shader.

The **HsSetConstantBuffers** function sets constant buffers for a hull shader.

The **PsSetConstantBuffers** function sets constant buffers for a pixel shader.

The **DsSetConstantBuffers** function sets constant buffers for a domain shader.

## See also

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)