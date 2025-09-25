# IBitsPeerCacheRecord::GetFileRanges

## Description

Gets the ranges of the file that are in the cache.

## Parameters

### `pRangeCount` [out]

Number of elements in *ppRanges*.

### `ppRanges` [out]

Array of [BG_FILE_RANGE](https://learn.microsoft.com/windows/desktop/api/bits2_0/ns-bits2_0-bg_file_range) structures that specify the ranges of the file that are in the cache. When done, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppRanges*.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

The method always returns at least one range (for the complete file). Multiple ranges can be returned if the application called [IBackgroundCopyJob3::AddFileWithRanges](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-addfilewithranges) to download one or more ranges of a file.

## See also

[BG_FILE_RANGE](https://learn.microsoft.com/windows/desktop/api/bits2_0/ns-bits2_0-bg_file_range)

[IBitsPeerCacheRecord](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacherecord)