# IBackgroundCopyJob4::SetMaximumDownloadTime

## Description

Sets the maximum time that BITS will spend transferring the files in the job.

## Parameters

### `Timeout` [in]

Maximum time, in seconds, that BITS will spend transferring the files in the job. The default is 7,776,000 seconds (90 days).

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

The value is the maximum elapsed time that the job can spend in the CONNECTING or TRANSFERRING state. Time spent in the QUEUED or TRANSIENT_ERROR state does not count against the timeout value. The job enters the fatal error state with an error code of BG_E_MAXDOWNLOAD_TIMEOUT if the transfer time exceeds the timeout value.

Note that if the computer sleeps while BITS is transferring the job's data, the time spent sleeping will count against the timeout even though data is not being transferred.

Calling the [IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method, resets the elapsed time.

This method overrides the MaxDownloadTime group policy.

## See also

[IBackgroundCopyJob4](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyjob4)

[IBackgroundCopyJob4::GetMaximumDownloadTime](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-getmaximumdownloadtime)