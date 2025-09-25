# PdhGetCounterTimeBase function

## Description

Returns the time base of the specified counter.

## Parameters

### `hCounter` [in]

Handle to the counter. The
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function returns this handle.

### `pTimeBase` [out]

Time base that specifies the number of performance values a counter samples per second.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | The specified counter does not use a time base. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |

## Remarks

If you use
the
[PdhFormatFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhformatfromrawvalue) function to calculate a displayable value instead of calling the [PdhCalculateCounterFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcalculatecounterfromrawvalue) function, you must call the
**PdhGetCounterTimeBase** function to retrieve the time base.

Each counter that returns time-based performance data has a time base defined for it. The time base of a counter is the number of times a counter samples data per second.

## See also

[PdhFormatFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhformatfromrawvalue)