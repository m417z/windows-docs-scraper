# IBackgroundCopyJob2::GetReplyProgress

## Description

Retrieves progress information related to the transfer of the reply data from an upload-reply job.

## Parameters

### `pProgress` [out]

Contains information that you use to calculate the percentage of the reply file transfer that is complete. For more information, see
[BG_JOB_REPLY_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_job_reply_progress).

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Progress information was successfully retrieved. |
| **E_NOTIMPL** | This method is not implemented for jobs of type **BG_JOB_TYPE_DOWNLOAD** or **BG_JOB_TYPE_UPLOAD**. |
| **E_INVALIDARG** | The *pProgress* parameter cannot be **NULL**. |

## See also

[BG_JOB_REPLY_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_job_progress)