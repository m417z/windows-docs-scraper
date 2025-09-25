# PdhSetCounterScaleFactor function

## Description

Sets the scale factor that is applied to the calculated value of the specified counter when you request the formatted counter value. If the PDH_FMT_NOSCALE flag is set, then this scale factor is ignored.

## Parameters

### `hCounter` [in]

Handle of the counter to apply the scale factor to. The
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function returns this handle.

### `lFactor` [in]

Power of ten by which to multiply the calculated value before returning it. The minimum value of this parameter is PDH_MIN_SCALE (–7), where the returned value is the actual value multiplied by 10–⁷. The maximum value of this parameter is PDH_MAX_SCALE (+7), where the returned value is the actual value multiplied by 10⁺⁷. A value of zero will set the scale to one, so that the actual value is returned.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | The scale value is out of range. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |

## See also

[PdhCalculateCounterFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcalculatecounterfromrawvalue)

[PdhComputeCounterStatistics](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcomputecounterstatistics)

[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue)