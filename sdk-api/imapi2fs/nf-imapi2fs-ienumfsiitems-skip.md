# IEnumFsiItems::Skip

## Description

Skips a specified number of items in the enumeration sequence.

## Parameters

### `celt` [in]

Number of items to skip.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **S_FALSE** | Skipped less than the number of requested elements. |

## Remarks

If there are fewer elements left in the sequence than the requested number of elements to skip, it skips past the last element in the sequence.

## See also

[IEnumFsiItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ienumfsiitems)