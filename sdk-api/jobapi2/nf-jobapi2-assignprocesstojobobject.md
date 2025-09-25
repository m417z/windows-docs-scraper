# AssignProcessToJobObject function

## Description

Assigns a process to an existing job object.

## Parameters

### `hJob` [in]

A handle to the job object to which the process will be associated. The
[CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta) or
[OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta) function returns this handle. The handle must have the JOB_OBJECT_ASSIGN_PROCESS access right. For more information, see
[Job Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/job-object-security-and-access-rights).

### `hProcess` [in]

A handle to the process to associate with the job object. The handle must have the PROCESS_SET_QUOTA and PROCESS_TERMINATE access rights. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

If the process is already associated with a job, the job specified by *hJob* must be empty or it must be in the hierarchy of nested jobs to which the process already belongs, and it cannot have UI limits set ([SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) with **JobObjectBasicUIRestrictions**). For more information, see Remarks.

**Windows 7, Windows Server 2008 R2, Windows XP with SP3, Windows Server 2008, Windows Vista and Windows Server 2003:** The process must not already be assigned to a job; if it is, the function fails with ERROR_ACCESS_DENIED. This behavior changed starting in Windows 8 and Windows Server 2012.

**Terminal Services:** All processes within a job must run within the same session as the job.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After you associate a process with a job object using
**AssignProcessToJobObject**, the process is subject to the limits set for the job. To set limits for a job, use the
[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) function.

If the job has a user-mode time limit, and the time limit has been exhausted,
**AssignProcessToJobObject** fails and the specified process is terminated. If the time limit would be exceeded by associating the process,
**AssignProcessToJobObject** still succeeds. However, the time limit violation will be reported. If the job has an active process limit, and the limit would be exceeded by associating this process,
**AssignProcessToJobObject** fails, and the specified process is terminated.

Memory operations performed by a process associated with a job that has a memory limit are subject to the memory limit. Memory operations performed by the process before it was associated with the job are not examined by
**AssignProcessToJobObject**.

If the process is already running and the job has security limitations,
**AssignProcessToJobObject** may fail. For example, if the primary token of the process contains the local administrators group, but the job object has the security limitation JOB_OBJECT_SECURITY_NO_ADMIN, the function fails. If the job has the security limitation JOB_OBJECT_SECURITY_ONLY_TOKEN, the process must be created suspended. To create a suspended process, call the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function with the CREATE_SUSPENDED flag.

A process can be associated with more than one job in a hierarchy of nested jobs. For priority class, affinity, commit charge, per-process execution time limit, scheduling class limit, and working set minimum and maximum, the process inherits an effective limit which is the most restrictive limit of all the jobs in its parent job chain. For other resource limits, the process inherits limits from its immediate job in the hierarchy. Accounting information is added to the immediate job and aggregated in each parent job in the job chain. By default, all child processes are associated with the immediate job and every job in the parent job chain. To create a child process that is not part of the same job chain, call the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function with the CREATE_BREAKAWAY_FROM_JOB flag. The child process breaks away from every job in the job chain unless a job in the chain does not allow breakaway. In this case, the child process does not break away from that job or any job above it in the job chain. For more information, see [Nested Jobs](https://learn.microsoft.com/windows/desktop/ProcThread/nested-jobs).

**Windows 7, Windows Server 2008 R2, Windows XP with SP3, Windows Server 2008, Windows Vista and Windows Server 2003:** A process can be associated only with a single job. A process inherits limits from the job it is associated with and adds its accounting information to the job. If a process is associated with a job, all child processes it creates are associated with that job by default. To create a child process that is not part of the same job, call the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function with the CREATE_BREAKAWAY_FROM_JOB flag. A process can be associated with more than one job starting in Windows 8 and Windows Server 2012.

**Windows 7, Windows Server 2008 R2, Windows Server 2008 and Windows Vista:** If the process is being monitored by the Program Compatibility Assistant (PCA), it is placed into a compatibility job. Therefore, the process must be created using CREATE_BREAKAWAY_FROM_JOB before it can be placed in another job. Alternatively, you can embed an application manifest that specifies a User Account Control (UAC) level in your application and PCA will not add the process to the compatibility job. For more information, see [Application Development Requirements for User Account Control Compatibility](https://learn.microsoft.com/previous-versions/dotnet/articles/bb530410(v=msdn.10)).

If the job or any of its parent jobs in the job chain is terminating when **AssignProcessToJob** is called, the function fails.

To compile an application that uses this function, define _WIN32_WINNT as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[Job Objects](https://learn.microsoft.com/windows/desktop/ProcThread/job-objects)

[OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)