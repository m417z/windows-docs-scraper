# SYNC_SESSION_STATISTICS structure

## Description

Represents statistics about a single, unidirectional synchronization session.

## Members

### `dwChangesApplied`

The total number of changes that were successfully applied during the synchronization session. This value is the sum of item changes plus change unit changes.

### `dwChangesFailed`

The total number of changes that were not applied during a session. This value is the sum of item changes plus change unit changes.

## See also

[IKnowledgeSyncProvider::ProcessChangeBatch Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-processchangebatch)

[IKnowledgeSyncProvider::ProcessFullEnumerationChangeBatch Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-processfullenumerationchangebatch)

[Windows Sync Structures](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-structures)