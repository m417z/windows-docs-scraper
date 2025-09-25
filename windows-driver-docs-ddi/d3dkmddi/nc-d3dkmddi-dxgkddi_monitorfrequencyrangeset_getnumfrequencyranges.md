# DXGKDDI_MONITORFREQUENCYRANGESET_GETNUMFREQUENCYRANGES callback function

## Description

The **pfnGetNumFrequencyRanges** returns the number of frequency range descriptors in a specified monitor frequency range set object.

## Parameters

### `hMonitorFrequencyRangeSet` [in]

A handle to a monitor frequency range set object. The display miniport driver previously obtained this handle by calling the **pfnGetMonitorFrequencyRangeSet** function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pNumMonitorFrequencyRanges` [out]

A pointer to a SIZE_T-typed variable that receives the number of descriptors in the set.

## Return value

The **pfnGetNumFrequencyRanges** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_INVALID_PARAMETER|An invalid parameter was supplied.|
|STATUS_INVALID_MONITOR_FREQUENCYRANGESET|The handle supplied in hMonitorFrequencyRangeSet was invalid.|