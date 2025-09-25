# ISyncCallback::OnFullEnumerationNeeded

## Description

Occurs when the forgotten knowledge from the source provider is not contained in the current knowledge of the destination provider.

## Parameters

### `pFullEnumerationAction` [out]

Specifies how a synchronization session should handle the full enumeration.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Application-determined error codes.** |  |

## Remarks

By default, if an application callback is not registered to receive this notification, Windows Sync uses **SFEA_ABORT**.

## See also

[ISyncCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback)

[SYNC_FULL_ENUMERATION_ACTION Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_full_enumeration_action)