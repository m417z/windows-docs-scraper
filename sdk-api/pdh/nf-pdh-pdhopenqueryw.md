# PdhOpenQueryW function

## Description

Creates a new query that is used to manage the collection of performance data.

To use handles to data sources, use the
[PdhOpenQueryH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenqueryh) function.

## Parameters

### `szDataSource` [in]

**Null**-terminated string that specifies the name of the log file from which to retrieve performance data. If **NULL**, performance data is collected from a real-time data source.

### `dwUserData` [in]

User-defined value to associate with this query. To retrieve the user data later, call
[PdhGetCounterInfo](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcounterinfoa) and access the **dwQueryUserData** member of [PDH_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_info_a).

### `phQuery` [out]

Handle to the query. You use this handle in subsequent calls.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

## See also

[PdhCloseQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhclosequery)

[PdhGetCounterInfo](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcounterinfoa)

[PdhIsRealTimeQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhisrealtimequery)

[PdhOpenQueryH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenqueryh)

[PdhSetDefaultRealTimeDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhsetdefaultrealtimedatasource)

## Remarks

> [!NOTE]
> The pdh.h header defines PdhOpenQuery as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).