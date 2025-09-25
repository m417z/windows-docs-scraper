# IChangeUnitListFilterInfo::GetChangeUnitId

## Description

Gets the change unit ID that is stored at the specified index in the array of change unit IDs that define the filter.

## Parameters

### `dwChangeUnitIdIndex` [in]

The index of the change unit ID to look up.

### `pbChangeUnitId` [in, out]

Returns the change unit ID that is stored at the index that is specified by *dwChangeUnitIdIndex*.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbChangeUnitId*. Returns the number of bytes that are required to retrieve the ID when *pbChangeUnitId* is too small, or the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | No filter is defined, or *dwChangeUnitIdIndex* is larger than the number of change unit IDs that are stored in this object. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbChangeUnitId* is too small. In this case, the required number of bytes is returned in *pcbIdSize*. |
| **SYNC_E_ID_FORMAT_MISMATCH** | The change unit ID to be returned is not valid. |

## See also

[IChangeUnitListFilterInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeunitlistfilterinfo)