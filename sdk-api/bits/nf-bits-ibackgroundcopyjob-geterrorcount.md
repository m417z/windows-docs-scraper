# IBackgroundCopyJob::GetErrorCount

## Description

Retrieves the number of times BITS tried to transfer the job and an error occurred.

## Parameters

### `Errors` [out]

Number of errors that occurred while BITS tried to transfer the job. The count increases when the job moves from the BG_JOB_STATE_TRANSFERRING state to the BG_JOB_STATE_TRANSIENT_ERROR or BG_JOB_STATE_ERROR state.

## Return value

This method returns **S_OK** on success or one of the standard COM **HRESULT** values on error.

## Remarks

The count is never reset. The count may not accurately reflect the number of times the job moves to the transient error or error state. For example, BITS does not increase the count when network disconnects occur, the check disk program runs, or the bandwidth policy prevents jobs from transferring.

BITS also increases the count each time it tries to transfer the job when the job is in the transient error state and the job fails.

**BITS 1.5 and earlier:**  BITS does not increase the count each time it tries to transfer the job when it is in the transient error state.

## See also

[IBackgroundCopyJob::GetError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-geterror)