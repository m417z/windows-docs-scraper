# PFND3D10_1DDI_CREATESHADERRESOURCEVIEW callback function

## Description

The **CreateShaderResourceView(D3D10_1)** function creates a shader resource view.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateShaderResourceView* [in]

A pointer to a [D3D10_1DDIARG_CREATESHADERRESOURCEVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddiarg_createshaderresourceview) structure that describes the parameters that the user-mode display driver uses to create a shader resource view.

### `unnamedParam3`

*hShaderResourceView* [in]

A handle to the driver's private data for the shader resource view.

### `unnamedParam4`

*hRTShaderResourceView* [in]

A handle to the shader resource view that the driver should use anytime it calls back into the Direct3D runtime.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver might run out of memory. Therefore, the driver can pass E_OUTOFMEMORY or D3DDDIERR_DEVICEREMOVED in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The Direct3D runtime will determine that any other errors are critical. If the driver passes any errors, including D3DDDIERR_DEVICEREMOVED, the Direct3D runtime will determine that the handle is invalid; therefore, the runtime will not call the [DestroyShaderResourceView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshaderresourceview) function to destroy the handle that the *hShaderResourceView* parameter specifies.

## See also

[CalcPrivateShaderResourceViewSize(D3D10_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_calcprivateshaderresourceviewsize)

[D3D10_1DDIARG_CREATESHADERRESOURCEVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddiarg_createshaderresourceview)

[D3D10_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs)

[DestroyShaderResourceView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshaderresourceview)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)