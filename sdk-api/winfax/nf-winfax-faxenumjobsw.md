# FaxEnumJobsW function

## Description

The **FaxEnumJobs** function enumerates all queued and active fax jobs on the fax server to which the client has connected. The function returns detailed information for each fax job to the fax client application.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `JobEntry` [out]

Type: **PFAX_JOB_ENTRY***

Pointer to the address of a buffer to receive an array of [FAX_JOB_ENTRY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_entrya) structures. Each structure describes one fax job. The data includes, among other items, the job type and status; recipient and sender identification; scheduling and delivery settings; and the page count. For information about memory allocation, see the following Remarks section.

### `JobsReturned` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive the number of [FAX_JOB_ENTRY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_entrya) structures the function returns in the *JobEntry* parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_JOB_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_PARAMETER** | One or all of the *JobsReturned*, *JobEntry*, or *FaxHandle* parameters are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

The **FaxEnumJobs** function returns a list of fax jobs on the fax server of interest, as well as information available about each job. A fax administration application typically calls this function to display the fax job queue for administrative or query purposes. For more information, see [Managing Fax Jobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-jobs).

The **FaxEnumJobs** function allocates the memory required for the [FAX_JOB_ENTRY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_entrya) buffer array pointed to by the *JobEntry* parameter. An application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

> [!NOTE]
> The winfax.h header defines FaxEnumJobs as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_JOB_ENTRY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_entrya)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxGetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetjoba)