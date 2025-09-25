# PerfRegInfoType enumeration

## Description

Indicates the types of information that you can request about a performance counter set by calling the [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function.

## Constants

### `PERF_REG_COUNTERSET_STRUCT:1`

Gets the registration information for a counter set and all of the counters it contains as a [PERF_COUNTERSET_REG_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_reg_info) block. The block includes a **PERF_COUNTERSET_REG_INFO** structure followed by one or

 more [PERF_COUNTER_REG_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_reg_info) structures.

### `PERF_REG_COUNTER_STRUCT`

Gets the registration information for a performance counter as a [PERF_COUNTER_REG_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_reg_info) structure.

 Use the *requestLangId* parameter of the [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function to specify the counter identifier.

### `PERF_REG_COUNTERSET_NAME_STRING`

Gets a null-terminated UTF16-LE string that indicates the name of the counter set.

 Use the *requestLangId* parameter of the [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function to specify the preferred locale of the result.

### `PERF_REG_COUNTERSET_HELP_STRING`

Gets a null-terminated UTF16-LE string that contains the help string for the counter set.

 Use the *requestLangId* parameter of the [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function to specify the preferred locale of the result.

### `PERF_REG_COUNTER_NAME_STRINGS`

 Gets the names of the performance counters in the counter set as a [PERF_STRING_BUFFER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_buffer_header) block.

 The block includes a **PERF_STRING_BUFFER_HEADER** structure, followed by one

 or more [PERF_STRING_COUNTER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_counter_header) structures, followed by string data that indicates the counter names.

 Use the *requestLangId* parameter of the [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function to specify the preferred locale of the result.

### `PERF_REG_COUNTER_HELP_STRINGS`

Gets the help strings for the performance counters in the counter set as a [PERF_STRING_BUFFER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_buffer_header) block.

 The block includes a **PERF_STRING_BUFFER_HEADER** structure, followed by one

 or more [PERF_STRING_COUNTER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_counter_header) structures, followed by string data that contains the help strings.

 Use the *requestLangId* parameter of the [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function to specify the preferred locale of the result.

### `PERF_REG_PROVIDER_NAME`

Gets a null-terminated UTF-16LE string that indicates the name of the provider for the counter set.

### `PERF_REG_PROVIDER_GUID`

Gets the GUID of the provider for the counter set.

### `PERF_REG_COUNTERSET_ENGLISH_NAME`

Gets a null-terminated UTF-16LE string that contains the name of the counter set in English. This value is equivalent to setting the *requestCode* parameter to **PERF_REG_COUNTERSET_NAME_STRING** and the *requestLangId* parameter to 0 when you call the [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function.

### `PERF_REG_COUNTER_ENGLISH_NAMES`

Gets the English names of the performance counters in the counter set as a [PERF_STRING_BUFFER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_buffer_header) block.

 The block includes a **PERF_STRING_BUFFER_HEADER** structure, followed by one

 or more [PERF_STRING_COUNTER_HEADER](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_string_counter_header) structures, followed by string data that indicates the counter names. This value is equivalent to setting the *requestCode* parameter to **PERF_REG_COUNTER_NAME_STRINGS** and the *requestLangId* parameter to 0 when you call the [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function.

## See also

[PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo)