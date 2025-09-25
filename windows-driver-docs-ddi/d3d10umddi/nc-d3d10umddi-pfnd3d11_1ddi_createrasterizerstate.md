# PFND3D11_1DDI_CREATERASTERIZERSTATE callback function

## Description

Creates a rasterizer state.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pRasterizerDesc* [in]

A pointer to a [D3D11_1_DDI_RASTERIZER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1_ddi_rasterizer_desc) structure that describes the parameters that the user-mode display driver uses to create a rasterizer state.

### `unnamedParam3`

*hRasterizerState* [in]

A handle to the driver's private data for the rasterizer state.

### `unnamedParam4`

*hRTRasterizerState*

A handle to the rasterizer state that the driver should use when it calls back into the Direct3D runtime.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver can pass E_OUTOFMEMORY (if the driver runs out of memory) or D3DDDIERR_DEVICEREMOVED (if the device has been removed) in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The Direct3D runtime will determine that any other errors are critical. If the driver passes any errors, including D3DDDIERR_DEVICEREMOVED, the Direct3D runtime will determine that the handle is incorrect; therefore, the runtime will not call the [DestroyRasterizerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyrasterizerstate) function to destroy the handle that the *hRasterizerState* parameter specifies.

The user-mode display driver is not required to create more than 4,096 unique instances of rasterizer-state objects on a device at a time.

## See also

[CalcPrivateRasterizerStateSize(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivaterasterizerstatesize)

[D3D11_1_DDI_RASTERIZER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1_ddi_rasterizer_desc)

[DestroyRasterizerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyrasterizerstate)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)