# PFND3D10DDI_SETSAMPLERS callback function

## Description

The **CsSetSamplers** function sets samplers for a compute shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `StartSlot`

*Offset* [in]

The offset to the first sampler to set.

### `NumSamplers` [in]

The total number of samplers to set.

### `unnamedParam4`

*phSamplers* [in]

An array of handles to the samplers, beginning at the offset that *Offset* specifies.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of **CsSetSamplers** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

The HsSetSamplers function sets samplers for a hull shader.

The GsSetSamplers function sets samplers for a geometry shader.

The VsSetSamplers function sets samplers for a vertex shader.

The PsSetSamplers function sets samplers for a pixel shader.

## See also

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)