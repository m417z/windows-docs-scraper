# IFaxJob::SetStatus

## Description

Call the **IFaxJob::SetStatus** method to pause, resume, cancel, or restart a specified fax job.

## Parameters

### `Command` [in]

Type: **LONG**

Specifies a **LONG** variable that indicates the job command to perform. This parameter can be one of the following values.

#### JC_DELETE (JC_DELETE)

Cancel the specified fax job. The job can be active or queued.

#### JC_PAUSE (JC_PAUSE)

Pause the specified queued fax job. If the fax job is active, the fax service
pauses the job when it returns to the queued state.

#### JC_RESUME (JC_RESUME)

Resume the paused fax job.

#### JC_RESTART (JC_RESTART)

Restart the specified fax job.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use the [IFaxJob::get_QueueStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-queuestatus-vb) property to retrieve the job queue status of a fax job.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJob::get_QueueStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-queuestatus-vb)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)

[Managing Fax Jobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-jobs)