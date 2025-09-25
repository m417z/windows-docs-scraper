# NetScheduleJobGetInfo function

## Description

[**NetScheduleJobGetInfo** is no longer available for use as of Windows 8. Instead, use the  [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces).

]

The
**NetScheduleJobGetInfo** function retrieves information about a particular job queued on a specified computer. This function requires that the schedule service be started.

## Parameters

### `Servername` [in, optional]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `JobId` [in]

A value that indicates the identifier of the job for which to retrieve information.

### `PointerToBuffer` [out]

A pointer to the buffer that receives the
[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure describing the specified job. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Normally only members of the local Administrators group on the computer where the schedule job is being enumerated can successfully execute this function. If the server name passed in the string pointed to by the *Servername* parameter is a remote server, then only members of the local Administrators group on the server can successfully execute this function.

If the following registry value has the least significant bit set (for example, 0x00000001), then users belonging to the Server Operators group can also successfully execute this function.

**HKLM\System\CurrentControlSet\Control\Lsa\SubmitControl**

## See also

[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info)

[NetScheduleJobAdd](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobadd)

[NetScheduleJobDel](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobdel)

[NetScheduleJobEnum](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Schedule
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/schedule-functions)