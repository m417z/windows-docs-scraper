# PERF_STRING_BUFFER_HEADER structure

## Description

Provides information about the **PERF_STRING_BUFFER_HEADER** block that contains the structure. The **PERF_STRING_BUFFER_HEADER** block provides the names or help strings for the performance counters in a counter set, amd consists of the following items in order:

1. A **PERF_STRING_BUFFER_HEADER** structure
2. A number of [PERF_STRING_COUNTER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_counter_header) structures. The **dwCounters** member of the **PERF_STRING_BUFFER_HEADER** structure specifies how many **PERF_STRING_COUNTER_HEADER** structures the **PERF_STRING_BUFFER_HEADER** block contains.
3. A block of string data.

## Members

### `dwSize`

The total size of the **PERF_STRING_BUFFER_HEADER** block, in bytes. This total size is the sum of the sizes of the **PERF_STRING_BUFFER_HEADER** structure, all of the [PERF_STRING_COUNTER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_counter_header) structures, and the block of string data.

### `dwCounters`

The number of [PERF_STRING_COUNTER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_counter_header) structures in the **PERF_STRING_BUFFER_HEADER** block.

## Remarks

The [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function called with the *requestCode* parameter set to
**PERF_REG_COUNTER_NAME_STRINGS** or **PERF_REG_COUNTER_HELP_STRINGS** gets a
**PERF_STRING_BUFFER_HEADER** block.

## See also

[PERF_STRING_COUNTER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_counter_header)

[PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo)