# PFND3D11DDI_CHECKDEFERREDCONTEXTHANDLESIZES callback function

## Description

The **CheckDeferredContextHandleSizes** function verifies the sizes of the driver-private memory spaces that hold the handle data of deferred context handles.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `pHSizes`

The size, in bytes, of the array pointed to by *pHandleSize*.

### `unnamedParam3`

*pHandleSize* [out, optional]

An array of [D3D11DDI_HANDLESIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_handlesize) structures that describe the handle data of deferred context handles.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set a critical error code.

The driver is only required to implement *CheckDeferredContextHandleSizes* if the driver supports the **D3D11DDICAPS_COMMANDLISTS_BUILD_2** capability that can be returned in the [D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure from a call to the [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function.

For more information about how *CheckDeferredContextHandleSizes* is used, see [Using Context-Local DDI Handles](https://learn.microsoft.com/windows-hardware/drivers/display/using-context-local-ddi-handles).

The driver's *CheckDeferredContextHandleSizes* function cannot call the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set the **D3DDDIERR_DEVICEREMOVED** error code because *CheckDeferredContextHandleSizes* is a capability-check type of function. The driver must ensure that it has enough information after device creation to respond to a call to *CheckDeferredContextHandleSizes*, even in the presence of **D3DDDIERR_DEVICEREMOVED**.

*CheckDeferredContextHandleSizes* should not encounter any errors. However, *CheckDeferredContextHandleSizes* might call [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) for critical errors.

## See also

[CheckDeferredContextHandleSizes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_checkdeferredcontexthandlesizes)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)