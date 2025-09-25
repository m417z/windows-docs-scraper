# XPS_JOB_STATUS structure

## Description

[**XPS_JOB_STATUS** is not supported and may be altered or unavailable in the future. ]

Contains a snapshot of job status.

## Members

### `jobId`

The spooler job ID that is assigned to the print job. If no job ID has yet been assigned, *jobId* will be 0.

### `currentDocument`

The zero-based index of the most recently processed document in the print job; 0 is the first document, 1 is the next, and so on. If no documents have been processed, *currentDocument* will have a value of -1.

### `currentPage`

The zero-based index of the most recently processed page in the current document; 0 is the first page, 1 is the next, and so on. If no pages have been processed, *currentPage* will have a value of -1.

### `currentPageTotal`

A running total of the number of pages that have been processed by the print job. At the beginning of the job, this value is 0. As each page in each document is processed by the job, this value increases monotonically.

### `completion`

The [XPS_JOB_COMPLETION](https://learn.microsoft.com/windows/win32/api/xpsprint/ne-xpsprint-xps_job_completion) value that indicates the completion status of the job. This value will change when the event passed in the **completionEvent** parameter of [StartXpsPrintJob](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-startxpsprintjob) is signaled at the end of a job. If the print job fails, this value will be **XPS_JOB_FAILED**, with *jobStatus* containing the error code of the failure.

### `jobStatus`

The error state of the job. If the job finishes without an error, this value will be **S_OK**. If an error causes the print job to exit, this value will be the error code of the failure.

## See also

[Documents](https://learn.microsoft.com/previous-versions/windows/desktop/dd316975(v=vs.85))

[IXpsPrintJob::GetJobStatus](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjob-getjobstatus)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_JOB_COMPLETION](https://learn.microsoft.com/windows/win32/api/xpsprint/ne-xpsprint-xps_job_completion)