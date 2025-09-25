# IBackgroundCopyFile6::RequestFileRanges

## Description

Adds a new set of file ranges to be prioritized for download.

## Parameters

### `rangeCount` [in]

Specifies the size of the *Ranges* array.

### `ranges` [in]

An array of file ranges to be downloaded. Requested ranges are allowed to overlap previously downloaded (or pending) ranges. Ranges are automatically split into non-overlapping ranges.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. **BG_E_INVALID_RANGE** is returned if any part of the requested range is outside the actual file size; **BG_E_RANDOM_ACCESS_NOT_SUPPORTED** is returned if the job is not a download job or if the server loses its ability to support download ranges.

## Remarks

**RequestFileRanges** can be requested for any download job that also meets the requirements for **BITS_JOB_PROPERTY_ON_DEMAND_MODE** jobs.

The requirements for a **BITS_JOB_PROPERTY_ON_DEMAND_MODE** job is that the transfer must be a **DOWNLOAD** job. The job must not be **DYNAMIC** and the server must be an HTTP or HTTPS server and the server requirements for range support must all be met.
For more information, see [HTTP Requirements for BITS Downloads](https://learn.microsoft.com/windows/desktop/Bits/http-requirements-for-bits-downloads).

When all of the requested ranges have been downloaded the job state will be set to **BG_JOB_STATE_TRANSFERRED** if all of the bytes of the file have been transferred. Otherwise, the job state will be set to **BG_JOB_STATE_SUSPENDED**.

## See also

[IBackgroundCopyFile6](https://learn.microsoft.com/windows/desktop/api/bits10_1/nn-bits10_1-ibackgroundcopyfile6)