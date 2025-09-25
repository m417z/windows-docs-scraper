# DXGKDDI_MONITORFREQUENCYRANGESET_RELEASEFREQUENCYRANGEINFO callback function

## Description

The **pfnReleaseFrequencyRangeInfo** function releases a [D3DKMDT_MONITOR_FREQUENCY_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_frequency_range) structure that the VidPN manager previously provided to the display miniport driver.

## Parameters

### `hMonitorFrequencyRangeSet` [in]

A handle to a monitor frequency range set object. The display miniport driver previously obtained this handle by calling the [pfnGetMonitorFrequencyRangeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitorfrequencyrangeset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pMonitorFrequencyRangeInfo` [in]

A pointer to the D3DKMDT_MONITOR_FREQUENCY_RANGE structure that is to be released.

## Return value

The **pfnAcquireNextFrequencyRangeInfo** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_INVALID_MONITOR_FREQUENCY_RANGE|The frequency range descriptor supplied in pMonitorFrequencyRangeInfo was invalid.|
|STATUS_INVALID_MONITOR_FREQUENCYRANGESET|The handle supplied in hMonitorFrequencyRangeSet was invalid.|

## Remarks

When you have finished using a D3DKMDT_MONITOR_FREQUENCY_RANGE structure that you obtained by calling [pfnAcquireFirstFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_acquirefirstfrequencyrangeinfo) or [pfnAcquireNextFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_acquirenextfrequencyrangeinfo), you must release it by calling **pfnReleaseFrequencyRangeInfo**.