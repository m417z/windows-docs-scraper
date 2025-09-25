# IBackgroundCopyJob::SetNoProgressTimeout

## Description

Sets the length of time that BITS tries to transfer the file after a transient error condition occurs. If there is progress, the timer is reset.

## Parameters

### `Seconds` [in]

Length of time, in seconds, that BITS tries to transfer the file after the first transient error occurs. The default retry period is 1,209,600 seconds (14 days). Set the retry period to 0 to prevent retries and to force the job into the BG_JOB_STATE_ERROR state for all errors. If the retry period value exceeds the [JobInactivityTimeout](https://learn.microsoft.com/windows/desktop/Bits/group-policies) Group Policy value (90-day default), BITS cancels the job after the policy value is exceeded.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Retry period successfully set. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

If BITS does not make progress during the retry period, it moves the state of the job from BG_JOB_STATE_TRANSIENT_ERROR to BG_JOB_STATE_ERROR. If you request error notification, BITS then calls your
[JobError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopycallback-joberror) callback.

**Note** Changing the system clock does not affect the retry period. For example, if the retry period expires in 14 days, moving the system clock forward 14 or more days does not mean the retry period expires early—the retry period will still expire in 14 days. To reflect the system clock change in BITS, you must restart the computer or the BITS service.

## See also

[IBackgroundCopyJob::GetNoProgressTimeout](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getnoprogresstimeout)

[IBackgroundCopyJob::SetMinimumRetryDelay](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setminimumretrydelay)