# PFAX_RECIPIENT_CALLBACKA callback function

## Description

The **FAX_RECIPIENT_CALLBACK** function is an application-defined or library-defined callback function that the [FaxSendDocumentForBroadcast](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumentforbroadcasta) function calls to retrieve user-specific information for the transmission.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `RecipientNumber` [in]

Type: **DWORD**

Specifies a **DWORD** variable that indicates the number of times the [FaxSendDocumentForBroadcast](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumentforbroadcasta) function has called the **FAX_RECIPIENT_CALLBACK** function. Each function call corresponds to one designated fax recipient, and the index is relative to 1.

### `Context` [in]

Type: **LPVOID**

Pointer to a variable that contains application-specific context information or an application-defined value. [FaxSendDocumentForBroadcast](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumentforbroadcasta) passes this data to the **FAX_RECIPIENT_CALLBACK** function.

### `JobParams` [in, out]

Type: **PFAX_JOB_PARAM**

Pointer to a [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure that contains the information necessary for the fax server to send the fax transmission to the designated recipient. The structure includes, among other items, the recipient's fax number, sender and recipient data, an optional billing code, and job scheduling information. The fax server queues the fax transmission according to the details specified by the **FAX_JOB_PARAM** structure.

### `CoverpageInfo` [in, out, optional]

Type: **PFAX_COVERPAGE_INFO**

Pointer to a [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) structure that contains cover page data to display on the cover page of the fax document for the designated recipient. This parameter must be **NULL** if a cover page is not required.

## Return value

Type: **BOOL**

The function returns a value of nonzero to indicate that the [FaxSendDocumentForBroadcast](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumentforbroadcasta) function should queue an outbound fax transmission, using the data pointed to by the *JobParams* and *CoverpageInfo* parameters.

The function returns a value of zero to indicate that there are no more fax transmission jobs to queue, and calls to **FAX_RECIPIENT_CALLBACK** should be terminated. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

[FaxSendDocumentForBroadcast](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumentforbroadcasta) calls **FAX_RECIPIENT_CALLBACK** multiple times, once for each designated fax recipient.

The **PFAX_RECIPIENT_CALLBACK** data type is a pointer to a **FAX_RECIPIENT_CALLBACK** function.

Call the [FaxCompleteJobParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxcompletejobparamsa) function before calling the **FAX_RECIPIENT_CALLBACK** function. **FaxCompleteJobParams** is a utility function that fills multiple members in the [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) and [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structures, with information such as the sender's name, fax number, and optional billing code information.

A fax client application must specify the **FAX_RECIPIENT_CALLBACK** function by passing its address when it calls the [FaxSendDocumentForBroadcast](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumentforbroadcasta) function.

For more information, see [Transmitting Faxes](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-transmitting-faxes).

> [!NOTE]
> The winfax.h header defines PFAX_RECIPIENT_CALLBACK as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa)

[FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxSendDocumentForBroadcast](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumentforbroadcasta)