# IBackgroundCopyJob::SetMinimumRetryDelay

## Description

Sets the minimum length of time that BITS waits after encountering a transient error condition before trying to transfer the file.

## Parameters

### `Seconds` [in]

Minimum length of time, in seconds, that BITS waits after encountering a transient error before trying to transfer the file. The default retry delay is 600 seconds (10 minutes). The minimum retry delay that you can specify is 5 seconds. If you specify a value less than 5 seconds, BITS changes the value to 5 seconds. If the value exceeds the no-progress-timeout
value retrieved from the [GetNoProgressTimeout](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getprogress) method, BITS will not retry the transfer and moves the job to the BG_JOB_STATE_ERROR state.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Retry delay was successfully set. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

To start the job before the minimum retry period expires, call the [IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method.

BITS does not retry the job if a network disconnect or disk lock error occurred (for example, chkdsk is running) or the [MaxInternetBandwidth](https://learn.microsoft.com/windows/desktop/Bits/group-policies) Group Policy is zero.

**Note** Changing the system clock does not affect the minimum retry delay. For example, if the current time is 2:00 P.M. and BITS is to retry the job at 2:10 P.M., moving the system clock forward ten or more minutes does not mean BITS will retry the job early—BITS will still retry the job in ten minutes. To reflect the system clock change in BITS, you must restart the computer or the BITS service.

## See also

[IBackgroundCopyJob::GetMinimumRetryDelay](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getminimumretrydelay)

[IBackgroundCopyJob::GetNoProgressTimeout](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getnoprogresstimeout)

[IBackgroundCopyJob::SetNoProgressTimeout](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnoprogresstimeout)