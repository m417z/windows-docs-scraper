# PerfQueryCounterData function

## Description

Gets the values of the performance counters that match the counter specifications in the
specified query.

## Parameters

### `hQuery` [in]

A handle to a query for the counter specifications of the performance counters for which you want to get the values.

### `pCounterBlock` [out, optional]

A pointer to a buffer that has enough space to receive the amount of data that the *cbCounterBlock* parameter specifies, in bytes. May be NULL if

*cbCounterBlock* is 0.

### `cbCounterBlock`

The size of the buffer that the *pCounterBlock* parameter specifies, in bytes.

### `pcbCounterBlockActual` [out]

The size of the buffer actually required to get the performance counter values. The meaning depends on the value that the function

returns.

| Function Return Value | Meaning of *pcbCounterBlockActual* |
| --- | --- |
| **ERROR_SUCCESS** | The number of <br><br> bytes of performance counter values that the function stored in the buffer that *pCounterBlock* specified. |
| **ERROR_NOT_ENOUGH_MEMORY** | The <br><br> size of the buffer required to store the performance counter values, in bytes. Enlarge the buffer to the required <br><br> size and call the function again. |
| Other | The value is undefined and should not be used. |

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function successfully stored all of the requested performance counter values in the buffer that *pCounterBlock* specified. The value that *pcbCounterBlockActual* points to indicates amount of information actually stored in the buffer, in bytes. |
| **ERROR_NOT_ENOUGH_MEMORY** | The buffer that *pCounterBlock* specified was not large enough to store all of the requested performance counter values. The value that *pcbCounterBlockActual* points to indicates the size of the buffer required to store all of the information. Enlarge the buffer to the required <br><br> size and call the function again. |

For other types of failures, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The information about the performance counter values is written to the buffer that *pCounterBlock* specifies as a [PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header) block, which consists **PERF_DATA_HEADER** structure followed by a sequence of [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) blocks.

## See also

[PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header)

[PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header)