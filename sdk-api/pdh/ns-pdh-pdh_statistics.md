# PDH_STATISTICS structure

## Description

The
**PDH_STATISTICS** structure contains the minimum, maximum, and mean values for an array of raw counters values.

## Members

### `dwFormat`

Format of the data. The format is specified in the *dwFormat* when calling
[PdhComputeCounterStatistics](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcomputecounterstatistics).

### `count`

Number of values in the array.

### `min`

Minimum of the values.

### `max`

Maximum of the values.

### `mean`

Mean of the values.

## See also

[PdhComputeCounterStatistics](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcomputecounterstatistics)