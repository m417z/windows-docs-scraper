# IBackgroundCopyFile3::SetValidationState

## Description

Sets the validation state of this file.

## Parameters

### `state` [in]

Set to **TRUE** if the file content is valid, otherwise, **FALSE**.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **E_PENDING** | You cannot validate the file until the download is complete. |
| **BG_E_RECORD_DELETED** | The cached record associated with this file has been deleted. |

## Remarks

If you set the validation state to **FALSE** and the file was downloaded from the origin server, the job moves to the error state with an error code of BG_E_VALIDATION_FAILED and the file progress is set to zero. You can then call the [IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method to download the file again.

**BITS 3.0:** Do not call the [IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method to download the file again. Instead, call the [IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) or [IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) method to cleanup the current job and then create a new job to download the file.

If you set the validation state to **FALSE** and the file was downloaded from a peer, BITS removes the file from the cache, resets the file progress to zero, and downloads the file again from the origin server.

You can call this method only after BITS finishes transferring the file. To receive notification when the transfer is complete, implement the [IBackgroundCopyCallback2::FileTransferred](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopycallback2-filetransferred) method.

Calling the [IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method implicitly validates the file.

If you validate a file in the cache and then call [IBackgroundCopyJob4::SetPeerCachingFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-setpeercachingflags) to disable caching (or peer caching is disable through Group Policy), the file remains in the cache. If you disable caching before validating the file, BITS removes the file from the cache.

## See also

[IBackgroundCopyFile3](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyfile3)

[IBackgroundCopyFile3::GetValidationState](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyfile3-getvalidationstate)

[IBitsPeerCacheRecord::IsFileValidated](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacherecord-isfilevalidated)