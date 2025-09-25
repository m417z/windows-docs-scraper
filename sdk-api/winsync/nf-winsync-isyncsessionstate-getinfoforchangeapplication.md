# ISyncSessionState::GetInfoForChangeApplication

## Description

Retrieves stored data for a serialized change applier.

## Parameters

### `pbChangeApplierInfo` [in, out]

Returns the serialized change applier data.

### `pcbChangeApplierInfo` [in, out]

Specifies the number of bytes in *pbChangeApplierInfo*. Returns the number of bytes required to retrieve the change applier data when *pcbChangeApplierInfo* is too small, or returns the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_INVALIDARG** |  |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbChangeApplierInfo* is too small. In this case, the required number of bytes is returned in *pcbChangeApplierInfo*. |

## See also

[ISyncSessionState Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionstate)