# PERF_STRING_COUNTER_HEADER structure

## Description

Indicates where in the [PERF_STRING_BUFFER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_buffer_header) block that the string that contains the name or help string for the indicated performance counter starts. The **PERF_STRING_COUNTER_HEADER** structure is part of the
[PERF_STRING_BUFFER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_buffer_header) block

## Members

### `dwCounterId`

The identifier of the performance counter.

### `dwOffset`

The number of bytes from the start of the
[PERF_STRING_BUFFER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_buffer_header) block to the null-terminated UTF-16LE data. A value of 0xFFFFFFFF indicates that the string is not present; in other words, that the value of the string is NULL.

## Remarks

The [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function called with the *requestCode* parameter set to
**PERF_REG_COUNTER_NAME_STRINGS** or **PERF_REG_COUNTER_HELP_STRINGS** gets a
[PERF_STRING_BUFFER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_buffer_header) block that contains one or more
**PERF_STRING_COUNTER_HEADER** structures.

## See also

[PERF_STRING_BUFFER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_buffer_header)

[PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo)