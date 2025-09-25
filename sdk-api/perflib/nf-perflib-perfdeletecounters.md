# PerfDeleteCounters function

## Description

Removes the specified performance counter specifications from the specified query.

## Parameters

### `hQuery` [in]

A handle to the query from which you want to remove performance counter specifications.

### `pCounters` [in, out]

A pointer to the performance counter specifications that you want to remove.

### `cbCounters`

The size of the buffer that the *pCounters* parameter specifies, in bytes.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The *pCounters* parameter should point to a sequence of [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) blocks. Each **PERF_COUNTER_IDENTIFIER** block consists of a
**PERF_COUNTER_IDENTIFIER** structure, optionally followed by a null-terminated
UTF-16LE instance name string, followed by padding that makes the size of the block a multiple of 8 bytes.

Configure each [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) block in the same way as described in the Remarks for [PerfAddCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfaddcounters).

**PerfDeleteCounters** attempts to remove one counter specification from the
query for each [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) block, and updates the **Status** member of the **PERF_COUNTER_IDENTIFIER** structure in each
block with the result of the attempt.

## See also

[PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier)

[PerfAddCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfaddcounters)