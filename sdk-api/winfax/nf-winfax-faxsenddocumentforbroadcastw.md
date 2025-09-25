# FaxSendDocumentForBroadcastW function

## Description

A fax client application calls the **FaxSendDocumentForBroadcast** function to queue several fax jobs that will transmit the same outgoing fax transmission to several recipients.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `FileName` [in]

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that contains the fully qualified path and name of the file that contains the fax document to transmit to all recipients. The path can be a UNC path or a path that begins with a drive letter.

This parameter can contain any valid local file name. The file must be a properly registered file type, and the fax server must be able to access the file.

### `FaxJobId` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive the unique number that identifies the queued job that will send the fax transmission.

### `FaxRecipientCallback` [in]

Type: **PFAX_RECIPIENT_CALLBACK**

Pointer to a [FAX_RECIPIENT_CALLBACK](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfax_recipient_callbacka) function that retrieves user-specific information for each designated recipient of the fax transmission. The **FaxSendDocumentForBroadcast** function calls the **FAX_RECIPIENT_CALLBACK** function once for each fax recipient until it returns a value of zero, indicating that all outbound transmissions have been queued.

### `Context` [in]

Type: **LPVOID**

Pointer to a variable that contains application-specific context information or an application-defined value. **FaxSendDocumentForBroadcast** passes this data to the [FAX_RECIPIENT_CALLBACK](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfax_recipient_callbacka) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or all of the *FaxHandle*, *FileName*, *FaxRecipientCallback*, or *FaxJobId* parameters are **NULL**, or the **RecipientNumber** member in the [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure is **NULL**. |
| **ERROR_FILE_NOT_FOUND** | The fax server cannot locate the file specified by the *FileName* parameter. |
| **ERROR_INVALID_DATA** | The fax server cannot render the file specified by the *FileName* parameter. |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_JOB_SUBMIT](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |

## Remarks

The function calls the [FAX_RECIPIENT_CALLBACK](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfax_recipient_callbacka) function once for each designated fax recipient.

An application should call the **FaxSendDocumentForBroadcast** function to efficiently send a fax document to multiple recipients, rather than calling [FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta) multiple times. This is because **FaxSendDocumentForBroadcast** stores the master document only once, using the same file for all outbound transmissions.

**Note** To send a fax document efficiently to multiple recipients, an application should call the [FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta) function multiple times. The **FaxSendDocumentForBroadcast** function is supported for backward compatibility.

The **FaxSendDocumentForBroadcast** function performs the following operations in the order indicated:

1. The function queues the master document for transmission to multiple fax transmission recipients.
2. The function calls the user-defined [FAX_RECIPIENT_CALLBACK](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfax_recipient_callbacka) function. If the callback function supplies the required information for the transmission to a fax recipient, it returns a value of nonzero. This value indicates that **FaxSendDocumentForBroadcast** should use the data to queue an outbound fax.
3. The function queues a fax transmission job for the first recipient using the master document.
4. The function calls the [FAX_RECIPIENT_CALLBACK](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfax_recipient_callbacka) function multiple times, until it returns a value of zero. Each time **FAX_RECIPIENT_CALLBACK** returns nonzero, the **FaxSendDocumentForBroadcast** function queues an outbound transmission for the next fax recipient. A value of zero indicates that there are no more fax transmission jobs to queue, and calls to **FAX_RECIPIENT_CALLBACK** should be terminated.

For more information, see [Transmitting Faxes](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-transmitting-faxes).

> [!NOTE]
> The winfax.h header defines FaxSendDocumentForBroadcast as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_RECIPIENT_CALLBACK](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfax_recipient_callbacka)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta)