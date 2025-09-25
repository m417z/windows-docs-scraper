# IBackgroundCopyFile6::UpdateDownloadPosition

## Description

Specifies a position to prioritize downloading missing data from.

## Parameters

### `offset` [in]

Specifies the new position to prioritize downloading missing data from.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. It will return **BG_E_RANDOM_ACCESS_NOT_SUPPORTED** if the job does not meet the requirements of a **BITS_JOB_PROPERTY_ON_DEMAND_MODE** job.

## Remarks

**UpdateDownloadPosition** can be requested for any download job that also meets the requirements for **BITS_JOB_PROPERTY_ON_DEMAND_MODE** jobs.

The requirements for a **BITS_JOB_PROPERTY_ON_DEMAND_MODE** job is that the transfer must be a **DOWNLOAD** job. The job must not be **DYNAMIC** and the server must be an HTTP or HTTPS server and the server requirements for range support must all be met.
For more information, see [HTTP Requirements for BITS Downloads](https://learn.microsoft.com/windows/desktop/Bits/http-requirements-for-bits-downloads).

## See also

[IBackgroundCopyFile6](https://learn.microsoft.com/windows/desktop/api/bits10_1/nn-bits10_1-ibackgroundcopyfile6)