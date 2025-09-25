# PdhAddEnglishCounterW function

## Description

Adds the specified language-neutral counter to the query.

## Parameters

### `hQuery` [in]

Handle to the query to which you want to add the counter. This handle is returned by the
[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function.

### `szFullCounterPath` [in]

Null-terminated string that contains the counter path. For details on the format of a counter path, see
[Specifying a Counter Path](https://learn.microsoft.com/windows/desktop/PerfCtrs/specifying-a-counter-path). The maximum length of a counter path is PDH_MAX_COUNTER_PATH.

### `dwUserData` [in]

User-defined value. This value becomes part of the counter information. To retrieve this value later, call the [PdhGetCounterInfo](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcounterinfoa) function and access the **dwQueryUserData** member of the [PDH_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_info_a) structure.

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
| **PDH_CSTATUS_NO_MACHINE** | The path did not contain a computer name and the function was unable to retrieve the local computer name. |
| **PDH_CSTATUS_NO_OBJECT** | Unable to find the specified object on the computer or in the log file. |
| **PDH_FUNCTION_NOT_FOUND** | Unable to determine the calculation function to use for this counter. |
| **PDH_INVALID_ARGUMENT** | One or more arguments are not valid. |
| **PDH_INVALID_HANDLE** | The query handle is not valid. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | Unable to allocate memory required to complete the function. |

## Remarks

This function provides a language-neutral way to add performance counters to the query. In contrast, the counter path that you specify in the [PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function must be localized.

If a counter instance is specified that does not yet exist,
**PdhAddEnglishCounter** does not report an error condition. Instead, it returns ERROR_SUCCESS. The reason for this behavior is that it is not known whether a nonexistent counter instance has been specified or whether one will exist but has not yet been created.

To remove the counter from the query, use the
[PdhRemoveCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhremovecounter) function.

**Note** If the counter path contains a wildcard character, the non-wildcard portions of the path will be localized, but wildcards will not be expanded before adding the localized counter path to the query. In this case, you will need use the following procedure to add all matching counter names to the query.

1. Make a query
2. Use **PdhAddEnglishCounter** with the string containing wildcards
3. Use [PdhGetCounterInfo](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcounterinfoa) on the counter handle returned by **PdhAddEnglishCounter** to get a localized full path (*szFullPath*.) This string still contains wildcards, but the non-wildcard parts are now localized.
4. Use [PdhExpandWildCardPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandwildcardpatha) to expand the wildcards.
5. Use [PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) on each of the resulting paths

> [!NOTE]
> The pdh.h header defines PdhAddEnglishCounter as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera)

[PdhBrowseCounters](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersa)

[PdhMakeCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhmakecounterpatha)

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)

[PdhRemoveCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhremovecounter)