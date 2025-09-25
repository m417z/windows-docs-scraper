# FaxSetJobA function

## Description

A fax client application calls the **FaxSetJob** function to pause, resume, cancel, or restart a specified fax job.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `JobId` [in]

Type: **DWORD**

Specifies a **DWORD** variable that is a unique number to identify the fax job to modify. Call the [FaxEnumJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumjobsa) function to retrieve a valid fax job identifier to use in the *JobId* parameter.

### `Command` [in]

Type: **DWORD**

Specifies a **DWORD** variable that indicates the job command to perform. This parameter can be one of the following values.

#### JC_DELETE

Cancel the specified fax job. The job can be active or queued.

#### JC_PAUSE

Pause the specified queued fax job. If the fax job is active, the fax service pauses the job when it returns to the queued state.

#### JC_RESUME

Resume the paused fax job.

#### JC_RESTART

Restart the specified fax job.

### `JobEntry` [in]

Type: **const [FAX_JOB_ENTRY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_entrya)***

Not used, must be **NULL**.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_JOB_MANAGE](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_PARAMETER** | The *FaxHandle* parameter is **NULL**, or one or all of the *Command*, *JobEntry*, or *JobId* parameters are invalid. |

## Remarks

An application typically calls the **FaxSetJob** function to manage a queued fax job. To terminate a fax transmission that is in progress, an application can call the [FaxAbort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxabort) function.

For more information, see [Modifying a Fax Job](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-modifying-a-fax-job) and [Terminating a Fax Job](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-terminating-a-fax-job).

> [!NOTE]
> The winfax.h header defines FaxSetJob as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_JOB_ENTRY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_entrya)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxAbort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxabort)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxEnumJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumjobsa)

[FaxGetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetjoba)

[FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta)

[FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba)