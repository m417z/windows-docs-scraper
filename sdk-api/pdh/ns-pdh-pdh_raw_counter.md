# PDH_RAW_COUNTER structure

## Description

The
**PDH_RAW_COUNTER** structure returns the data as it was collected from the counter provider. No translation, formatting, or other interpretation is performed on the data.

## Members

### `CStatus`

Counter status that indicates if the counter value is valid. Check this member before using the data in a calculation or displaying its value. For a list of possible values, see
[Checking PDH Interface Return Values](https://learn.microsoft.com/windows/desktop/PerfCtrs/checking-pdh-interface-return-values).

### `TimeStamp`

Local time for when the data was collected, in
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format.

### `FirstValue`

First raw counter value.

### `SecondValue`

Second raw counter value. Rate counters require two values in order to compute a displayable value.

### `MultiCount`

If the counter type contains the PERF_MULTI_COUNTER flag, this member contains the additional counter data used in the calculation. For example, the PERF_100NSEC_MULTI_TIMER counter type contains the PERF_MULTI_COUNTER flag.

## See also

[PdhCalculateCounterFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcalculatecounterfromrawvalue)

[PdhComputeCounterStatistics](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcomputecounterstatistics)

[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue)