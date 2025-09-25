# ISyncSessionState::IsCanceled

## Description

Indicates whether the synchronization session has been canceled.

## Parameters

### `pfIsCanceled` [out]

Returns **TRUE** if the synchronization session has been canceled; otherwise, returns **FALSE**.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## See also

[ISyncSessionState Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionstate)