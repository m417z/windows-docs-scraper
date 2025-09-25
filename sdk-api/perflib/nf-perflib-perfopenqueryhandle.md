# PerfOpenQueryHandle function

## Description

Creates a handle that references a query on the specified system. A query is a
list of counter specifications.

## Parameters

### `szMachine` [in, optional]

The name of the machine for which you want to get the query handle.

### `phQuery` [out]

The handle to the query. Call [PerfCloseQueryHandle](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfclosequeryhandle) to close ths handle when you no longer need it.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Use [PerfAddCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfaddcounters) and [PerfDeleteCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfdeletecounters) to
add or remove counter specifications to the list. Use [PerfQueryCounterInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterinfo) to
get the counter specifications currently in the list and to determine the
indexes at which the data for each counter will be returned by
[PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata). Use **PerfQueryCounterData** to retrieve the values of the
counters that match the counter specifications.

## See also

[PerfAddCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfaddcounters)

[PerfCloseQueryHandle](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfclosequeryhandle)

[PerfDeleteCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfdeletecounters)

[PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata)

[PerfQueryCounterInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterinfo)