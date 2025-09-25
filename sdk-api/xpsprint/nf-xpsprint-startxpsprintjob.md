# StartXpsPrintJob function

## Description

[StartXpsPrintJob is not supported and may be altered or unavailable in the future. ]

Starts printing an XPS document stream to a printer.

## Parameters

### `printerName` [in]

The name of the printer with which this job will be associated.

### `jobName` [in]

A user-specified job name to be associated with this job. If the job does not require a separate, user-specified name, this parameter can be set to **NULL**.

### `outputFileName` [in]

The file name of the file or port into which the output of this job is to be redirected. Setting this value will cause the output of the print job to be directed to the specified file or port. To send the print job to the printer that is specified by *printerName*, this parameter must be set to **NULL**.

### `progressEvent` [in]

An event handle that is signaled when the following print job changes occur:

* A job ID is assigned to the print job
* Printing of a page has finished
* Printing of a document has finished
* The print job has been canceled or has ended because of an error

**Note** This event will not be signaled until after the application has started sending data to the print job.

The XPS Print API does not reset this event—that is the caller's responsibility.

If no progress notification is required, this parameter can be set to **NULL**.

### `completionEvent` [in]

An event handle that is signaled when the print job finishes. This event is guaranteed to be signaled exactly once per **StartXpsPrintJob** call. The XPS Print API does not reset this event—that is the caller's responsibility.

If no completion notification is required, this parameter can be set to **NULL**.

### `printablePagesOn` [in]

The parameter references a UINT8 array whose elements specify a subset of a document's pages to be printed. As shown in the table that follows, the value of each element indicates whether the page is to be printed.

| Array Element Value | Meaning |
| --- | --- |
| 0 | Do not print the page. |
| Non-zero | Print the page. |

Progress events will be signaled only for the pages that are designated for printing.

The elements in the array represent all pages that are designated for printing, in all documents of the XPS package. For example, if the package contains two documents that have three pages each, the array shown in the following table designates the printing of pages 0 and 2 from document 1, and pages 0 and 2 from document 2.

| Element index | Element Value | Print? | Document number | Page number |
| --- | --- | --- | --- | --- |
| 5 | 1 | Yes | 2 | 2 |
| 4 | 0 | No | 2 | 1 |
| 3 | 1 | Yes | 2 | 0 |
| 2 | 1 | Yes | 1 | 2 |
| 1 | 0 | No | 1 | 1 |
| 0 | 1 | Yes | 1 | 0 |

If *printablePagesOn* is **NULL**, all pages in the package will be printed.

If *printablePagesOn* has more elements than there are pages in the package, the superfluous elements will be ignored.

If the array has fewer elements than there are pages in the document, the value of the last array element of the array is applied to the remaining pages. This rule makes it easier to specify a range that is open-ended or that gets only a few pages of a large document printed.

### `printablePagesOnCount` [in]

The number of elements in the array that is referenced by *printablePagesOn*. If *printablePagesOn* is **NULL**, this parameter is ignored.

### `xpsPrintJob` [out]

A pointer to the [IXpsPrintJob](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjob) interface that represents the print job that is created by **StartXpsPrintJob**. To get the status of the print job or to cancel it, use the **IXpsPrintJob** interface. If an **IXpsPrintJob** is not required, this parameter can be set to **NULL**.

### `documentStream` [out]

A pointer to the [IXpsPrintJobStream](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjobstream) interface into which the caller writes the XPS document to be printed by this print job.

### `printTicketStream` [out]

A pointer to the [IXpsPrintJobStream](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjobstream) interface that is used by the caller to write the job-level print ticket that will be associated with this job. If this parameter is set to **NULL**, the print tickets (if any exist) from the XPS document that is written to *documentStream* will be used.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *printerName* or *documentStream* is **NULL**. |
| **E_OUTOFMEMORY** | Not enough memory to create a new [IXpsPrintJob](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjob) object. |

## Remarks

**StartXpsPrintJob** is an asynchronous function, which can return before the print spooler creates or starts a print job.

The interfaces that are returned in *xpsPrintJob*, *documentStream*, and *printTicketStream* must not be used until **StartXpsPrintJob** has returned successfully.

 After the caller starts sending data, it should monitor the progress events that are signaled to the event that is passed in *progressEvent*. When the event is signaled, the caller must call [IXpsPrintJob::GetJobStatus](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjob-getjobstatus) to get the current status of the print job.

When the print job finishes, whether successfully or not, the event that is passed in *completionEvent* is signaled once and only once. To prevent data loss, the caller should monitor this event and the thread or the application of the caller should not be terminated until the event has been signaled.

Job states are neither stored nor queued by the print spooler. Because job processing does not wait for the status to be read after events are signaled, the caller might miss some state changes, depending on the delay between the time the application received the change notification and the time it called [IXpsPrintJob::GetJobStatus](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjob-getjobstatus). To receive subsequent notifications, the application must reset the progress event after it has received the notification.

If a call to **StartXpsPrintJob** fails, the job status will be updated, the completion and progress events will be signaled, and an error code will be returned. To get the status of the failed print job, call [IXpsPrintJob::GetJobStatus](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjob-getjobstatus).

**StartXpsPrintJob** calls **DuplicateHandle** on *completionEvent* and *progressEvent* to ensure that they remain valid for the lifetime of the job. Because the print spooler is using a duplicate handle for the events, it is possible for the caller to close these handles at any point without affecting job execution. The recommended procedure, however, is for the caller to close these handles only after the *completionEvent* event has been signaled and observed by the caller.

The [IXpsPrintJobStream](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjobstream) interfaces that are returned in *documentStream* and *printTicketStream* are write-only streams that do not permit seeking but that can be closed. The caller writes the XPS document and print ticket content into these streams, and then calls [Close](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjobstream-close) after all data has been written. Calls to the streams' **Write** method are thread-safe; however, if such calls are made from different threads, they are not guaranteed to be committed to the stream in the expected order.

**Note** When printing to a file, the application is responsible for providing the value that will be passed in the *outputFileName* parameter for print-to-file operations. To print to a printer which uses a driver that outputs to the FILE: port, the caller must retrieve the file name from the user by displaying the common file dialog.

## See also

[Documents](https://learn.microsoft.com/previous-versions/windows/desktop/dd316975(v=vs.85))

[StartXpsPrintJob1](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-startxpsprintjob1)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)