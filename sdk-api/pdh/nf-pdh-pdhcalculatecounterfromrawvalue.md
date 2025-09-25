# PdhCalculateCounterFromRawValue function

## Description

Calculates the displayable value of two raw counter values.

## Parameters

### `hCounter` [in]

Handle to the counter to calculate. The function uses information from the counter to determine how to calculate the value. This handle is returned by the
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function.

### `dwFormat` [in]

Determines the data type of the calculated value. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_FMT_DOUBLE** | Return the calculated value as a double-precision floating point real. |
| **PDH_FMT_LARGE** | Return the calculated value as a 64-bit integer. |
| **PDH_FMT_LONG** | Return the calculated value as a long integer. |

You can use the bitwise inclusive OR operator (|) to combine the data type with one of the following scaling factors.

| Value | Meaning |
| --- | --- |
| **PDH_FMT_NOSCALE** | Do not apply the counter's scaling factor in the calculation. |
| **PDH_FMT_NOCAP100** | Counter values greater than 100 (for example, counter values measuring the processor load on multiprocessor computers) will not be reset to 100. The default behavior is that counter values are capped at a value of 100. |
| **PDH_FMT_1000** | Multiply the final value by 1,000. |

### `rawValue1` [in]

Raw counter value used to compute the displayable counter value. For details, see the [PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter) structure.

### `rawValue2` [in]

Raw counter value used to compute the displayable counter value. For details, see [PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter). Some counters (for example, rate counters) require two raw values to calculate a displayable value. If the counter type does not require a second value, set this parameter to **NULL**. This value must be the older of the two raw values.

### `fmtValue` [out]

A
[PDH_FMT_COUNTERVALUE](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue) structure that receives the calculated counter value.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | An argument is not correct or is incorrectly formatted. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |

## Remarks

To retrieve the current raw counter value from the query, call the [PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue) function.

## See also

[PDH_FMT_COUNTERVALUE](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue)

[PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter)

[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue)

[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue)

[PdhSetCounterScaleFactor](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhsetcounterscalefactor)