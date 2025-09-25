# IBackgroundCopyCallback2::FileTransferred

## Description

BITS calls your implementation of the
**FileTransferred** method when BITS successfully finishes transferring a file.

## Parameters

### `pJob` [in]

Contains job-related information. Do not release *pJob*; BITS releases the interface when this method returns.

### `pFile` [in]

Contains file-related information. Do not release *pFile*; BITS releases the interface when this method returns.

## Return value

This method should return **S_OK**; otherwise, if negative, BITS continues to call this method until **S_OK** is returned. For performance reasons, you should limit the number of times you return a value other than **S_OK** to a few times. As an alternative to returning an error code, consider always returning **S_OK** and handling the error internally. The interval at which this method is called is arbitrary.

## Remarks

Typically, you would not use this callback unless you want to validate the contents of the file that was downloaded. Validating the file may be important to you if you are downloading content that could be served to peers.

To get the name of the temporary file that contains the downloaded content, call the [IBackgroundCopyFile3::GetTemporaryName](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyfile3-gettemporaryname) method. After verifying the content, call the [IBackgroundCopyFile3::SetValidationState](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyfile3-setvalidationstate) method to indicate to BITS if the contents of the file is valid. If you set the validation state to **FALSE** and the content is from the origin server, the job moves to the error state.

If the content is from a peer, BITS downloads the file from the origin server. The callback is called again after the file transfer from the origin server completes.

**BITS 3.0:** The callback is not called again after the file transfer from the origin server completes.

For a job, **FileTransferred** callbacks are serialized. BITS will not dispatch a callback for the next file in the job until the current callback returns successfully.

**FileTransferred** callbacks are dispatched before [JobTransferred](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopycallback-jobtransferred) and [JobError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopycallback-joberror) callbacks.

The **FileTransferred** callback is for download jobs or the reply portion of an upload-reply job.

## See also

[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback)

[IBackgroundCopyCallback2](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopycallback2)