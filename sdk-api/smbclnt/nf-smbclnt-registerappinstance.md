# RegisterAppInstance function

## Description

Registers the *AppInstance* ID for a process.

## Parameters

### `ProcessHandle` [in]

A process handle for the current process or a remote process to be tagged with the
*AppInstanceId*. To tag a remote process, the handle must have
**PROCESS_TERMINATE** access to that process.

### `AppInstanceId` [in]

The application instance ID, which is a **GUID**.

### `ChildrenInheritAppInstance` [in]

**TRUE** to tag the child processes spawned by the process specified by
*ProcessHandle*; otherwise, **FALSE**.

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | The CCF Filter failed to allocate the proper cache objects to fulfill this operation. |
| **ERROR_ACCESS_DENIED** | The current process that's trying to tag the process specified by *ProcessHandle* doesn't have **PROCESS_TERMINATE** access to that process. |
| **ERROR_INVALID_PARAMETER** | *ProcessHandle* is not a handle to a process. |
| **ERROR_NOT_FOUND** | The CCF mini-filter is not found. |
| **ERROR_OBJECT_ALREADY_EXISTS** | Another *AppInstance***GUID** is provided for the same process, which means that the [RegisterAppInstance](https://learn.microsoft.com/windows/desktop/api/smbclnt/nf-smbclnt-registerappinstance) function was called twice or the application was registered twice. |

## Remarks

The **RegisterAppInstance** function issues an
**IOCTL_CCF_REGISTER_APPINSTANCE** call to the CCF mini-filter. The function
passes the *AppInstance* **GUID**, the
process handle, and the tagged child processes to the CCF cache that maps the process handle to the
*AppInstanceId*.

The issued IOCTL for tagging another process checks if the current process has
**PROCESS_TERMINATE** access to the target process.

## See also

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)