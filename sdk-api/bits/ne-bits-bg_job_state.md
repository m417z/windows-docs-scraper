# BG_JOB_STATE enumeration

## Description

Defines constants that specify the different states of a job.

## Constants

### `BG_JOB_STATE_QUEUED:0`

Specifies that the job is in the queue, and waiting to run. If a user logs off while their job is transferring, the job transitions to the queued state.

### `BG_JOB_STATE_CONNECTING`

Specifies that BITS is trying to connect to the server. If the connection succeeds, the state of the job becomes **BG_JOB_STATE_TRANSFERRING**; otherwise, the state becomes **BG_JOB_STATE_TRANSIENT_ERROR**.

### `BG_JOB_STATE_TRANSFERRING`

Specifies that BITS is transferring data for the job.

### `BG_JOB_STATE_SUSPENDED`

Specifies that the job is suspended (paused). To suspend a job, call the [IBackgroundCopyJob::Suspend method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-suspend). BITS automatically suspends a job when it is created. The job remains suspended until you call the [IBackgroundCopyJob::Resume method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume), [IBackgroundCopyJob::Complete method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete), or [IBackgroundCopyJob::Cancel method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel).

### `BG_JOB_STATE_ERROR`

Specifies that a nonrecoverable error occurred (the service is unable to transfer the file). If the error—such as an access-denied error—can be corrected, then call the
[IBackgroundCopyJob::Resume method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) after the error is fixed. However, if the error cannot be corrected, then call the
[IBackgroundCopyJob::Cancel method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) to cancel the job, or call the
[IBackgroundCopyJob::Complete method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) to accept the portion of a download job that transferred successfully.

### `BG_JOB_STATE_TRANSIENT_ERROR`

Specifies that a recoverable error occurred. BITS will retry jobs in the transient error state based on the retry interval you specify (see [IBackgroundCopyJob::SetMinimumRetryDelay method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setminimumretrydelay)). The state of the job changes to **BG_JOB_STATE_ERROR** if the job fails to make progress (see [IBackgroundCopyJob::SetNoProgressTimeout method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnoprogresstimeout)).

BITS does not retry the job if a network disconnect or a disk lock error occurred (for example, `chkdsk` is running), or the [MaxInternetBandwidth](https://learn.microsoft.com/windows/desktop/Bits/group-policies) Group Policy is zero.

### `BG_JOB_STATE_TRANSFERRED`

Specifies that your job was successfully processed. You must call the
[IBackgroundCopyJob::Complete method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) to acknowledge completion of the job, and to make the files available to the client.

### `BG_JOB_STATE_ACKNOWLEDGED`

Specifies that you called the [IBackgroundCopyJob::Complete method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) to acknowledge that your job completed successfully.

### `BG_JOB_STATE_CANCELLED`

Specifies that you called the
[IBackgroundCopyJob::Cancel method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) to cancel the job (that is, to remove the job from the transfer queue).

## See also

* [IBackgroundCopyJob::GetState method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getstate)