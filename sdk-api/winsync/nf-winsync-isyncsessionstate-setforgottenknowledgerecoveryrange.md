# ISyncSessionState::SetForgottenKnowledgeRecoveryRange

## Description

Sets the recovery range when the session is performing forgotten knowledge recovery.

## Parameters

### `pRange` [in]

The lower and upper bounds that define the range of IDs to be recovered.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** |  |
| **SYNC_E_ID_FORMAT_MISMATCH** | An item ID in *pRange* is not in the format that is specified by the ID format schema of the provider. |

## See also

[ISyncSessionState Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionstate)