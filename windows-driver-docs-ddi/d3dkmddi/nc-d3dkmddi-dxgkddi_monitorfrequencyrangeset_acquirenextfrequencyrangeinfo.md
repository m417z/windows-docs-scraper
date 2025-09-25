# DXGKDDI_MONITORFREQUENCYRANGESET_ACQUIRENEXTFREQUENCYRANGEINFO callback function

## Description

The **pfnAcquireNextFrequencyRangeInfo** function returns the next frequency range descriptor in a monitor frequency range set, given the current frequency range descriptor.

## Parameters

### `hMonitorFrequencyRangeSet` [in]

A handle to a monitor frequency range set object. The display miniport driver previously obtained this handle by calling the [pfnGetMonitorFrequencyRangeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitorfrequencyrangeset) function of the [Monitor Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pMonitorFrequencyRangeInfo` [in]

A pointer to a [D3DKMDT_MONITOR_FREQUENCY_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_frequency_range) structure that is the current frequency range descriptor. The display miniport driver previously obtained this pointer by calling [pfnAcquireFirstFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_acquirefirstfrequencyrangeinfo) or **pfnAcquireNextFrequencyRangeInfo**.

### `ppNextMonitorFrequencyRangeInfo` [out]

A pointer to a variable that receives a pointer to a D3DKMDT_MONITOR_FREQUENCY_RANGE structure that is the next frequency range descriptor.

## Return value

The **pfnAcquireNextFrequencyRangeInfo** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function successfully returned the next frequency range descriptor.|
|STATUS_GRAPHICS_DATASET_IS_EMPTY|The function succeeded, but there were no more frequency range descriptors in the set.|
|STATUS_INVALID_PARAMETER|An invalid parameter was supplied.|
|STATUS_INVALID_FREQUENCYRANGE|The frequency range descriptor supplied in pMonitorFrequencyRangeInfo was invalid.|
|STATUS_INVALID_MONITOR_FREQUENCYRANGESET|The handle supplied in hMonitorFrequencyRangeSet was invalid.|

This function might also return other error codes defined in *Ntstatus.h*.

## Remarks

When you have finished using the D3DKMDT_MONITOR_FREQUENCY_RANGE structure, you must release the structure by calling [pfnReleaseFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_releasefrequencyrangeinfo).

You can obtain all the descriptors in a monitor frequency range set by calling [pfnAcquireFirstFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_acquirefirstfrequencyrangeinfo) and then making a sequence of calls to **pfnAcquireNextFrequencyRangeInfo**.