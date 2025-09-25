# PDH_TIME_INFO structure

## Description

The
**PDH_TIME_INFO** structure contains information on time intervals as applied to the sampling of performance data.

## Members

### `StartTime`

Starting time of the sample interval, in local [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format.

### `EndTime`

Ending time of the sample interval, in local [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format.

### `SampleCount`

Number of samples collected during the interval.

## See also

[PdhSetQueryTimeRange](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhsetquerytimerange)