# DXGKDDI_MONITORDESCRIPTORSET_ACQUIRENEXTDESCRIPTORINFO callback function

## Description

The **pfnAcquireNextDescriptorInfo** function returns the next descriptor in a monitor descriptor set, given the current descriptor.

## Parameters

### `hMonitorDescriptorSet` [in]

A handle to a monitor descriptor set object. The display miniport driver previously obtained this handle by calling the [pfnGetMonitorDescriptorSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitordescriptorset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pMonitorDescriptorInfo` [in]

A pointer to a [D3DKMDT_MONITOR_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_descriptor) structure that is the current descriptor. The display miniport driver previously obtained this pointer by calling [pfnAcquireFirstDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_acquirefirstdescriptorinfo) or **pfnAcquireNextDescriptorInfo**.

### `ppNextMonitorDescriptorInfo` [out]

A pointer to a variable that receives a pointer to a [D3DKMDT_MONITOR_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_descriptor) structure. The structure is the next descriptor in the set.

## Return value

The **pfnAcquireNextDescriptorInfo** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function successfully returned the next descriptor in the set.|
|STATUS_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET|The function succeeded, but there were no more descriptors in the set.|
|STATUS_INVALID_PARAMETER|An invalid parameter was supplied.|
|STATUS_INVALID_MONITOR_DESCRIPTOR|The descriptor supplied in pMonitorDescriptorInfo was invalid.|
|STATUS_GRAPHICS_INVALID_MONITOR_DESCRIPTORSET|The handle supplied in hMonitorDescriptorSet was invalid.|

## Remarks

When you have finished using the D3DKMDT_MONITOR_DESCRIPTOR structure, you must release the structure by calling [pfnReleaseDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_releasedescriptorinfo).

You can obtain all the descriptors in a monitor descriptor set by calling [pfnAcquireFirstDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_acquirefirstdescriptorinfo) and then making a sequence of calls to **pfnAcquireNextDescriptorInfo**.