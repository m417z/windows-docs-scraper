# NetScheduleJobEnum function

## Description

[**NetScheduleJobEnum** is no longer available for use as of Windows 8. Instead, use the  [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces).

]

The
**NetScheduleJobEnum** function lists the jobs queued on a specified computer. This function requires that the schedule service be started.

## Parameters

### `Servername` [in, optional]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `PointerToBuffer` [out]

A pointer to the buffer that receives the data. The return information is an array of
[AT_ENUM](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_enum) structures. The buffer is allocated by the system and must be freed using a single call to the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.

### `PrefferedMaximumLength` [in]

A value that indicates the preferred maximum length of the returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `EntriesRead` [out]

A pointer to a value that receives the count of elements actually enumerated.

### `TotalEntries` [out]

A pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint.

### `ResumeHandle` [in, out]

A pointer to a value that contains a resume handle which is used to continue a job enumeration. The handle should be zero on the first call and left unchanged for subsequent calls. If this parameter is **NULL**, then no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Normally only members of the local Administrators group on the computer where the schedule job is being enumerated can successfully execute this function. If the server name passed in the string pointed to by the *Servername* parameter is a remote server, then only members of the local Administrators group on the server can successfully execute this function.

If the following registry value has the least significant bit set (for example, 0x00000001), then users belonging to the Server Operators group can also successfully execute this function.

**HKLM\System\CurrentControlSet\Control\Lsa\SubmitControl**

Each entry returned contains an
[AT_ENUM](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_enum) structure. The value of the **JobId** member can be used when calling functions that require a job identifier parameter, such as the
[NetScheduleJobDel](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobdel) function.

## See also

[AT_ENUM](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_enum)

[NetScheduleJobAdd](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobadd)

[NetScheduleJobDel](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobdel)

[NetScheduleJobGetInfo](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobgetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Schedule
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/schedule-functions)