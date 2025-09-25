# PFND3D10DDI_SETSHADERRESOURCES callback function

## Description

The **CsSetShaderResources** function sets resources for a compute shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `StartSlot` [in]

The offset to the first view to set.

### `NumViews`

The total number of views to set.

### `unnamedParam4`

*phShaderResourceViews* [in]

An array of handles to the shader resource views, beginning at the offset that *Offset* specifies.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of **CsSetShaderResources** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

The **VsSetShaderResources** function sets resources for a vertex shader.

The **PsSetShaderResources** function sets resources for a pixel shader.

The **DsSetShaderResources** function sets resources for a domain shader.

The **GsSetShaderResources** function sets resources for a geometry shader.

## See also

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)