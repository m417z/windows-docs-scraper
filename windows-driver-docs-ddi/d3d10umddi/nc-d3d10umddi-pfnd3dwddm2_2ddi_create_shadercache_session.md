# PFND3DWDDM2_2DDI_CREATE_SHADERCACHE_SESSION callback function

## Description

The *pfnCreateShaderCacheSession* callback function creates a shader cache session.

## Parameters

### `unnamedParam1`

*hDevice* [in]

The handle of a device.

### `unnamedParam2`

*hCacheSession*

The handle of a cache session.

### `unnamedParam3`

*hRTCacheSession*

The handle of the cache session for the driver to use when it calls back into the runtime.

## Remarks

The runtime uses the object that is created to inform the driver of different caching contexts. It can be used to direct the caching callbacks towards a process-local cache or a per-component cache which is shared by multiple processes.

Access this callback function by using the [D3DWDDM2_2DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_2ddi_devicefuncs) structure.

## See also

[D3DWDDM2_2DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_2ddi_devicefuncs)