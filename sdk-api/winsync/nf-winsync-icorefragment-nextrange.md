# ICoreFragment::NextRange

## Description

Returns the next range that is contained in this knowledge fragment, and the clock vector that defines what is known about the items in the range.

## Parameters

### `pItemId` [in, out]

Returns the closed lower bound of item IDs in this range. This value is also the open upper bound of item IDs in the previous range when it is not the first in the range set.

### `pItemIdSize` [in, out]

Specifies the number of bytes in *pItemId*. Returns the number of bytes written, or the number of bytes that are required to retrieve the ID when *pItemId* is too small.

### `piClockVector` [out]

Returns the clock vector that defines what is known about the items in the range.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | There are no more ranges to enumerate. |
| **E_POINTER** | The item ID is a variable-length ID and *pItemIdSize* is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pItemId* is too small. In this situation, the required number of bytes is returned in *pItemIdSize*. |
| **SYNC_E_INVALID_OPERATION** | The knowledge object that is contained in this object has changed since this object was created. |

## Remarks

The value that is returned in *pItemId* is the closed lower bound on the range of item IDs that are associated with the clock vector that is returned in *piClockVector*. The value of *pItemId* also defines the open upper bound of the previous range, so the open upper bound of the current range can be obtained by calling **NextRange** again. If there are no more ranges to enumerate, the range contains all items that have IDs greater than or equal to *pItemId*.

## See also

[ICoreFragment Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-icorefragment)