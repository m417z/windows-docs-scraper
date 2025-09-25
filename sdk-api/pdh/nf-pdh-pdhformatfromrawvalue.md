# PdhFormatFromRawValue function

## Description

Computes a displayable value for the given raw counter values.

## Parameters

### `dwCounterType` [in]

Type of counter. Typically, you call [PdhGetCounterInfo](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcounterinfoa) to retrieve the counter type at the time you call [PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue) to retrieve the raw counter value.

For a list of counter types, see the Counter Types section of the [Windows Server 2003 Deployment Kit](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc776490(v=ws.10)). (The constant values are defined in Winperf.h.)

Note that you cannot specify base types, for example, PERF_LARGE_RAW_BASE.

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

### `pTimeBase` [in]

Pointer to the time base, if necessary for the format conversion. If time base information is not necessary for the format conversion, the value of this parameter is ignored. To retrieve the time base of the counter, call [PdhGetCounterTimeBase](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcountertimebase).

### `pRawValue1` [in]

Raw counter value used to compute the displayable counter value. For details, see [PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter).

### `pRawValue2` [in]

Raw counter value used to compute the displayable counter value. For details, see [PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter). Some counters, for example, rate counters, require two raw values to calculate a displayable value. If the counter type does not require a second value, set this parameter to **NULL**. This value must be the older of the two raw values.

### `pFmtValue` [out]

A
[PDH_FMT_COUNTERVALUE](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue) structure that receives the calculated counter value.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

## See also

[PDH_FMT_COUNTERVALUE](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue)

[PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter)

[PdhGetCounterInfo](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcounterinfoa)

[PdhGetCounterTimeBase](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcountertimebase)

[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue)

[PdhReadRawLogRecord](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhreadrawlogrecord)