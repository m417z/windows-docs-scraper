# RmGetList function

## Description

Gets a list of all applications and services that are currently using resources that have been registered with the Restart Manager session.

## Parameters

### `dwSessionHandle` [in]

A handle to an existing Restart Manager session.

### `pnProcInfoNeeded` [out]

A pointer to an array size necessary to receive [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structures required to return information for all affected applications and services.

### `pnProcInfo` [in, out]

A pointer to the total number of [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structures in an array and number of structures filled.

### `rgAffectedApps` [in, out, optional]

An array of [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structures that list the applications and services using resources that have been registered with the session.

### `lpdwRebootReasons` [out]

Pointer to location that receives a value of the [RM_REBOOT_REASON](https://learn.microsoft.com/windows/desktop/api/restartmanager/ne-restartmanager-rm_reboot_reason) enumeration that describes the reason a system restart is needed.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The function completed successfully. |
| **ERROR_MORE_DATA**<br><br>234 | This error value is returned by the [RmGetList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetlist) function if the *rgAffectedApps* buffer is too small to hold all application information in the list. |
| **ERROR_CANCELLED**<br><br>1223 | The current operation is canceled by user. |
| **ERROR_SEM_TIMEOUT**<br><br>121 | A Restart Manager function could not obtain a Registry write mutex in the allotted time. A system restart is recommended because further use of the Restart Manager is likely to fail. |
| **ERROR_BAD_ARGUMENTS**<br><br>160 | One or more arguments are not correct. This error value is returned by the Restart Manager function if a **NULL** pointer or 0 is passed in a parameter that requires a non-**null** and non-zero value. |
| **ERROR_WRITE_FAULT**<br><br>29 | An operation was unable to read or write to the registry. |
| **ERROR_OUTOFMEMORY**<br><br>14 | A Restart Manager operation could not complete because not enough memory was available. |
| **ERROR_INVALID_HANDLE**<br><br>6 | No Restart Manager session exists for the handle supplied. |
| **ERROR_ACCESS_DENIED**<br><br>5 | A path registered to the Restart Manager session is a directory. |

## See also

[RmCancelCurrentTask](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmcancelcurrenttask)