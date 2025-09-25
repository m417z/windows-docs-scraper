# FaxGetJobA function

## Description

A fax client application calls the **FaxGetJob** function to retrieve detailed information for the specified queued or active fax job. The function returns the information in a [FAX_JOB_ENTRY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_entrya) structure.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `JobId` [in]

Type: **DWORD**

Specifies a unique number that identifies a queued or active fax job. The job can be an inbound or an outbound transmission.

### `JobEntry` [out]

Type: **PFAX_JOB_ENTRY***

Pointer to the address of a buffer to receive a [FAX_JOB_ENTRY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_entrya) structure. The data includes the job type and status, recipient and sender identification, scheduling and delivery settings, and the page count. For information about memory allocation, see the following Remarks section.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_JOB_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_PARAMETER** | The *JobId* parameter is invalid, or one or both of the *JobEntry* or *FaxHandle* parameters are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

The **FaxGetJob** function retrieves information about an individual fax job. To retrieve information about all queued and active jobs on the fax server of interest, call the [FaxEnumJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumjobsa) function.

The **FaxGetJob** function allocates the memory required for the buffer pointed to by the *JobEntry* parameter. An application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function to deallocate the resources associated with this parameter.

For more information, see [Managing Fax Jobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-jobs) and [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

> [!NOTE]
> The winfax.h header defines FaxGetJob as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_JOB_ENTRY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_entrya)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxEnumJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumjobsa)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxSetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetjoba)