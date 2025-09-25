# IChangeUnitListFilterInfo::Initialize

## Description

Initializes a new instance of the **IChangeUnitListFilterInfo** class that contains the specified array of change unit IDs.

## Parameters

### `ppbChangeUnitIds` [in]

The array of change unit IDs that indicate which change units are included by this filter.

### `dwChangeUnitCount` [in]

The number of change unit IDs that are contained in *ppbChangeUnitIds*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwChangeUnitCount* is 0, or any ID that is contained in *ppbChangeUnitIds* is not valid. |
| **E_OUTOFMEMORY** |  |
| **E_POINTER** | Invalid pointer. |

## Remarks

An **IChangeUnitListFilterInfo** object can be reused. Calling **Initialize** more than one time frees any previously contained array of change unit IDs and replaces it with the array that is specified by *ppbChangeUnitIds*.

## See also

[IChangeUnitListFilterInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeunitlistfilterinfo)