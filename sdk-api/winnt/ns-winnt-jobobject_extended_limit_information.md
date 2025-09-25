# JOBOBJECT_EXTENDED_LIMIT_INFORMATION structure

## Description

Contains basic and extended limit information for a job object.

## Members

### `BasicLimitInformation`

A
[JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information) structure that contains basic limit information.

### `IoInfo`

Reserved.

### `ProcessMemoryLimit`

If the **LimitFlags** member of the
[JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information) structure specifies the **JOB_OBJECT_LIMIT_PROCESS_MEMORY** value, this member specifies the limit for the virtual memory that can be committed by a process. Otherwise, this member is ignored.

### `JobMemoryLimit`

If the **LimitFlags** member of the
[JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information) structure specifies the **JOB_OBJECT_LIMIT_JOB_MEMORY** value, this member specifies the limit for the virtual memory that can be committed for the job. Otherwise, this member is ignored.

### `PeakProcessMemoryUsed`

The peak memory used by any process ever associated with the job.

### `PeakJobMemoryUsed`

The peak memory usage of all processes currently associated with the job.

## Remarks

The system tracks the value of **PeakProcessMemoryUsed** and **PeakJobMemoryUsed** constantly. This allows you know the peak memory usage of each job. You can use this information to establish a memory limit using the **JOB_OBJECT_LIMIT_PROCESS_MEMORY** or **JOB_OBJECT_LIMIT_JOB_MEMORY** value.

Note that the job memory and process memory limits are very similar in operation, but they are independent. You could set a job-wide limit of 100 MB with a per-process limit of 10 MB. In this scenario, no single process could commit more than 10 MB, and the set of processes associated with a job could never exceed 100 MB.

To register for notifications that a job has exceeded its peak memory limit while allowing processes to continue to commit memory, use the [SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) function with the **JobObjectNotificationLimitInformation** information class.

## See also

[JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information)

[JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_notification_limit_information)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)