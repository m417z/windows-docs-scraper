# PFND3D10DDI_SHADERRESOURCEVIEWREADAFTERWRITEHAZARD callback function

## Description

The *ShaderResourceViewReadAfterWriteHazard* function informs the user-mode display driver that the specified resource was used as an output from the graphics processing unit (GPU) and that the resource will be used as an input to the GPU. A shader resource view is also provided to indicate which view caused the hazard.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hResource* [in]

A handle to the resource.

### `unnamedParam3`

*hShaderResourceView* [in]

A handle to the driver's private data for a shader resource view object.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The Microsoft Direct3D runtime calls *ShaderResourceViewReadAfterWriteHazard* immediately before the specified resource is bound as an input to the GPU.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *ShaderResourceViewReadAfterWriteHazard* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)