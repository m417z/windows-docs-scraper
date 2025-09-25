# NetScheduleJobAdd function

## Description

[**NetScheduleJobAdd** is no longer available for use as of Windows 8. Instead, use the  [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces).

]

The
**NetScheduleJobAdd** function submits a job to run at a specified future time and date. This function requires that the schedule service be started on the computer to which the job is submitted.

## Parameters

### `Servername` [in, optional]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `Buffer` [in]

A pointer to an
[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure describing the job to submit. For more information about scheduling jobs using different job properties, see the following Remarks section and
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `JobId` [out]

A pointer that receives a job identifier for the newly submitted job. This entry is valid only if the function returns successfully.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Normally only members of the local Administrators group on the computer where the schedule job is being added can successfully execute this function. If the server name passed in the string pointed to by the *Servername* parameter is a remote server, then only members of the local Administrators group on the remote server can successfully execute this function.

If the following registry value has the least significant bit set (for example, 0x00000001), then users belonging to the Server Operators group can also successfully execute this function.

**HKLM\System\CurrentControlSet\Control\Lsa\SubmitControl**

The following are examples of how to schedule jobs using different properties supported by the
**NetScheduleJobAdd** function.

To schedule a job that executes once:

* Set the **DaysOfMonth** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure to zero.
* Set the **DaysOfWeek** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure to zero.
* Set the **JobTime** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure to the time the job should execute.

The job executes at the time specified by the **JobTime** member of the
[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure pointed to by the *Buffer* parameter. After the job executes, it is deleted.

To schedule and delete a job that executes multiple times:

* Set the appropriate bits in the **DaysOfMonth** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure or
* Set the appropriate bits in the **DaysOfWeek** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure.
* Set the **JobTime** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure to the time the job should execute.

**Note** You do not need to set both the **DaysOfMonth** and the **DaysOfWeek** members of the
[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure.

The job executes at the time specified by the **JobTime** member of the
[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure pointed to by the *Buffer* parameter, once for each day set in the **DaysOfMonth** or **DaysOfWeek** members of the
[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure. After each job executes, the corresponding bit is cleared. When the last bit is cleared, the job is deleted.

To schedule a job that executes periodically:

* Set the appropriate bits in the **DaysOfMonth** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure or
* Set the appropriate bits in the **DaysOfWeek** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure.
* Set the **JobTime** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure to the time the job should execute.
* Set the job submission flag JOB_RUN_PERIODICALLY in the **Flags** member of the
  [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure.

**Note** You do not need to set both the **DaysOfMonth** and the **DaysOfWeek** members of the
[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure.

The job will execute periodically, at the time specified by the **JobTime** member of the
[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure pointed to by the *Buffer* parameter, on each day set in the **DaysOfMonth** or **DaysOfWeek** member of the
[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure. The job will not be deleted as a result of the repeated executions. The only way to delete the job is by an explicit call to the
[NetScheduleJobDel](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobdel) function.

See
the [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure for a description of the **DaysOfWeek**, **DaysOfMonth**, and job property bitmasks.

On Windows 2000, the earlier AT service and the Task Scheduler were combined. The Task Scheduler service was only accurate to the minute. Therefore, the **NetScheduleJobAdd** function only uses hours and minutes specified in the **JobTime** member of the [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure when a job is scheduled to run.

Starting with Windows Vista, the precision for the Task Scheduler was increased to the second. Therefore, the **NetScheduleJobAdd** function uses only the hours, minutes, and seconds specified in the **JobTime** member of the [AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info) structure when a job is scheduled to run.

## See also

[AT_INFO](https://learn.microsoft.com/windows/desktop/api/lmat/ns-lmat-at_info)

[NetScheduleJobDel](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobdel)

[NetScheduleJobEnum](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobenum)

[NetScheduleJobGetInfo](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobgetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Schedule
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/schedule-functions)