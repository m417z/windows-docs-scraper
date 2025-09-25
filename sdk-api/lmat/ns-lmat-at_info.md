# AT_INFO structure

## Description

The
**AT_INFO** structure contains information about a job. The
[NetScheduleJobAdd](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobadd) function uses the structure to specify information when scheduling a job. The
[NetScheduleJobGetInfo](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobgetinfo) function uses the structure to retrieve information about a job that has already been submitted.

## Members

### `JobTime`

Type: **DWORD_PTR**

A pointer to a value that indicates the time of day at which the job is scheduled to run. The time is the local time at a computer on which the schedule service is running; it is measured from midnight, and is expressed in milliseconds.

### `DaysOfMonth`

Type: **DWORD**

A set of bit flags representing the days of the month. For each bit that is set, the scheduled job will run at the time specified by the **JobTime** member, on the corresponding day of the month. Bit 0 corresponds to the first day of the month, and so on.

The value of the bitmask is zero if the job was scheduled to run only once, at the first occurrence specified by the **JobTime** member.

### `DaysOfWeek`

Type: **UCHAR**

A set of bit flags representing the days of the week. For each bit that is set, the scheduled job will run at the time specified by the **JobTime** member, on the corresponding day of the week. Bit 0 corresponds to Monday, and so on.

The value of the bitmask is zero if the job was scheduled to run only once, at the first occurrence specified by the **JobTime** member.

### `Flags`

Type: **UCHAR**

A set of bit flags describing job properties.

 When you submit a job using a call to the
[NetScheduleJobAdd](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobadd) function, you can specify one of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_RUN_PERIODICALLY** | If you set this flag, the job runs, and continues to run, on each day for which a corresponding bit is set in the **DaysOfMonth** member or the **DaysOfWeek** member. The job is not deleted after it executes. <br><br>If this flag is clear, the job runs only once for each bit set in these members. The job is deleted after it executes once. |
| **JOB_ADD_CURRENT_DATE** | If you set this flag, the job executes at the first occurrence of **JobTime** member at the computer where the job is queued. <br><br>Setting this flag is equivalent to setting the bit for the current day in the **DaysOfMonth** member. |
| **JOB_NONINTERACTIVE** | If you set this flag, the job does not run interactively. <br><br>If this flag is clear, the job runs interactively. |

 When you call
[NetScheduleJobGetInfo](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobgetinfo) to retrieve job information, the function can return one or more of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_RUN_PERIODICALLY** | This flag is equal to its original value, that is, the value when the job was submitted. |
| **JOB_EXEC_ERROR** | If this flag is set, it indicates that the schedule service failed to successfully execute the job the last time it was scheduled to run. |
| **JOB_RUNS_TODAY** | If this flag is set, it indicates that the job is scheduled to execute on the current day; the value of the **JobTime** member is greater than the current time of day at the computer where the job is queued. |
| **JOB_NONINTERACTIVE** | This flag bit is equal to its original value, that is, the value when the job was submitted. |

### `Command`

Type: **LPWSTR**

A pointer to a Unicode string that contains the name of the command, batch program, or binary file to execute.

## Remarks

For more information about scheduling jobs that execute once, jobs that execute multiple times, and jobs that execute periodically without deletion, see
[NetScheduleJobAdd](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobadd).

## See also

[NetScheduleJobAdd](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobadd)

[NetScheduleJobGetInfo](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobgetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Schedule Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/schedule-functions)