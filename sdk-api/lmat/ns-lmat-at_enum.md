# AT_ENUM structure

## Description

The
**AT_ENUM** structure contains information about a submitted job. The
[NetScheduleJobEnum](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobenum) function uses this structure to enumerate and return information about an entire queue of submitted jobs.

## Members

### `JobId`

Type: **DWORD**

The job identifier of a submitted (queued) job.

### `JobTime`

Type: **DWORD_PTR**

A pointer to the time of day at which the job is scheduled to run. The time is the local time at a computer on which the schedule service is running; it is measured from midnight, and is expressed in milliseconds.

### `DaysOfMonth`

Type: **DWORD**

A set of bit flags representing the days of the month. For each bit that is set, the scheduled job will run at the time specified by the **JobTime** member, on the corresponding day of the month. Bit 0 corresponds to the first day of the month, and so on.

The value of the bitmask is zero if the job was scheduled to run only once, at the first occurrence specified in the **JobTime** member

### `DaysOfWeek`

Type: **UCHAR**

A set of bit flags representing the days of the week. For each bit that is set, the scheduled job will run at the time specified by the **JobTime** member, on the corresponding day of the week. Bit 0 corresponds to Monday, and so on.

The value of the bitmask is zero if the job was scheduled to run only once, at the first occurrence specified in the **JobTime** member.

### `Flags`

Type: **UCHAR**

A set of bit flags describing job properties. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_RUN_PERIODICALLY** | This flag is equal to its original value, that is, the value when the job was submitted. |
| **JOB_EXEC_ERROR** | If this flag is set, it indicates that the schedule service failed to successfully execute the job the last time it was scheduled to run. |
| **JOB_RUNS_TODAY** | If this flag is set, it indicates that the job is scheduled to execute on the current day; the value of the **JobTime** member is greater than the current time of day at the computer where the job is queued. |
| **JOB_NONINTERACTIVE** | This flag is equal to its original value, that is, the value when the job was submitted. |

### `Command`

Type: **LPWSTR**

A pointer to a Unicode string that contains the name of the command, batch program, or binary file to execute.

## Remarks

For more information about setting the bit flags to schedule jobs that execute once, jobs that execute multiple times, and jobs that execute periodically without deletion, see
the [NetScheduleJobAdd](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobadd) function.

## See also

[NetScheduleJobEnum](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobenum)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Schedule Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/schedule-functions)