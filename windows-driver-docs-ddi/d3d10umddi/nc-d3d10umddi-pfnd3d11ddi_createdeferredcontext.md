# PFND3D11DDI_CREATEDEFERREDCONTEXT callback function

## Description

The **CreateDeferredContext** function creates a deferred context.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateDeferredContext* [in]

A pointer to a [D3D11DDIARG_CREATEDEFERREDCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createdeferredcontext) structure that describes the parameters that the user-mode display driver uses to create a deferred context.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver is only required to implement **CreateDeferredContext** if the driver supports the D3D11DDICAPS_COMMANDLISTS_BUILD_2 capability that can be returned in the [D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure from a call to the [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function.

## See also

[D3D11DDIARG_CREATEDEFERREDCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createdeferredcontext)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)