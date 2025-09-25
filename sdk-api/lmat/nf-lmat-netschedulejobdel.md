# NetScheduleJobDel function

## Description

[**NetScheduleJobDel** is no longer available for use as of Windows 8. Instead, use the  [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces).

]

The
**NetScheduleJobDel** function deletes a range of jobs queued to run at a computer. This function requires that the schedule service be started at the computer to which the job deletion request is being sent.

## Parameters

### `Servername` [in, optional]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `MinJobId` [in]

The minimum job identifier. Jobs with a job identifier smaller than *MinJobId* will not be deleted.

### `MaxJobId` [in]

The maximum job identifier. Jobs with a job identifier larger than *MaxJobId* will not be deleted.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Normally only members of the local Administrators group on the computer where the schedule job is being deleted can successfully execute this function. If the server name passed in the string pointed to by the *Servername* parameter is a remote server, then only members of the local Administrators group on the server can successfully execute this function.

If the following registry value has the least significant bit set (for example, 0x00000001), then users belonging to the Server Operators group can also successfully execute this function.

**HKLM\System\CurrentControlSet\Control\Lsa\SubmitControl**

Call the
[NetScheduleJobEnum](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobenum) function to retrieve the job identifier for one or more scheduled jobs.

The
**NetScheduleJobDel** function deletes all jobs whose job identifiers are in the range *MinJobId* through *MaxJobId*.

To delete all scheduled jobs at the server, you can call
**NetScheduleJobDel** specifying *MinJobId* equal to 0 and *MaxJobId* equal to – 1. To delete one job, specify the job's identifier for both the *MinJobId* parameter and the *MaxJobId* parameter.

## See also

[NetScheduleJobAdd](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobadd)

[NetScheduleJobEnum](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobenum)

[NetScheduleJobGetInfo](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobgetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Schedule
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/schedule-functions)