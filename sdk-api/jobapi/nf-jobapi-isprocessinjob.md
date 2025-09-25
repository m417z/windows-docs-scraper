# IsProcessInJob function

## Description

Determines whether the process is running in the specified job.

## Parameters

### `ProcessHandle` [in]

A handle to the process to be tested. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the PROCESS_QUERY_INFORMATION access right.

### `JobHandle` [in, optional]

A handle to the job. If this parameter is NULL, the function tests if the process is running under any job.

If this parameter is not NULL, the handle must have the JOB_OBJECT_QUERY access right. For more information, see [Job Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/job-object-security-and-access-rights).

### `Result` [out]

A pointer to a value that receives TRUE if the process is running in the job, and FALSE otherwise.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application cannot obtain a handle to the job object in which it is running unless it has the name of the job object. However, an application can call the [QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) function with NULL to obtain information about the job object.

To compile an application that uses this function, define _WIN32_WINNT as 0x0501 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[AssignProcessToJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-assignprocesstojobobject)

[Job Objects](https://learn.microsoft.com/windows/desktop/ProcThread/job-objects)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)