# FaxSendDocumentW function

## Description

A fax client application calls the **FaxSendDocument** function to queue a fax job that will transmit an outgoing fax transmission.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `FileName` [in]

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that contains the fully qualified path and name of the file that contains the fax document to transmit. The path can be a UNC path or a path that begins with a drive letter.

This parameter can contain any valid local file name. The file must be a properly registered file type, and the fax server must be able to access the file.

### `JobParams` [in]

Type: **PFAX_JOB_PARAM**

Pointer to a [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure that contains the information necessary for the fax server to send the fax transmission. The structure includes, among other items, the recipient's fax number, sender and recipient data, an optional billing code, and job scheduling information.

### `CoverpageInfo` [in, optional]

Type: **const [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa)***

Pointer to a [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) structure that contains personal data to display on the cover page of the fax document. This parameter must be **NULL** if a cover page is not required.

### `FaxJobId` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive a unique number that identifies the queued job that will send the fax transmission.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or all of the *FaxHandle*, *JobParams*, or *FileName* parameters are **NULL**; the call handle specified by the **CallHandle** member of the [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure is invalid (should be **NULL**), or the **RecipientNumber** member in the **FAX_JOB_PARAM** structure is **NULL**. |
| **ERROR_INVALID_FUNCTION** | The *FaxHandle* parameter specifies a remote connection, but the **CallHandle** member of the [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure is not **NULL**. |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_JOB_SUBMIT](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_FILE_NOT_FOUND** | The fax server cannot locate the file specified by the *FileName* or the *CoverpageInfo* parameter. |
| **ERROR_INVALID_DATA** | The fax server cannot process the file specified by the *FileName* or the *CoverpageInfo* parameter. |
| **ERROR_NOT_SUPPORTED** | An attempt was made to hand off a voice call to send a fax, using the **CallHandle** member of the [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure. This functionality is not supported. |

## Remarks

Call the [FaxCompleteJobParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxcompletejobparamsa) function before calling the FaxSendDocument function. **FaxCompleteJobParams** is a utility function that fills in multiple members in the [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) and [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structures, with information such as the sender's name, the fax number, and optional billing code information.

The **FaxSendDocument** function executes asynchronously, and the function returns immediately. The fax server queues the job to send the fax transmission according to the details specified by the [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure.

For **FaxSendDocument** to succeed, there must be a remote fax printer installed on the fax server.

To send a fax document efficiently to multiple recipients, an application should call the **FaxSendDocument** function multiple times. The [FaxSendDocumentForBroadcast](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumentforbroadcasta) function is supported for backward compatibility.

When you send a document from an application, links in the document may cause a dialog to appear, requesting information. If you do not handle the information request within several minutes, **FaxSendDocument** will fail and return an error.

> [!NOTE]
> The winfax.h header defines FaxSendDocument as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa)

[FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxCompleteJobParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxcompletejobparamsa)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxSendDocumentForBroadcast](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumentforbroadcasta)