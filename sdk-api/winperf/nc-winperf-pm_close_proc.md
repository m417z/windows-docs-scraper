# PM_CLOSE_PROC callback function

## Description

Performs the cleanup required by your performance DLL. Implement and export this function if you are writing a performance DLL to provide performance data. The system calls this function whenever a consumer closes the registry key used to collect performance data.

The **ClosePerformanceData** function is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

## Return value

This function should return ERROR_SUCCESS.

## See also

[CollectPerformanceData](https://learn.microsoft.com/windows/desktop/api/winperf/nc-winperf-pm_collect_proc)

[OpenPerformanceData](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa372200(v=vs.85))