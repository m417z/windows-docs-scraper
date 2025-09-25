# OpenJobObjectW function

## Description

Opens an existing job object.

## Parameters

### `dwDesiredAccess` [in]

The access to the job object. This parameter can be one or more of the
[job object access rights](https://learn.microsoft.com/windows/desktop/ProcThread/job-object-security-and-access-rights). This access right is checked against any security descriptor for the object.

### `bInheritHandle` [in]

If this value is TRUE, processes created by this process will inherit the handle. Otherwise, the processes do not inherit this handle.

### `lpName` [in]

The name of the job to be opened. Name comparisons are case sensitive.

This function can open objects in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

**Terminal Services:** The name can have a "Global\\" or "Local\\" prefix to explicitly open the object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces).

## Return value

If the function succeeds, the return value is a handle to the job. The handle provides the requested access to the job.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To associate a process with a job, use the
[AssignProcessToJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-assignprocesstojobobject) function.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[AssignProcessToJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-assignprocesstojobobject)

[Job Objects](https://learn.microsoft.com/windows/desktop/ProcThread/job-objects)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)