# JOBOBJECT_BASIC_LIMIT_INFORMATION structure

## Description

Contains basic limit information for a job object.

## Members

### `PerProcessUserTimeLimit`

If **LimitFlags** specifies **JOB_OBJECT_LIMIT_PROCESS_TIME**, this member is the per-process user-mode execution time limit, in 100-nanosecond ticks. Otherwise, this member is ignored.

The system periodically checks to determine whether each process associated with the job has accumulated more user-mode time than the set limit. If it has, the process is terminated.

If the job is nested, the effective limit is the most restrictive limit in the job chain.

### `PerJobUserTimeLimit`

If **LimitFlags** specifies **JOB_OBJECT_LIMIT_JOB_TIME**, this member is the per-job user-mode execution time limit, in 100-nanosecond ticks. Otherwise, this member is ignored.

The system adds the current time of the processes associated with the job to this limit. For example, if you set this limit to 1 minute, and the job has a process that has accumulated 5 minutes of user-mode time, the limit actually enforced is 6 minutes.

The system periodically checks to determine whether the sum of the user-mode execution time for all processes is greater than this end-of-job limit. If it is, the action specified in the **EndOfJobTimeAction** member of the
[JOBOBJECT_END_OF_JOB_TIME_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_end_of_job_time_information) structure is carried out. By default, all processes are terminated and the status code is set to **ERROR_NOT_ENOUGH_QUOTA**.

To register for notification when this limit is exceeded without terminating processes, use the [SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) function with the **JobObjectNotificationLimitInformation** information class.

### `LimitFlags`

The limit flags that are in effect. This member is a bitfield that determines whether other structure members are used. Any combination of the following values can be specified.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_LIMIT_ACTIVE_PROCESS**<br><br>0x00000008 | Establishes a maximum number of simultaneously active processes associated with the job. The **ActiveProcessLimit** member contains additional information. |
| **JOB_OBJECT_LIMIT_AFFINITY**<br><br>0x00000010 | Causes all processes associated with the job to use the same processor affinity. The **Affinity** member contains additional information.<br><br>If the job is nested, the specified processor affinity must be a subset of the effective affinity of the parent job. If the specified affinity a superset of the affinity of the parent job, it is ignored and the affinity of the parent job is used. |
| **JOB_OBJECT_LIMIT_BREAKAWAY_OK**<br><br>0x00000800 | If any process associated with the job creates a child process using the **CREATE_BREAKAWAY_FROM_JOB** flag while this limit is in effect, the child process is not associated with the job. <br><br>This limit requires use of a [JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information) structure. Its **BasicLimitInformation** member is a **JOBOBJECT_BASIC_LIMIT_INFORMATION** structure. |
| **JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION**<br><br>0x00000400 | Forces a call to the [SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode) function with the **SEM_NOGPFAULTERRORBOX** flag for each process associated with the job. <br><br>If an exception occurs and the system calls the [UnhandledExceptionFilter](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-unhandledexceptionfilter) function, the debugger will be given a chance to act. If there is no debugger, the functions returns **EXCEPTION_EXECUTE_HANDLER**. Normally, this will cause termination of the process with the exception code as the exit status.<br><br>This limit requires use of a [JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information) structure. Its **BasicLimitInformation** member is a **JOBOBJECT_BASIC_LIMIT_INFORMATION** structure. |
| **JOB_OBJECT_LIMIT_JOB_MEMORY**<br><br>0x00000200 | Causes all processes associated with the job to limit the job-wide sum of their committed memory. When a process attempts to commit memory that would exceed the job-wide limit, it fails. If the job object is associated with a completion port, a **JOB_OBJECT_MSG_JOB_MEMORY_LIMIT** message is sent to the completion port.<br><br>This limit requires use of a [JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information) structure. Its **BasicLimitInformation** member is a **JOBOBJECT_BASIC_LIMIT_INFORMATION** structure.<br><br>To register for notification when this limit is exceeded while allowing processes to continue to commit memory, use the [SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) function with the **JobObjectNotificationLimitInformation** information class. |
| **JOB_OBJECT_LIMIT_JOB_TIME**<br><br>0x00000004 | Establishes a user-mode execution time limit for the job. The **PerJobUserTimeLimit** member contains additional information. This flag cannot be used with **JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME**. |
| **JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE**<br><br>0x00002000 | Causes all processes associated with the job to terminate when the last handle to the job is closed.<br><br>This limit requires use of a [JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information) structure. Its **BasicLimitInformation** member is a **JOBOBJECT_BASIC_LIMIT_INFORMATION** structure. |
| **JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME**<br><br>0x00000040 | Preserves any job time limits you previously set. As long as this flag is set, you can establish a per-job time limit once, then alter other limits in subsequent calls. This flag cannot be used with **JOB_OBJECT_LIMIT_JOB_TIME**. |
| **JOB_OBJECT_LIMIT_PRIORITY_CLASS**<br><br>0x00000020 | Causes all processes associated with the job to use the same priority class. For more information, see [Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities). The **PriorityClass** member contains additional information.<br><br>If the job is nested, the effective priority class is the lowest priority class in the job chain. |
| **JOB_OBJECT_LIMIT_PROCESS_MEMORY**<br><br>0x00000100 | Causes all processes associated with the job to limit their committed memory. When a process attempts to commit memory that would exceed the per-process limit, it fails. If the job object is associated with a completion port, a **JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT** message is sent to the completion port.<br><br>If the job is nested, the effective memory limit is the most restrictive memory limit in the job chain.<br><br>This limit requires use of a [JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information) structure. Its **BasicLimitInformation** member is a **JOBOBJECT_BASIC_LIMIT_INFORMATION** structure. |
| **JOB_OBJECT_LIMIT_PROCESS_TIME**<br><br>0x00000002 | Establishes a user-mode execution time limit for each currently active process and for all future processes associated with the job. The **PerProcessUserTimeLimit** member contains additional information. |
| **JOB_OBJECT_LIMIT_SCHEDULING_CLASS**<br><br>0x00000080 | Causes all processes in the job to use the same scheduling class. The **SchedulingClass** member contains additional information.<br><br>If the job is nested, the effective scheduling class is the lowest scheduling class in the job chain. |
| **JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK**<br><br>0x00001000 | Allows any process associated with the job to create child processes that are not associated with the job. <br><br>If the job is nested and its immediate job object allows breakaway, the child process breaks away from the immediate job object and from each job in the parent job chain, moving up the hierarchy until it reaches a job that does not permit breakaway. If the immediate job object does not allow breakaway, the child process does not break away even if jobs in its parent job chain allow it.<br><br>This limit requires use of a [JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information) structure. Its **BasicLimitInformation** member is a **JOBOBJECT_BASIC_LIMIT_INFORMATION** structure. |
| **JOB_OBJECT_LIMIT_SUBSET_AFFINITY**<br><br>0x00004000 | Allows processes to use a subset of the processor affinity for all processes associated with the job. This value must be combined with **JOB_OBJECT_LIMIT_AFFINITY**. <br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is supported starting with Windows 7 and Windows Server 2008 R2. |
| **JOB_OBJECT_LIMIT_WORKINGSET**<br><br>0x00000001 | Causes all processes associated with the job to use the same minimum and maximum working set sizes. The **MinimumWorkingSetSize** and **MaximumWorkingSetSize** members contain additional information.<br><br>If the job is nested, the effective working set size is the smallest working set size in the job chain. |

### `MinimumWorkingSetSize`

If **LimitFlags** specifies **JOB_OBJECT_LIMIT_WORKINGSET**, this member is the minimum working set size in bytes for each process associated with the job. Otherwise, this member is ignored.

If **MaximumWorkingSetSize** is nonzero, **MinimumWorkingSetSize** cannot be zero.

### `MaximumWorkingSetSize`

If **LimitFlags** specifies **JOB_OBJECT_LIMIT_WORKINGSET**, this member is the maximum working set size in bytes for each process associated with the job. Otherwise, this member is ignored.

If **MinimumWorkingSetSize** is nonzero, **MaximumWorkingSetSize** cannot be zero.

### `ActiveProcessLimit`

If **LimitFlags** specifies **JOB_OBJECT_LIMIT_ACTIVE_PROCESS**, this member is the active process limit for the job. Otherwise, this member is ignored.

If you try to associate a process with a job, and this causes the active process count to exceed this limit, the process is terminated and the association fails.

### `Affinity`

If **LimitFlags** specifies **JOB_OBJECT_LIMIT_AFFINITY**, this member is the processor affinity for all processes associated with the job. Otherwise, this member is ignored.

The affinity must be a subset of the system affinity mask obtained by calling the
[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask) function. The affinity of each thread is set to this value, but threads are free to subsequently set their affinity, as long as it is a subset of the specified affinity mask. Processes cannot set their own affinity mask.

### `PriorityClass`

If **LimitFlags** specifies **JOB_OBJECT_LIMIT_PRIORITY_CLASS**, this member is the priority class for all processes associated with the job. Otherwise, this member is ignored.

Processes and threads cannot modify their priority class. The calling process must enable the **SE_INC_BASE_PRIORITY_NAME** privilege.

### `SchedulingClass`

If **LimitFlags** specifies **JOB_OBJECT_LIMIT_SCHEDULING_CLASS**, this member is the scheduling class for all processes associated with the job. Otherwise, this member is ignored.

The valid values are 0 to 9. Use 0 for the least favorable scheduling class relative to other threads, and 9 for the most favorable scheduling class relative to other threads. By default, this value is 5. To use a scheduling class greater than 5, the calling process must enable the **SE_INC_BASE_PRIORITY_NAME** privilege.

## Remarks

Processes can still empty their working sets using the
[SetProcessWorkingSetSize](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsize) function with (**SIZE_T**)-1, even when **JOB_OBJECT_LIMIT_WORKINGSET** is used. However, you cannot use **SetProcessWorkingSetSize** change the minimum or maximum working set size of a process in a job object.

The system increments the active process count when you attempt to associate a process with a job. If the limit is exceeded, the system decrements the active process count only when the process terminates and all handles to the process are closed. Therefore, if you have an open handle to a process that has been terminated in such a manner, you cannot associate any new processes until the handle is closed and the active process count is below the limit.

## See also

[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask)

[JOBOBJECT_END_OF_JOB_TIME_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_end_of_job_time_information)

[JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information)

[JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_notification_limit_information)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)

[SetProcessWorkingSetSize](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsize)