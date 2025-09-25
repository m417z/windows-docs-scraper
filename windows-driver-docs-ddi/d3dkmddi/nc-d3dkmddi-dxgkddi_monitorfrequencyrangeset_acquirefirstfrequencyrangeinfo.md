# DXGKDDI_MONITORFREQUENCYRANGESET_ACQUIREFIRSTFREQUENCYRANGEINFO callback function

## Description

The **DXGKDDI_MONITORFREQUENCYRANGESET_ACQUIREFIRSTFREQUENCYRANGEINFO** function returns the first frequency range descriptor in a specified monitor frequency range set object.

## Parameters

### `hMonitorFrequencyRangeSet` [in]

A handle to a monitor frequency range set object. The display miniport driver previously obtained this handle by calling the [pfnGetMonitorFrequencyRangeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitorfrequencyrangeset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `ppFirstMonitorFrequencyRangeInfo` [out]

A pointer to a variable that receives a pointer to a [D3DKMDT_MONITOR_FREQUENCY_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_frequency_range) structure.

## Return value

The **pfnAcquireFirstFrequencyRangeInfo** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function successfully returned the first frequency range descriptor.|
|STATUS_GRAPHICS_DATASET_IS_EMPTY|The function succeeded, but there were no frequency range descriptors in the set.|
|STATUS_INVALID_PARAMETER|An invalid parameter was supplied.|
|STATUS_INVALID_MONITOR_FREQUENCYRANGESET|The handle supplied in hMonitorFrequencyRangeSet was invalid.|

This function might also return other error codes defined in *Ntstatus.h*.

## Remarks

When you have finished using the D3DKMDT_MONITOR_FREQUENCY_RANGE structure, you must release the structure by calling [pfnReleaseFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_releasefrequencyrangeinfo).

You can obtain all the descriptors in a monitor frequency range set by calling **pfnAcquireFirstFrequencyRangeInfo** and then making a sequence of calls to [pfnAcquireNextFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_acquirenextfrequencyrangeinfo).