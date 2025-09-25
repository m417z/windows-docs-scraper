# ISyncKnowledge::ConvertVersion

## Description

Converts a version from another replica into one that is compatible with the replica that owns this knowledge.

## Parameters

### `pKnowledgeIn` [in]

A knowledge that is valid for *pbCurrentOwnerId* and that contains *pVersionIn*.

### `pbCurrentOwnerId` [in]

The ID of the replica that owns *pVersionIn*.

### `pVersionIn` [in]

The version to convert.

### `pbNewOwnerId` [in]

Returns the ID of the replica that owns the converted version.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbNewOwnerId*. Returns the number of bytes required to retrieve the ID when *pbNewOwnerId* is too small, or returns the number of bytes written.

### `pVersionOut` [out]

Returns the version. This is converted to be valid for the replica that owns this knowledge.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbNewOwnerId* is too small. In this case, the required number of bytes is returned in *pcbIdSize*. |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[SYNC_VERSION Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_version)