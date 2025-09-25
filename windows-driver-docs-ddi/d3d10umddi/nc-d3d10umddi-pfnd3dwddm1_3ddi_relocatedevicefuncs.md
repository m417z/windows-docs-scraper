# PFND3DWDDM1_3DDI_RELOCATEDEVICEFUNCS callback function

## Description

Notifies the user-mode display driver about the new location of the driver function table.

Implemented by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*DeviceFuncs* [in]

A pointer to a [D3DWDDM1_3DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_devicefuncs) structure that contains pointers to the functions of the user-mode display driver.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

A user-mode display driver can use the *RelocateDeviceFuncs(D3D11_2)* function to replace function pointers in the driver function table.

## See also

[D3DWDDM1_3DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_devicefuncs)

[RelocateDeviceFuncs(D3D11_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_relocatedevicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)