# ISyncChangeBatchBase2::SerializeWithOptions

## Description

Serializes the change batch object data to a byte array, based on the specified version and serialization options.

## Parameters

### `targetFormatVersion` [in]

The serialized change batch is compatible with this version.

### `dwFlags` [in]

Reserved. Must be zero.

### `pbBuffer` [in, out]

The serialized change batch object data is serialized to this buffer.

### `pdwSerializedSize` [in, out]

The number of bytes in *pbBuffer*. Returns either the number of bytes that are required to serialize the change batch data when *pbBuffer* is too small, or the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwFlags* is not zero, or the version that is specified by *targetFormatVersion* is incompatible with the change batch object data. |
| **E_OUTOFMEMORY** |  |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pBuffer* is too small. In this situation, the required number of bytes is returned in *pdwSerializedSize*. |
| **SYNC_E_INVALID_OPERATION** | The change batch contains a group that was started but not ended. |
| **SYNC_E_INVALID_VERSION** | The value of *targetFormatVersion* is higher than the version of the object, or the object contains elements that are not compatible with *targetFormatVersion*. |

## Remarks

The following table describes the flags that specify information about an [ISyncFilterInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfilterinfo) object.

| SYNC_FILTER_INFO_FLAG value | Description |
| --- | --- |
| **SYNC_FILTER_INFO_FLAG_ITEM_LIST** | This flag indicates that the set of items synchronized is restricted by an item filter. |
| **SYNC_FILTER_INFO_FLAG_CHANGE_UNIT_LIST** | An [IChangeUnitListFilterInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeunitlistfilterinfo) object specifies that changes apply only to a subset of the change units that are defined for the scope. |

## See also

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)

[ISyncChangeBatchBase2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase2)

[ISyncFilterInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfilterinfo)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)

[SyncSerializationVersion Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_serialization_version)