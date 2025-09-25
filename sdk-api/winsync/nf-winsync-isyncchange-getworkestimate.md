# ISyncChange::GetWorkEstimate

## Description

Gets the work estimate for this change.

## Parameters

### `pdwWork` [out]

The work estimate for this change. The default value is zero.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

The work estimate is a part of the total work that is estimated for the batch or the session.

The work estimate is only meaningful when the **ISyncChange** object represents a change from the source provider.

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchange)