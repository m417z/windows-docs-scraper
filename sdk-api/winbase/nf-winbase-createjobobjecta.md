# CreateJobObjectA function

## Description

Creates or opens a job object.

## Parameters

### `lpJobAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies the security descriptor for the job object and determines whether child processes can inherit the returned handle. If *lpJobAttributes* is **NULL**, the job object gets a default security descriptor and the handle cannot be inherited. The ACLs in the default security descriptor for a job object come from the primary or impersonation token of the creator.

### `lpName` [in, optional]

The name of the job. The name is limited to **MAX_PATH** characters. Name comparison is case-sensitive.

If *lpName* is **NULL**, the job is created without a name.

If *lpName* matches the name of an existing event, semaphore, mutex, waitable timer, or file-mapping object, the function fails and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_INVALID_HANDLE**. This occurs because these objects share the same namespace.

The object can be created in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

**Terminal Services:** The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces).

## Return value

If the function succeeds, the return value is a handle to the job object. The handle has the **JOB_OBJECT_ALL_ACCESS** access right. If the object existed before the function call, the function returns a handle to the existing job object and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_ALREADY_EXISTS**.

If the function fails, the return value is NULL. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When a job is created, its accounting information is initialized to zero, all limits are inactive, and there are no associated processes. To assign a process to a job object, use the
[AssignProcessToJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-assignprocesstojobobject) function. To set limits for a job, use the
[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) function. To query accounting information, use the
[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) function.

All processes associated with a job must run in the same session. A job is associated with the session of the first process to be assigned to the job.

**Windows Server 2003 and Windows XP:** A job is associated with the session of the process that created it.

To close a job object handle, use the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function. The job is destroyed when its last handle has been closed and all associated processes have exited. However, if the job has the **JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE** flag specified, closing the last job object handle terminates all associated processes and then destroys the job object itself.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[AssignProcessToJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-assignprocesstojobobject)

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[Job Objects](https://learn.microsoft.com/windows/desktop/ProcThread/job-objects)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)