# PFND3D10DDI_DISABLE_DEFERRED_STAGING_RESOURCE_DESTRUCTION_CB callback function

## Description

The **pfnDisableDeferredStagingResourceDestruction** function disables the deferred destruction of staging resources.

## Parameters

### `unnamedParam1`

*hRuntimeDevice* [in]

A handle to a context for the core Microsoft Direct3D 10 runtime. This handle is supplied to the driver in a call to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

## Remarks

By default, the Direct3D runtime defers the destruction of staging resources, until a call to the user-mode display driver's [ResourceIsStagingBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceisstagingbusy) function indicates that the graphics pipeline no longer uses the resources. The runtime defers the destruction of staging resources because the destruction of a staging resource, while still in use, might cause the processor to block until the resource is no longer used.

If the user-mode display driver can ensure that this type of block can be avoided, the driver can call **pfnDisableDeferredStagingResourceDestruction** to disable the deferred destruction behavior.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDI_CORELAYER_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_corelayer_devicecallbacks)

[ResourceIsStagingBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceisstagingbusy)