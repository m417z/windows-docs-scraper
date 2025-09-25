# PdhBindInputDataSourceW function

## Description

Binds one or more binary log files together for reading log data.

## Parameters

### `phDataSource` [out]

Handle to the bound data sources.

### `LogFileNameList` [in]

**Null**-terminated string that contains one or more binary log files to bind together. Terminate each log file name with a **null**-terminator character and the list with one additional **null**-terminator character. The log file names can contain absolute or relative paths. You cannot specify more than 32 log files.

If **NULL**, the source is a real-time data source.

## Return value

Returns ERROR_SUCCESS if the function succeeds.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

## Remarks

This function is used with the PDH functions that require a handle to a data source. For a list of these functions, see See Also.

You cannot specify more than one comma-delimited (CSV) or tab-delimited (TSV) file. The list can contain only one type of file—you cannot combine multiple file types.

To close the bound log files, call the [PdhCloseLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcloselog) function using the log handle.

> [!NOTE]
> The pdh.h header defines PdhBindInputDataSource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhBrowseCountersH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersha)

[PdhEnumMachinesH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenummachinesha)

[PdhEnumObjectItemsH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectitemsha)

[PdhEnumObjectsH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectsha)

[PdhExpandWildCardPathH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandwildcardpathha)

[PdhGetDataSourceTimeRangeH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdatasourcetimerangeh)

[PdhGetDefaultPerfCounterH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdefaultperfcounterha)

[PdhGetDefaultPerfObjectH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdefaultperfobjectha)

[PdhOpenQueryH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenqueryh)