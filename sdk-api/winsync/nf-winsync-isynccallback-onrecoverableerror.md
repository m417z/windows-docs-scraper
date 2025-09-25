# ISyncCallback::OnRecoverableError

## Description

Occurs when a synchronization provider sets a recoverable error when it is loading or saving an item.

## Parameters

### `pRecoverableError` [in]

The recoverable error.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Application-determined error codes.** |  |

## See also

[ISyncCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback)