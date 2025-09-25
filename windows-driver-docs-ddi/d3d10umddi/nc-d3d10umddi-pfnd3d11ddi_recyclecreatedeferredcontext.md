# PFND3D11DDI_RECYCLECREATEDEFERREDCONTEXT callback function

## Description

The *RecycleCreateDeferredContext* function clears out the pipeline state for a deferred context.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateDeferredContext* [in]

A pointer to a [D3D11DDIARG_CREATEDEFERREDCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createdeferredcontext) structure, which describes the parameters that the user-mode display driver uses to create a deferred context.

## Return value

*RecycleCreateDeferredContext* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The deferred context is successfully created.|
|E_OUTOFMEMORY|RecycleCreateDeferredContext could not allocate memory that is required for it to complete.|

## Remarks

The driver is only required to implement *RecycleCreateDeferredContext* if the driver supports the D3D11DDICAPS_COMMANDLISTS_BUILD_2 threading-capability bit. The driver can return D3D11DDICAPS_COMMANDLISTS_BUILD_2 in the **Caps** member of the [D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure from a call to the driver's [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function.

For more information about *RecycleCreateDeferredContext*, see [Introduction to Deferred Contexts](https://learn.microsoft.com/windows-hardware/drivers/display/introduction-to-deferred-contexts).

## See also

[D3D11DDIARG_CREATEDEFERREDCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createdeferredcontext)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)