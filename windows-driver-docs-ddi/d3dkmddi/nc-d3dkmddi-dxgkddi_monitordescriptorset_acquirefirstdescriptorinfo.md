# DXGKDDI_MONITORDESCRIPTORSET_ACQUIREFIRSTDESCRIPTORINFO callback function

## Description

The **pfnAcquireFirstDescriptorInfo** function returns the first descriptor in a monitor descriptor set object.

## Parameters

### `hMonitorDescriptorSet` [in]

A handle to a monitor descriptor set object. The display miniport driver previously obtained this handle by calling the [pfnGetMonitorDescriptorSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitordescriptorset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `ppFirstMonitorDescriptorInfo` [out]

A pointer to a variable that receives a pointer to a [D3DKMDT_MONITOR_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_descriptor) structure. The structure is the first descriptor in the set.

## Return value

The **pfnAcquireFirstDescriptorInfo** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function successfully returned the first descriptor in the set.|
|STATUS_GRAPHICS_DATASET_IS_EMPTY|The function succeeded, but there were no descriptors in the set.|
|STATUS_INVALID_PARAMETER|An invalid parameter was supplied.|
|STATUS_GRAPHICS_INVALID_MONITOR_DESCRIPTORSET|The handle supplied in *hMonitorDescriptorSet* was invalid.|

## Remarks

When you have finished using the D3DKMDT_MONITOR_DESCRIPTOR structure, you must release the structure by calling [pfnReleaseDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_releasedescriptorinfo).

You can obtain all the descriptors in a monitor descriptor set by calling **pfnAcquireFirstDescriptorInfo** and then making a sequence of calls to [pfnAcquireNextDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_acquirenextdescriptorinfo).