# ISyncFilterInfo2::GetFlags

## Description

Gets the flags that specify additional information about the filter information object.

## Parameters

### `pdwFlags` [out]

Gets the flags that specify additional information about the filter information object. This will be one of the **SYNC_FILTER_INFO_FLAG** values (See Remarks).

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

The following table describes the flags that specify information about an [ISyncFilterInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfilterinfo) object.

| SYNC_FILTER_INFO_FLAG value | Description |
| --- | --- |
| **SYNC_FILTER_INFO_FLAG_ITEM_LIST** | This flag indicates that the set of items synchronized is restricted by an item filter. |
| **SYNC_FILTER_INFO_FLAG_CHANGE_UNIT_LIST** | An [IChangeUnitListFilterInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeunitlistfilterinfo) object specifies that changes apply only to a subset of the change units that are defined for the scope. |

## See also

[IChangeUnitListFilterInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeunitlistfilterinfo)

[ISyncFilterInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfilterinfo)

[ISyncFilterInfo2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfilterinfo2)