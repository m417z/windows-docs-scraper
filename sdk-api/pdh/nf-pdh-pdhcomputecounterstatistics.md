# PdhComputeCounterStatistics function

## Description

Computes statistics for a counter from an array of raw values.

## Parameters

### `hCounter` [in]

Handle of the counter for which you want to compute statistics. The
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function returns this handle.

### `dwFormat` [in]

Determines the data type of the formatted value. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_FMT_DOUBLE** | Return the calculated value as a double-precision floating point real. |
| **PDH_FMT_LARGE** | Return the calculated value as a 64-bit integer. |
| **PDH_FMT_LONG** | Return the calculated value as a long integer. |

You can use the bitwise inclusive OR operator (|) to combine the data type with one of the following scaling factors.

| Value | Meaning |
| --- | --- |
| **PDH_FMT_NOSCALE** | Do not apply the counter's scaling factors in the calculation. |
| **PDH_FMT_NOCAP100** | Counter values greater than 100 (for example, counter values measuring the processor load on multiprocessor computers) will not be reset to 100. The default behavior is that counter values are capped at a value of 100. |
| **PDH_FMT_1000** | Multiply the final value by 1,000. |

### `dwFirstEntry` [in]

Zero-based index of the first raw counter value to use to begin the calculations. The index value must point to the oldest entry in the buffer. The
function starts at this entry and scans through the buffer, wrapping at the last entry back to the beginning of the buffer and up to the *dwFirstEntry-1* entry, which is assumed to be the newest or most recent data.

### `dwNumEntries` [in]

Number of raw counter values in the *lpRawValueArray* buffer.

### `lpRawValueArray` [in]

Array of
[PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter) structures that contain *dwNumEntries* entries.

### `data` [out]

A
[PDH_STATISTICS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_statistics) structure that receives the counter statistics.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | An argument is not correct or is incorrectly formatted. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |

## See also

[PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter)

[PDH_STATISTICS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_statistics)

[PdhCalculateCounterFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcalculatecounterfromrawvalue)

[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue)

[PdhSetCounterScaleFactor](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhsetcounterscalefactor)