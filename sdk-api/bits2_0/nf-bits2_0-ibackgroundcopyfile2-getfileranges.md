# IBackgroundCopyFile2::GetFileRanges

## Description

Retrieves the ranges that you want to download from the remote file.

## Parameters

### `RangeCount` [in, out]

Number of elements in *Ranges*.

### `Ranges` [out]

Array of [BG_FILE_RANGE](https://learn.microsoft.com/windows/desktop/api/bits2_0/ns-bits2_0-bg_file_range) structures that specify the ranges to download. When done, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *Ranges*.

## Return value

This method returns the following return values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **S_FALSE** | No ranges were specified or the job is an upload or upload-reply job. *RangeCount* is set to zero and *Ranges* is set to **NULL**. |

## See also

[BG_FILE_RANGE](https://learn.microsoft.com/windows/desktop/api/bits2_0/ns-bits2_0-bg_file_range)

[IBackgroundCopyFile2](https://learn.microsoft.com/windows/desktop/api/bits2_0/nn-bits2_0-ibackgroundcopyfile2)

[IBackgroundCopyJob3::AddFileWithRanges](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-addfilewithranges)