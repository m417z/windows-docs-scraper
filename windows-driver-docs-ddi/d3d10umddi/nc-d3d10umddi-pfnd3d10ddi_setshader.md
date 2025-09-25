# PFND3D10DDI_SETSHADER callback function

## Description

The **CsSetShader** function sets the compute shader code so that all of the subsequent dispatching operations use that code.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hShader* [in]

A handle to the compute shader code object.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of**CsSetShader** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

The **DsSetShader** function sets the domain shader code so that all of the subsequent drawing operations use that code.

The **VsSetShader** function sets the vertex shader code so that all of the subsequent drawing operations use that code.

The **GsSetShader** function sets the geometry shader code so that all of the subsequent drawing operations use that code.

The **HsSetShader** function sets the hull shader code so that all of the subsequent drawing operations use that code.

The **PsSetShader** function sets a pixel shader to be used in all drawing operations.

## See also

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)