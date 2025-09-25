# JOBOBJECT_BASIC_ACCOUNTING_INFORMATION structure

## Description

Contains basic accounting information for a job object.

## Members

### `TotalUserTime`

The total amount of user-mode execution time for all active processes associated with the job, as well as all terminated processes no longer associated with the job, in 100-nanosecond ticks.

### `TotalKernelTime`

The total amount of kernel-mode execution time for all active processes associated with the job, as well as all terminated processes no longer associated with the job, in 100-nanosecond ticks.

### `ThisPeriodTotalUserTime`

The total amount of user-mode execution time for all active processes associated with the job (as well as all terminated processes no longer associated with the job) since the last call that set a per-job user-mode time limit, in 100-nanosecond ticks.

This member is set to 0 on creation of the job, and each time a per-job user-mode time limit is established.

### `ThisPeriodTotalKernelTime`

The total amount of kernel-mode execution time for all active processes associated with the job (as well as all terminated processes no longer associated with the job) since the last call that set a per-job kernel-mode time limit, in 100-nanosecond ticks.

This member is set to zero on creation of the job, and each time a per-job kernel-mode time limit is established.

### `TotalPageFaultCount`

The total number of page faults encountered by all active processes associated with the job, as well as all terminated processes no longer associated with the job.

### `TotalProcesses`

The total number of processes associated with the job during its lifetime, including those that have terminated. For example, when a process is associated with a job, but the association fails because of a limit violation, this value is incremented.

### `ActiveProcesses`

The total number of processes currently associated with the job. When a process is associated with a job, but the association fails because of a limit violation, this value is temporarily incremented. When the terminated process exits and all references to the process are released, this value is decremented.

### `TotalTerminatedProcesses`

The total number of processes terminated because of a limit violation.

## See also

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)