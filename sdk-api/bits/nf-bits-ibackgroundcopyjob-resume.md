# IBackgroundCopyJob::Resume

## Description

Activates a new job or restarts a job that has been suspended.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Job was successfully restarted. |
| **BG_E_EMPTY** | There are no files to transfer. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

When you create a job, the job is initially suspended. Calling **Resume** moves the job from the suspended state to the queued state. The job stays in the queued state until the scheduler determines it is the job's turn to transfer files. Note that the job must contain one or more files before calling this method. If the job is of type BG_JOB_TYPE_UPLOAD_REPLY and you want to specify the name of the reply file, you should call the
[IBackgroundCopyJob2::SetReplyFileName](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setreplyfilename) method before calling
**Resume**.

If a job that is in the BG_JOB_STATE_TRANSIENT_ERROR or BG_JOB_STATE_ERROR state, call the
**Resume** method to restart the job after you fix the error.

## See also

[IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel)

[IBackgroundCopyJob::Suspend](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-suspend)