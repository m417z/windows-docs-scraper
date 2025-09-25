# IBackgroundCopyJob::GetProgress

## Description

Retrieves job-related progress information, such as the number of bytes and files transferred.

## Parameters

### `pVal` [out]

Contains data that you can use to calculate the percentage of the job that is complete. For more information, see
[BG_JOB_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_job_progress).

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Progress information was successfully retrieved. |
| **E_INVALIDARG** | The *pProgress* parameter cannot be **NULL**. |

## See also

[BG_JOB_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_job_progress)