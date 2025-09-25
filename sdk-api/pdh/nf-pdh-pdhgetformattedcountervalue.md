# PdhGetFormattedCounterValue function

## Description

Computes a displayable value for the specified counter.

## Parameters

### `hCounter` [in]

Handle of the counter for which you want to compute a displayable value. The
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function returns this handle.

### `dwFormat` [in]

Determines the data type of the formatted value. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_FMT_DOUBLE** | Return data as a double-precision floating point real. |
| **PDH_FMT_LARGE** | Return data as a 64-bit integer. |
| **PDH_FMT_LONG** | Return data as a long integer. |

You can use the bitwise inclusive OR operator (|) to combine the data type with one of the following scaling factors.

| Value | Meaning |
| --- | --- |
| **PDH_FMT_NOSCALE** | Do not apply the counter's default scaling factor. |
| **PDH_FMT_NOCAP100** | Counter values greater than 100 (for example, counter values measuring the processor load on multiprocessor computers) will not be reset to 100. The default behavior is that counter values are capped at a value of 100. |
| **PDH_FMT_1000** | Multiply the actual value by 1,000. |

### `lpdwType` [out]

Receives the counter type. For a list of counter types, see the Counter Types section of the [Windows Server 2003 Deployment Kit](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc776490(v=ws.10)). This parameter is optional.

### `pValue` [out]

A
[PDH_FMT_COUNTERVALUE](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue) structure that receives the counter value.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid or is incorrectly formatted. |
| **PDH_INVALID_DATA** | The specified counter does not contain valid data or a successful status code. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |

## Remarks

The data for the counter is locked (protected) for the duration of the call to
**PdhGetFormattedCounterValue** to prevent any changes during the processing of the call. Reading the data (calling this function successfully) clears the data-changed flag for the counter.

Some counters, such as rate counters, require two counter values in order to compute a displayable value. In this case you must call [PdhCollectQueryData](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcollectquerydata) twice before calling
**PdhGetFormattedCounterValue**. For more information, see [Collecting Performance Data](https://learn.microsoft.com/windows/desktop/PerfCtrs/collecting-performance-data).

If
the specified counter instance does not exist, the method will return PDH_INVALID_DATA and set the **CStatus** member of the
[PDH_FMT_COUNTERVALUE](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue) structure to PDH_CSTATUS_NO_INSTANCE.

**Prior to Windows Server 2003:** The format call may fail for counters that require only a single value when the instance is not found. Try calling the query and format calls again. If the format call fails the second time, the instance is not found. As an alternative, you can call the [PdhEnumObjects](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectsa) function with the refresh option set to **TRUE** to refresh the counter instances before querying and formatting the counter data.

#### Examples

For an example, see
[Browsing Performance Counters](https://learn.microsoft.com/windows/desktop/PerfCtrs/browsing-performance-counters) or
[Reading Performance Data from a Log File](https://learn.microsoft.com/windows/desktop/PerfCtrs/reading-performance-data-from-a-log-file).

## See also

[PdhCollectQueryData](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcollectquerydata)

[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue)

[PdhSetCounterScaleFactor](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhsetcounterscalefactor)