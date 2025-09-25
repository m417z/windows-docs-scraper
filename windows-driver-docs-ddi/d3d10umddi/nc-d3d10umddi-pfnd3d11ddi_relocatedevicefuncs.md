# PFND3D11DDI_RELOCATEDEVICEFUNCS callback function

## Description

The *RelocateDeviceFuncs(D3D11)* function notifies the user-mode display driver about the new location of the driver function table.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDeviceFunctions* [in]

A pointer to a [D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs) structure that contains pointers to the functions of the user-mode display driver.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

A user-mode display driver can use the *RelocateDeviceFuncs(D3D11)* function to replace function pointers in the driver function table.

## See also

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)