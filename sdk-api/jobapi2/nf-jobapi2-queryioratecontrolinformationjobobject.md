# QueryIoRateControlInformationJobObject function

## Description

**Windows 10, version 1607, and newer: This function is not supported.**

Gets information about the control of the I/O rate for a job object.

## Parameters

### `hJob` [in, optional]

A handle to the job to query for information. Get this handle from the [CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta) or [OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta) function. The handle must have the **JOB_OBJECT_QUERY** access right. For more information about access rights, see [Job Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/job-object-security-and-access-rights).

If this value is NULL and the process that calls **QueryIoRateControlInformationJobObject** is associated with a job, the function uses job that is associated with the process. If the job is nested within another job, the function uses the immediate job for the process.

### `VolumeName` [in, optional]

The name of the volume to query. If this value is NULL, the function gets the information about I/O rate control for the job for all of the volumes for the system.

### `InfoBlocks` [out]

A pointer to array of [JOBOBJECT_IO_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/jobapi2/ns-jobapi2-jobobject_io_rate_control_information) structures that contain the information about I/O rate control for the job. Your code must free the memory for this array by calling the [FreeMemoryJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-freememoryjobobject) function with the address of the array.

### `InfoBlockCount` [out]

The number of [JOBOBJECT_IO_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/jobapi2/ns-jobapi2-jobobject_io_rate_control_information) structures that the function allocated in the array to which the *InfoBlocks* parameter points.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also

[FreeMemoryJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-freememoryjobobject)

[JOBOBJECT_IO_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/jobapi2/ns-jobapi2-jobobject_io_rate_control_information)

[SetIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setioratecontrolinformationjobobject)