# FaxDevAbortOperation function

## Description

The fax service calls the **FaxDevAbortOperation** function to request that the fax service provider (FSP) terminate the active fax operation for the fax job specified by the *FaxHandle* parameter. Each FSP must export the **FaxDevAbortOperation** function.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax handle returned by the [FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **FaxDevAbortOperation** function is called asynchronously on an execution thread that is independent of the fax operation. It is usually necessary to synchronize access by multiple threads. For more information, see [Synchronizing Execution of Multiple Threads](https://learn.microsoft.com/windows/desktop/ProcThread/synchronizing-execution-of-multiple-threads).

**FaxDevAbortOperation** should return after posting the abort request, rather than wait for the fax operation to end before returning.

## See also

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevEndJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevendjob)

[FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)