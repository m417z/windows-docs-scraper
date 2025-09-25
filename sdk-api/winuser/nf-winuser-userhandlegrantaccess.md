# UserHandleGrantAccess function

## Description

Grants or denies access to a handle to a User object to a job that has a user-interface restriction. When access is granted, all processes associated with the job can subsequently recognize and use the handle. When access is denied, the processes can no longer use the handle. For more information see
[User Objects](https://learn.microsoft.com/windows/desktop/SysInfo/user-objects).

## Parameters

### `hUserHandle` [in]

A handle to the User object.

### `hJob` [in]

A handle to the job to be granted access to the User handle. The
[CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta) or
[OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta) function returns this handle.

### `bGrant` [in]

If this parameter is TRUE, all processes associated with the job can recognize and use the handle. If the parameter is FALSE, the processes cannot use the handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**UserHandleGrantAccess** function can be called only from a process not associated with the job specified by the *hJob* parameter. The User handle must not be owned by a process or thread associated with the job.

To create user-interface restrictions, call the
[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) function with the JobObjectBasicUIRestrictions job information class.

## See also

[CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta)

[Job Objects](https://learn.microsoft.com/windows/desktop/ProcThread/job-objects)

[OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)