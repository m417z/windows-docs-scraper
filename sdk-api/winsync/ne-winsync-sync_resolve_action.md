# SYNC_RESOLVE_ACTION enumeration

## Description

Represents actions that are taken to resolve a specific concurrency conflict.

## Constants

### `SRA_DEFER:0`

Ignore the conflict and do not apply the change. The change applier does not pass the conflict data to the destination provider.

### `SRA_ACCEPT_DESTINATION_PROVIDER`

The change made on the destination replica wins. Only version information for the item is updated in the metadata on the destination replica. No item data changes are made.

### `SRA_ACCEPT_SOURCE_PROVIDER`

The change made on the source replica wins. The change is applied to the destination replica exactly like any non-conflicting change.

### `SRA_MERGE`

Merge the data from the source item into the destination item. The destination provider combines the source item data and the destination item data, and applies the result to the destination replica.

### `SRA_TRANSFER_AND_DEFER`

Log the conflict and do not apply the change.

### `SRA_LAST`

A placeholder for the last element in the enumeration. Do not use this value.

## Remarks

The members of **SYNC_RESOLVE_ACTION** specify the action that the change applier uses to resolve a concurrency conflict. Concurrency conflicts occur when the same item or change unit is changed on two different replicas that are later synchronized.

## See also

[IChangeConflict::GetResolveActionForChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ichangeconflict-getresolveactionforchange)

[IChangeConflict::SetResolveActionForChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ichangeconflict-setresolveactionforchange)

[Windows Sync Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-enumerations)