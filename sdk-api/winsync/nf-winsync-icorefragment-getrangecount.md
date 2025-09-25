# ICoreFragment::GetRangeCount

## Description

Gets the number of ranges that are contained in this knowledge fragment.

## Parameters

### `pRangeCount` [out]

Returns the number of ranges that are contained in this knowledge fragment.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

An **ICoreFragment** object contains one or more ranges. Each range specifies a set of item IDs and a clock vector that defines what is known about the items in the range.

## See also

[ICoreFragment Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-icorefragment)