# DXGKDDI_MONITORDESCRIPTORSET_GETNUMDESCRIPTORS callback function

## Description

The **pfnGetNumDescriptors** function returns the number of descriptors in a monitor descriptor set.

## Parameters

### `hMonitorDescriptorSet` [in]

A handle to a monitor descriptor set object. The display miniport driver previously obtained this handle by calling the [pfnGetMonitorDescriptorSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitordescriptorset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pNumMonitorDescriptors` [out]

A SIZE_T-typed variable that receives the number of descriptors in the set.

## Return value

The **pfnGetNumDescriptors** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_INVALID_PARAMETER|An invalid parameter was supplied.|
|STATUS_GRAPHICS_INVALID_MONITOR_DESCRIPTORSET|The handle supplied in hMonitorDescriptorSet was invalid.|