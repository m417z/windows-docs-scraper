# SetIoRateControlInformationJobObject function

## Description

**Windows 10, version 1607, and newer: This function is not supported.**

Sets I/O limits on a job object.

## Parameters

### `hJob` [in]

A handle to the job on which to set I/O limits. Get this handle from the [CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta) or [OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta) function. The handle must have the **JOB_OBJECT_SET_ATTRIBUTES** access right. For more information about access rights, see [Job Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/job-object-security-and-access-rights).

### `IoRateControlInfo` [in]

A pointer to a [JOBOBJECT_IO_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/jobapi2/ns-jobapi2-jobobject_io_rate_control_information) structure that specifies the I/O limits to set for the job.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also

[JOBOBJECT_IO_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/jobapi2/ns-jobapi2-jobobject_io_rate_control_information)

[QueryIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryioratecontrolinformationjobobject)