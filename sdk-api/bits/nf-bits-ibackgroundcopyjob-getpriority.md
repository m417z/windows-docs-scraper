# IBackgroundCopyJob::GetPriority

## Description

Retrieves the priority level for the job. The priority level determines when the job is processed relative to other jobs in the transfer queue.

## Parameters

### `pVal` [out]

Priority of the job relative to other jobs in the transfer queue.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Priority level was successfully retrieved. |
| **E_INVALIDARG** | The *pPriority* parameter cannot be **NULL**. |

## See also

[BG_JOB_PRIORITY](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_priority)

[IBackgroundCopyJob::SetPriority](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setpriority)