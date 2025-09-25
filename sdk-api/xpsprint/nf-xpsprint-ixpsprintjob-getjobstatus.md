# IXpsPrintJob::GetJobStatus

## Description

[IXpsPrintJob::GetJobSatus is not supported and may be altered or unavailable in the future. ]

Gets the current status of the print job.

## Parameters

### `jobStatus` [out, retval]

The current status of the print job. For information about the data that is returned in this structure, see [XPS_JOB_STATUS](https://learn.microsoft.com/windows/win32/api/xpsprint/ns-xpsprint-xps_job_status).

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

**GetJobStatus** may be called during the print job processing or after the print job has completed. The values returned in [XPS_JOB_STATUS](https://learn.microsoft.com/windows/win32/api/xpsprint/ns-xpsprint-xps_job_status) represent the current state of the print job at the time **GetJobStatus** is called, so it is possible to miss intermediate states between calls to this method.

The values of *jobStatus.currentDocument* and *jobStatus.currentPage* are guaranteed to progress sequentially: from the first document to the last, and from the first page to the last within each document.

The job ID of a print job that has been sent to the Microsoft XPS Document Writer (MXDW) is zero. If the interface is that of a print job that has been sent to the MXDW, zero will be returned in *jobStatus.jobId*.

If no job ID has been assigned to the print job, or the print job is printed without spooling, zero will be returned in *jobStatus.jobId*.

## See also

[Documents](https://learn.microsoft.com/previous-versions/windows/desktop/dd316975(v=vs.85))

[IXpsPrintJob](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjob)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_JOB_COMPLETION](https://learn.microsoft.com/windows/win32/api/xpsprint/ne-xpsprint-xps_job_completion)

[XPS_JOB_STATUS](https://learn.microsoft.com/windows/win32/api/xpsprint/ns-xpsprint-xps_job_status)