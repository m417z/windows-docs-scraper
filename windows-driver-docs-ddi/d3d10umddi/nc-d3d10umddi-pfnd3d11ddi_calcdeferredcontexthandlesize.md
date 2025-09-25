# PFND3D11DDI_CALCDEFERREDCONTEXTHANDLESIZE callback function

## Description

The **CalcDeferredContextHandleSize** function queries for the amount of storage space that the driver requires to satisfy deferred context handles to the given immediate context object.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*HandleType* [in]

A [D3D11DDI_HANDLETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_handletype)-typed value that indicates the type of deferred context handle to determine the size of the memory region for.

### `unnamedParam3`

*pICObject* [in]

A pointer to the object for the immediate context.

## Return value

**CalcDeferredContextHandleSize** returns the size of the storage space that the driver requires for the deferred context handles to the object that **pICObject** points to.

## Remarks

The driver is only required to implement **CalcDeferredContextHandleSize** if the driver supports the D3D11DDICAPS_COMMANDLISTS_BUILD_2 capability that can be returned in the [D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure from a call to the [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function.

The Direct3D runtime does not call the **CalcDeferredContextHandleSize** function from function tables for the deferred context. The runtime calls **CalcDeferredContextHandleSize** from the function table for the immediate context.

For more information about how **CalcDeferredContextHandleSize** is used, see [Using Context-Local DDI Handles](https://learn.microsoft.com/windows-hardware/drivers/display/using-context-local-ddi-handles).

## See also

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[D3D11DDI_HANDLETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_handletype)

[D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)