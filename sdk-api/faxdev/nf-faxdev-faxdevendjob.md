# FaxDevEndJob function

## Description

The fax service calls the **FaxDevEndJob** function after the last fax operation in a fax job. Each fax service provider (FSP) must export the **FaxDevEndJob** function.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax handle returned by the [FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The FSP should perform necessary cleanup tasks for the fax job when the fax service calls **FaxDevEndJob**. Cleanup should include deallocation of memory for any job-specific instance data that was allocated in the call to the [FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob) function.

Note that if the fax service calls **FaxDevEndJob**, it will also call the **FaxDevEndJob** function, even if an operation has been terminated by the [FaxDevAbortOperation](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevabortoperation) function.

## See also

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevAbortOperation](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevabortoperation)

[FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)