# DXGKDDI_MONITORDESCRIPTORSET_RELEASEDESCRIPTORINFO callback function

## Description

The **pfnReleaseDescriptorInfo** function releases a [D3DKMDT_MONITOR_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_descriptor) structure that the VidPN manager previously provided to the display miniport driver.

## Parameters

### `hMonitorDescriptorSet`

A handle to a monitor descriptor set object. The display miniport driver previously obtained this handle by calling the [pfnGetMonitorDescriptorSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitordescriptorset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pMonitorDescriptorInfo`

A pointer to the D3DKMDT_MONITOR_DESCRIPTOR structure to be released.

## Return value

The **pfnReleaseDescriptorInfo** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_INVALID_MONITOR_DESCRIPTOR|The descriptor supplied in pMonitorDescriptorInfo was invalid.|
|STATUS_GRAPHICS_INVALID_MONITOR_DESCRIPTORSET|The handle supplied in hMonitorDescriptorSet was invalid.|

## Remarks

When you have finished using a D3DKMDT_MONITOR_DESCRIPTOR structure that you obtained by calling [pfnAcquireFirstDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_acquirefirstdescriptorinfo) or [pfnAcquireNextDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_acquirenextdescriptorinfo), you must release it by calling **pfnReleaseDescriptorInfo**.