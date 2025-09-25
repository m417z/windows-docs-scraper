# PFND3D10DDI_CLEARDEPTHSTENCILVIEW callback function

## Description

The **ClearDepthStencilView** function clears the specified currently bound depth-stencil view.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDepthStencilView* [in]

A handle to the depth-stencil view to clear.

### `unnamedParam3`

*Stencil* [in]

An unsigned 8-bit integer value to set the stencil to.

### `unnamedParam4`

*Depth* [in]

A single-precision float vector to set the depth to.

### `unnamedParam5`

*Flags* [in]

A value that specifies which parts of the buffer to affect. This parameter must be set to one of the following values from the D3D10_DDI_CLEAR_FLAG enumeration.

|Value|Meaning|
|:--|:--|
|D3D10_DDI_CLEAR_DEPTH (0x01L)|The depth value (Z) is clamped to the ZNear and ZFar range of the viewport that is currently bound to slot zero by using Microsoft Direct3D. Afterwards, Z is clamped again to the representable range of the currently bound depth-stencil view by again using Direct3D.|
|D3D10_DDI_CLEAR_STENCIL (0x02L)|The stencil value is cleared.|

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

Floating point rules apply to the **ClearDepthStencilView** function.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of **ClearDepthStencilView** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)