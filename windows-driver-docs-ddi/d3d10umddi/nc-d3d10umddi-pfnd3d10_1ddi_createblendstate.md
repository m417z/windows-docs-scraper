# PFND3D10_1DDI_CREATEBLENDSTATE callback function

## Description

The **CreateBlendState(D3D10_1)** function creates a blend state.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pBlendDesc* [in]

A pointer to a [D3D10_1_DDI_BLEND_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1_ddi_blend_desc) structure that describes the parameters that the user-mode display driver uses to create a blend state.

### `unnamedParam3`

*hBlendState* [in]

A handle to the driver's private data for the blend state.

### `unnamedParam4`

*hRTBlendState* [in]

A handle to the blend state that the driver should use anytime it calls back into the Direct3D runtime.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver can pass E_OUTOFMEMORY (if the driver runs out of memory) or D3DDDIERR_DEVICEREMOVED (if the device has been removed) in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The Direct3D runtime will determine that any other errors are critical. If the driver passes any errors, including D3DDDIERR_DEVICEREMOVED, the Direct3D runtime will determine that the handle is invalid; therefore, the runtime will not call the [DestroyBlendState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyblendstate) function to destroy the handle that the *hBlendState* parameter specifies.

The user-mode display driver is not required to create more than 4,096 unique instances of blend-state objects on a device at one time.

## See also

[CalcPrivateBlendStateSize(D3D10_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_calcprivateblendstatesize)

[D3D10_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs)

[D3D10_1_DDI_BLEND_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1_ddi_blend_desc)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)