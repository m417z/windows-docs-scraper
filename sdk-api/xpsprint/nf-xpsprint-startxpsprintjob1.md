# StartXpsPrintJob1 function

## Description

[StartXpsPrintJob1 is not supported and may be altered or unavailable in the future. ]

Creates a print job for sending XPS document content to a printer.This function creates a more efficient print path than [StartXpsPrintJob](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-startxpsprintjob).

## Parameters

### `printerName` [in]

The name of the printer with which this job will be associated.

### `jobName` [in, optional]

A user-specified job name to be associated with this job. You can set this parameter to **NULL** if the job does not require a separate, user-specified name.

### `outputFileName` [in, optional]

The file name of the file or port into which the output of this job is to be redirected. Setting this value will cause the output of the print job to be directed to the specified file or port. To send the print job to the printer that is specified by *printerName*, you must set this parameter to **NULL**.

### `progressEvent` [in, optional]

An event handle that is signaled when one of the following print job changes occur:

* A job ID is assigned to the print job
* Printing of a page has finished
* Printing of a document has finished
* The print job has been canceled or has ended because of an error

**Note** This event will not be signaled until after the application has started sending data to the print job.

The XPS Print API does not reset this event—that is the caller's responsibility.

Set this parameter to **NULL** if you do not want to be notified about progress.

### `completionEvent` [in, optional]

An event handle that is signaled when the print job finishes. This event is guaranteed to be signaled exactly once per **StartXpsPrintJob1** call. The XPS Print API does not reset this event—that is the caller's responsibility.

Set this parameter to **NULL** if do not want to be notified about completion.

### `xpsPrintJob` [out, optional]

A pointer to the [IXpsPrintJob](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjob) interface that represents the print job that **StartXpsPrintJob1** created. To get the status of the print job or to cancel it, use the **IXpsPrintJob** interface. Set this parameter to **NULL** if you do not need it.

### `printContentReceiver` [out]

A pointer to the [IXpsOMPackageTarget](https://learn.microsoft.com/previous-versions/windows/desktop/ff970304(v=vs.85)) interface that this function created. This parameter is required and you cannot set it to **NULL**.

To send document content to the print job that this function created, use the [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface that you create by calling the [CreateXpsOMPackageWriter](https://learn.microsoft.com/previous-versions/windows/desktop/ff970305(v=vs.85)) method of the [IXpsOMPackageTarget](https://learn.microsoft.com/previous-versions/windows/desktop/ff970304(v=vs.85)) interface returned in *xpsOMPackageTarget*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *printerName* or *xpsOMPackageTarget* is **NULL**. |
| **E_OUTOFMEMORY** | Not enough memory to create a new [IXpsPrintJob](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjob) object. |

## Remarks

**StartXpsPrintJob1** is an asynchronous function, and therefore it can return before the print spooler creates or starts a print job.

Do not use the interfaces that are returned in *xpsPrintJob* and *xpsOMPackageTarget* until **StartXpsPrintJob1** has returned successfully.

 After the caller starts sending data, it is a good programming practice to monitor the progress events that are signaled to the event that is passed in *progressEvent*. When the event is signaled, the caller must call [IXpsPrintJob::GetJobStatus](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjob-getjobstatus) to get the current status of the print job.

When the print job finishes, whether successfully or not, the event that is passed in *completionEvent* is signaled only once. To prevent data loss, it is a good programming practice for the caller to monitor the completion event and ensure that neither the thread nor the application that created the print job are terminated until the completion event has been signaled.

Job states are neither stored nor queued by the print spooler. Because job processing does not wait for the status to be read after events are signaled, the caller might miss some state changes, depending on the delay between the time the application received the change notification and the time it called [IXpsPrintJob::GetJobStatus](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjob-getjobstatus). To receive subsequent notifications, the application must reset the progress event after it has received the notification.

If a call to **StartXpsPrintJob1** fails, the print spooler updates the job status, signals the completion and progress events, and returns an error code. To get the status of the failed print job, call [IXpsPrintJob::GetJobStatus](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjob-getjobstatus).

**StartXpsPrintJob1** calls **DuplicateHandle** on *completionEvent* and *progressEvent* to ensure that they remain valid for the lifetime of the job. Because the print spooler is using a duplicate handle for the events, the caller can close these handles at any point without affecting job execution. However, we recommend for the caller to close these handles only after the *completionEvent* event has been signaled and the caller observed it.

**Note** When your application prints to a file, the application is responsible for providing the value to pass in the *outputFileName* parameter for print-to-file operations. To print to a printer that uses a driver that outputs to the FILE: port, the caller must retrieve the file name from the user by displaying the common file dialog box.

## See also

[Documents](https://learn.microsoft.com/previous-versions/windows/desktop/dd316975(v=vs.85))

[IXpsOMPackageTarget](https://learn.microsoft.com/previous-versions/windows/desktop/ff970304(v=vs.85))

[IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)