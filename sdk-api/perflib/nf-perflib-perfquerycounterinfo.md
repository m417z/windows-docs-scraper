# PerfQueryCounterInfo function

## Description

Gets the counter specifications in the specified query.

## Parameters

### `hQuery` [in]

A handle to the query for which you want to get the counter specifications

### `pCounters` [out, optional]

Pointer to a buffer that is large enough to hold the amount of data that the *cbCounters* parameter specifies, in bytes. May be
NULL if *cbCounters* is 0.

### `cbCounters`

The size of the *pCounters* buffer, in bytes.

### `pcbCountersActual` [out]

The size of the buffer actually required to get the counter specifications. The meaning depends on the value that the function

returns.

| Function Return Value | Meaning of *pcbCountersActual* |
| --- | --- |
| **ERROR_SUCCESS** | The number of <br><br> bytes of information about the counter specifications that the function stored in the buffer that *pCounters* specified. |
| **ERROR_NOT_ENOUGH_MEMORY** | The <br><br> size of the buffer required to store the information about the counter specifications, in bytes. Enlarge the buffer to the required <br><br> size and call the function again. |
| Other | The value is undefined and should not be used. |

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function successfully stored all of the information about the counter specifications in the buffer that *pCounters* specified. The value that *pcbCountersActual* points to indicates amount of information actually stored in the buffer, in bytes. |
| **ERROR_NOT_ENOUGH_MEMORY** | The buffer that *pCounters* specified was not large enough to store all of the information about the counter specifications. The value that *pcbCountersActual* points to indicates the size of the buffer required to store all of the information. Enlarge the buffer to the required <br><br> size and call the function again. |

For other types of failures, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The information about the counter specifications is written to the buffer that *pCounters* specifies as a sequence of [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) blocks. The size in bytes of

the sequence of blocks is written to *pcbCountersActual*. Each **PERF_COUNTER_IDENTIFIER** block consists

of a **PERF_COUNTER_IDENTIFIER** structure, optionally followed by a null-terminated UTF-16LE

instance name, followed by padding so that the size of the

**PERF_COUNTER_IDENTIFIER** block is a multiple of 8 bytes.
The size of each block, including the **PERF_COUNTER_IDENTIFIER** structure, instance name,
and padding, is determined by the **Size** member of the **PERF_COUNTER_IDENTIFIER** structure, which
will be a multiple of 8 bytes.

## See also

[PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier)