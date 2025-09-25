# PFAXABORT callback function

## Description

A fax client application calls the **FaxAbort** function to terminate a fax job.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `JobId` [in]

Type: **DWORD**

Specifies a unique number that identifies the fax job to terminate.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. You must own the job, or have [FAX_JOB_MANAGE](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access. |
| **ERROR_INVALID_HANDLE** | The *FaxHandle* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | The *JobId* parameter is invalid. |

## Remarks

An application typically calls the **FaxAbort** function to terminate a fax transmission that is in progress. To manage a queued fax job, an application typically calls the [FaxSetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetjoba) function. **FaxSetJob** can cancel an active job; the function can also pause, resume, cancel, or restart a queued fax job.

Call the [FaxEnumJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumjobsa) function to retrieve a valid value to use in the *JobId* parameter.

For more information, see [Modifying a Fax Job](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-modifying-a-fax-job) and [Terminating a Fax Job](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-terminating-a-fax-job).

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxEnumJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumjobsa)

[FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta)

[FaxSetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetjoba)

[FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba)