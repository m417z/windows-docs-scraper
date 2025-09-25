# SetAppInstanceCsvFlags function

## Description

Sets the flags that affect connections from the application instance.

## Parameters

### `ProcessHandle` [in]

A process handle for the current process or a remote process to be tagged with the
application instance. To tag a remote process, the handle must have
**PROCESS_TERMINATE** access to that process.

### `Mask` [in]

A bitmask that indicates the flags that are modified by the *Flags* parameter.

### `Flags` [in]

New values of the flags.

## Return value

Returns "0" if the operation is successful; otherwise, one of the following error codes is returned:

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | The CCF filter failed to allocate the cache objects for the operation. |
| **ERROR_ACCESS_DENIED** | The current process that's trying to tag the process specified by *ProcessHandle* doesn't have **PROCESS_TERMINATE** access to that process. |
| **ERROR_NOT_FOUND** | The CCF mini-filter was not found. |

## See also

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)