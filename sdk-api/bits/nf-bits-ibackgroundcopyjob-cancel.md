# IBackgroundCopyJob::Cancel

## Description

Deletes the job from the transfer queue and removes related temporary files from the client (downloads) and server (uploads).

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Job was successfully canceled. |
| **BG_S_UNABLE_TO_DELETE_FILES** | Job was successfully canceled; however, the service was unable to delete the temporary files associated with the job. |
| **BG_E_INVALID_STATE** | Cannot cancel a job whose state is BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

You can
[cancel a job](https://learn.microsoft.com/windows/desktop/Bits/completing-and-canceling-a-job) at any time; however, the job cannot be recovered after it is canceled.

For upload jobs, if the server is unavailable, there may be a delay before BITS deletes the job from the queue. BITS periodically sends a cancel request to the BITS server for up to 24 hours. If the server does not respond within the 24-hour period, BITS removes the job from the queue. If the [no-progress time-out period](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnoprogresstimeout) is less than 24 hours, BITS uses the no-progress time-out period to limit the retries.

The
**Cancel** method cancels an upload if the upload is not complete. If the upload is complete and the job is of type BG_JOB_TYPE_UPLOAD_REPLY, the method cancels the reply.

## See also

[IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete)

[IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume)

[IBackgroundCopyJob::Suspend](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-suspend)