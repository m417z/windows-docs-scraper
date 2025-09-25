# IEnumBitsPeerCacheRecords::Skip

## Description

Skips the next specified number of elements in the enumeration sequence. If there are fewer elements left in the sequence than the requested number of elements to skip, it skips past the last element in the sequence.

## Parameters

### `celt` [in]

Number of elements to skip.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully skipped the number of requested elements. |
| **S_FALSE** | Skipped less than the number of requested elements. |

## See also

[IEnumBitsPeerCacheRecords](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ienumbitspeercacherecords)