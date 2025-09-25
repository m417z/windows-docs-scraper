# IBackgroundCopyJob::GetMinimumRetryDelay

## Description

Retrieves the minimum length of time that the service waits after encountering a transient error condition before trying to transfer the file.

## Parameters

### `Seconds` [in]

Length of time, in seconds, that the service waits after encountering a transient error before trying to transfer the file.

## Return value

This method returns **S_OK** on success or one of the standard COM **HRESULT** values on error.

## See also

[IBackgroundCopyJob::GetNoProgressTimeout](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getnoprogresstimeout)

[IBackgroundCopyJob::SetMinimumRetryDelay](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setminimumretrydelay)