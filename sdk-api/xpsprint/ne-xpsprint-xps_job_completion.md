# XPS_JOB_COMPLETION enumeration

## Description

[**XPS_JOB_COMPLETION** is not supported and may be altered or unavailable in the future. ]

Indicates the completion status of a print job.

## Constants

### `XPS_JOB_IN_PROGRESS:0`

The print job is running.

### `XPS_JOB_COMPLETED`

The print job finished without an error.

### `XPS_JOB_CANCELLED`

The print job was cancelled by a call to [IXpsPrintJob::Cancel](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjob-cancel), or cancelled while it was being processed by the print spooler.

### `XPS_JOB_FAILED`

The print job failed. The **jobStatus** member of [XPS_JOB_STATUS](https://learn.microsoft.com/windows/win32/api/xpsprint/ns-xpsprint-xps_job_status) contains the error code of the failure.

## See also

[Documents](https://learn.microsoft.com/previous-versions/windows/desktop/dd316975(v=vs.85))

[IXpsPrintJob::GetJobStatus](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-ixpsprintjob-getjobstatus)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_JOB_STATUS](https://learn.microsoft.com/windows/win32/api/xpsprint/ns-xpsprint-xps_job_status)