# IEnumBackgroundCopyJobs1::Skip

## Description

[**IEnumBackgroundCopyJobs1** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **Skip** method to skip the next specified number of elements in the enumeration sequence. If there are fewer elements left in the sequence than the requested number of elements to skip, it skips past the last element in the sequence.

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

[IEnumBackgroundCopyJobs1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ienumbackgroundcopyjobs1)