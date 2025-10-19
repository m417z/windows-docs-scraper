# IBackgroundCopyJob::SetPriority

## Description

Specifies the priority level of your job. The priority level determines when your job is processed relative to other jobs in the transfer queue.

## Parameters

### `Val` [in]

Specifies the priority level of your job relative to other jobs in the transfer queue. The default is BG_JOB_PRIORITY_NORMAL. For a list of priority levels, see the
[BG_JOB_PRIORITY](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_priority) enumeration.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Job priority was successfully set. |
| **E_NOTIMPL** | The value for *Priority* is not defined in the [BG_JOB_PRIORITY](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_priority) enumeration. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## See also

[BG_JOB_PRIORITY](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_priority)

[IBackgroundCopyJob::GetPriority](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getpriority)