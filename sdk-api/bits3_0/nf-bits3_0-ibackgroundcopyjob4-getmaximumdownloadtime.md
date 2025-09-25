# IBackgroundCopyJob4::GetMaximumDownloadTime

## Description

Retrieves the maximum time that BITS will spend transferring the files in the job.

## Parameters

### `pTimeout` [out]

Maximum time, in seconds, that BITS will spend transferring the files in the job.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

The value is the maximum elapsed time that the job can spend in the CONNECTING or TRANSFERRING state. Time spent in the QUEUED or TRANSIENT_ERROR state does not count against the timeout value.

## See also

[IBackgroundCopyJob4](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyjob4)

[IBackgroundCopyJob4::SetMaximumDownloadTime](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-setmaximumdownloadtime)