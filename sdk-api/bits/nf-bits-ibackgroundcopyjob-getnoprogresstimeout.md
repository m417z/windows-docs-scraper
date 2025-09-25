# IBackgroundCopyJob::GetNoProgressTimeout

## Description

Retrieves the length of time that the service tries to transfer the file after a transient error condition occurs. If there is progress, the timer is reset.

## Parameters

### `Seconds` [in]

Length of time, in seconds, that the service tries to transfer the file after a transient error occurs.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Time-out was successfully retrieved. |
| **E_INVALIDARG** | Must pass the address of *pRetryPeriod*. |

## See also

[IBackgroundCopyJob::GetMinimumRetryDelay](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getminimumretrydelay)

[IBackgroundCopyJob::SetNoProgressTimeout](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnoprogresstimeout)