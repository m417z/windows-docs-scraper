# ISyncSessionState::LoadInfoFromChangeApplication

## Description

Stores data for a serialized change applier.

## Parameters

### `pbChangeApplierInfo` [in]

The serialized change applier data.

### `cbChangeApplierInfo` [in]

Specifies the number of bytes in *pbChangeApplierInfo*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_INVALIDARG** | *pbChangeApplierInfo* is not **NULL** and *cbChangeApplierInfo* is zero. |
| **SYNC_E_DESERIALIZATION** | The serialized data is not valid. |

## See also

[ISyncSessionState Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionstate)