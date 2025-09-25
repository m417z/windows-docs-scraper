# PdhOpenQueryH function

## Description

Creates a new query that is used to manage the collection of performance data.

This function is identical to
the [PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function, except that it supports the use of handles to data sources.

## Parameters

### `hDataSource` [in]

Handle to a data source returned by the
[PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea) function.

### `dwUserData` [in]

User-defined value to associate with this query. To retrieve the user data later, call
the [PdhGetCounterInfo](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetcounterinfoa) function and access the **dwQueryUserData** member of [PDH_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_info_a).

### `phQuery` [out]

Handle to the query. You use this handle in subsequent calls.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

## See also

[PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea)