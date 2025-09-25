# IBackgroundCopyJob::GetState

## Description

Retrieves the state of the job.

## Parameters

### `pVal` [out]

The state of the job. For example, the state reflects whether the job is in error, transferring data, or suspended. For a list of job states, see the
[BG_JOB_STATE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_state) enumeration.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The state of the job was successfully retrieved. |
| **E_INVALIDARG** | The parameter, *pJobState*, cannot be **NULL**. |

## Remarks

If you want to know when a job is in error or has transferred all the files in the job, you can use this method to poll for the state of the job or you can register to receive notification when events occur. For details on registering to receive event notification, see the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface.

## Examples

See the example code for the [IBackgroundCopyManager::GetJob](https://learn.microsoft.com/windows/win32/api/bits/nf-bits-ibackgroundcopymanager-getjob) method.

## See also

[BG_JOB_STATE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_state), [Determining the status of a job](https://learn.microsoft.com/windows/desktop/Bits/determining-the-status-of-a-job), [IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback)