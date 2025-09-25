# PerfAddCounters function

## Description

Adds performance counter specifications to the specified query.

## Parameters

### `hQuery` [in]

A handle to the query to which you want to add performance counter specifications.

### `pCounters` [in, out]

A pointer to the performance counter specifications that you want to add.

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

For each [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) block:

* Set the **CounterSetGuid** member of the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) structure to the identifier of the counter set to be queried.
* Set the **Status** member of the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) structure to 0.
* Set **Size** member of the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) structure to the size of the **PERF_COUNTER_IDENTIFIER** block in bytes, including the
  **PERF_COUNTER_IDENTIFIER** structure, the instance name, and the padding. The
  value of **Size** must be a multiple of 8.
* Set the **CounterId** member of the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) structure to the identifier of the counter that should be returned by the query.
  To return all counters, set **CounterId** to **PERF_WILDCARD_COUNTER**.
* Set the **InstanceId** member of the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) structure to the identifier of the instance that should be returned by the
  query. If no filtering should be done based on instance identifier, set
  **InstanceId** to **PERF_WILDCARD_COUNTER**.
* Set the **Index** member of the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) structure to 0.
* Set the **Reserved** member of the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) structure to 0.
* Include the instance name immediately after the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) structure.
  + If the counter set is single-instance, do not set the instance name. In this case, the value of the Size member of the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) structure must be the size of the **PERF_COUNTER_IDENTIFIER** structure.
  + If the
    counter set is multiple-instance, you must set the instance name. If you do not want to filter the performance counter specifications based on instance name, use **PERF_WILDCARD_INSTANCE** as the
    instance name.

**PerfAddCounters** attempts to add one counter specification to the query for
each [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) block, and updates the **Status** member of the **PERF_COUNTER_IDENTIFIER** structure in each
block with the result of the attempt.

## See also

[PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier)

[PerfDeleteCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfdeletecounters)