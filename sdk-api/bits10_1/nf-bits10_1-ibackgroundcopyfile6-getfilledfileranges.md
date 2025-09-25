# IBackgroundCopyFile6::GetFilledFileRanges

## Description

Returns the set of file ranges that have been downloaded.

## Parameters

### `rangeCount` [out]

The number of elements in *Ranges*.

### `ranges` [out]

Array of **BG_FILE_RANGE** structures that describes the ranges that have been downloaded. Ranges will be merged together as much as possible. The ranges are ordered by offset. When done, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *Ranges*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. The error will be **E_OUTOFMEMORY** if the *Ranges* array could not be allocated and **BG_E_RANDOM_ACCESS_NOT_SUPPORTED** if the job is not a download job or if the server loses its ability to support download ranges.

## Remarks

**GetFilledFileRanges** can be requested for any download job that also meets the requirements for **BITS_JOB_PROPERTY_ON_DEMAND_MODE** jobs.

The requirements for a **BITS_JOB_PROPERTY_ON_DEMAND_MODE** job is that the transfer must be a **DOWNLOAD** job. The job must not be **DYNAMIC** and the server must be an HTTP or HTTPS server and the server requirements for range support must all be met.
For more information, see [HTTP Requirements for BITS Downloads](https://learn.microsoft.com/windows/desktop/Bits/http-requirements-for-bits-downloads).

## See also

[IBackgroundCopyFile6](https://learn.microsoft.com/windows/desktop/api/bits10_1/nn-bits10_1-ibackgroundcopyfile6)