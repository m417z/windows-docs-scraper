# PdhAddCounterW function

## Description

Adds the specified counter to the query.

## Parameters

### `hQuery` [in]

Handle to the query to which you want to add the counter. This handle is returned by the
[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function.

### `szFullCounterPath` [in]

Null-terminated string that contains the counter path. For details on the format of a counter path, see
[Specifying a Counter Path](https://learn.microsoft.com/windows/desktop/PerfCtrs/specifying-a-counter-path). The maximum length of a counter path is PDH_MAX_COUNTER_PATH.

### `dwUserData` [in]

User-defined value. This value becomes part of the counter information. To retrieve this value later, call the [PdhGetCounterInfo](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcounterinfoa) function and access the **dwUserData** member of the [PDH_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_info_a) structure.

### `phCounter` [out]

Handle to the counter that was added to the query. You may need to reference this handle in subsequent calls.

## Return value

Return ERROR_SUCCESS if the function succeeds.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_CSTATUS_BAD_COUNTERNAME** | The counter path could not be parsed or interpreted. |
| **PDH_CSTATUS_NO_COUNTER** | Unable to find the specified counter on the computer or in the log file. |
| **PDH_CSTATUS_NO_COUNTERNAME** | The counter path is empty. |
| **PDH_CSTATUS_NO_MACHINE** | The path did not contain a computer name, and the function was unable to retrieve the local computer name. |
| **PDH_CSTATUS_NO_OBJECT** | Unable to find the specified object on the computer or in the log file. |
| **PDH_FUNCTION_NOT_FOUND** | Unable to determine the calculation function to use for this counter. |
| **PDH_INVALID_ARGUMENT** | One or more arguments are not valid. |
| **PDH_INVALID_HANDLE** | The query handle is not valid. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | Unable to allocate memory required to complete the function. |

## Remarks

If the counter path contains a wildcard character, all counter names matching the wildcard character are added to the query.

If a counter instance is specified that does not yet exist,
**PdhAddCounter** does not report an error condition. Instead, it returns ERROR_SUCCESS. The reason for this behavior is that it is not known whether a nonexistent counter instance has been specified or whether one will exist but has not yet been created.

To remove the counter from the query, use the
[PdhRemoveCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhremovecounter) function.

#### Examples

For an example, see
[Browsing Performance Counters](https://learn.microsoft.com/windows/desktop/PerfCtrs/browsing-performance-counters) or
[Reading Performance Data from a Log File](https://learn.microsoft.com/windows/desktop/PerfCtrs/reading-performance-data-from-a-log-file).

> [!NOTE]
> The pdh.h header defines PdhAddCounter as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhAddEnglishCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddenglishcountera)

[PdhBrowseCounters](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersa)

[PdhMakeCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhmakecounterpatha)

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)

[PdhRemoveCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhremovecounter)