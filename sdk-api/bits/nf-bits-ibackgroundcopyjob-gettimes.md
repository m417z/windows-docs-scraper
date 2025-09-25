# IBackgroundCopyJob::GetTimes

## Description

Retrieves job-related time stamps, such as the time that the job was created or last modified.

## Parameters

### `pVal` [out]

Contains job-related time stamps. For available time stamps, see the
[BG_JOB_TIMES](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_job_times) structure.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Time stamps were successfully retrieved. |
| **E_INVALIDARG** | The *pTimes* parameter cannot be **NULL**. |

## See also

[BG_JOB_TIMES](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_job_times)