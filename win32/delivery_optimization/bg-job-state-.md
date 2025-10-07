# BG_JOB_STATE enumeration

The **BG_JOB_STATE** enumeration defines constant values for the different states of a job.

## Constants

**BG_JOB_STATE_QUEUED**

Specifies that the job is in the queue and waiting to run. If a user logs off while their job is transferring, the job transitions to the queued state.

**BG_JOB_STATE_CONNECTING**

Not supported.

**BG_JOB_STATE_TRANSFERRING**

Specifies that Delivery Optimization is transferring data for the job.

**BG_JOB_STATE_SUSPENDED**

Specifies that the job is suspended (paused). To suspend a job, call the [**IBackgroundCopyJob::Suspend**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-suspend) method. The job remains suspended until you call the [**IBackgroundCopyJob::Resume**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-resume), [**IBackgroundCopyJob::Complete**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-complete), or [**IBackgroundCopyJob::Cancel**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-cancel) method.

**BG_JOB_STATE_ERROR**

Specifies that a nonrecoverable error occurred (the service is unable to transfer the file). If the error, such as an access-denied error, can be corrected, call the [**IBackgroundCopyJob::Resume**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-resume) method after the error is fixed. However, if the error cannot be corrected, call the [**IBackgroundCopyJob::Cancel**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-cancel) method to cancel the job, or call the [**IBackgroundCopyJob::Complete**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-complete) method to accept the portion of a download job that transferred successfully.

**BG_JOB_STATE_TRANSIENT_ERROR**

Specifies that a recoverable error occurred. Delivery Optimization will retry jobs in the transient error state based on the internal retry configuration. The state of the job changes to **BG_JOB_STATE_ERROR** if the job fails to make progress (see [**IBackgroundCopyJob::SetNoProgressTimeout**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-setnoprogresstimeout)).

**BG_JOB_STATE_TRANSFERRED**

Specifies that your job was successfully processed. You must call the [**IBackgroundCopyJob::Complete**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-complete) method to acknowledge completion of the job and to make the files available to the client.

**BG_JOB_STATE_ACKNOWLEDGED**

Specifies that you called the [**IBackgroundCopyJob::Complete**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-complete) method to acknowledge that your job completed successfully.

**BG_JOB_STATE_CANCELLED**

Specifies that you called the [**IBackgroundCopyJob::Cancel**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-cancel) method to cancel the job (remove the job from the transfer queue).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**IBackgroundCopyJob::GetState**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-getstate)

