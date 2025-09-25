# CONFLICT_RESOLUTION_POLICY enumeration

## Description

Represents the options for the concurrency conflict resolution policy to use for the synchronization session.

## Constants

### `CRP_NONE:0`

The change applier notifies the synchronization application of each conflict as it occurs, by using the [ISyncCallback::OnConflict](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onconflict) method. The application examines the conflicting items and specifies the conflict resolution action by calling [IChangeConflict::SetResolveActionForChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ichangeconflict-setresolveactionforchange) or [IChangeConflict::SetResolveActionForChangeUnit](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ichangeconflict-setresolveactionforchangeunit).

### `CRP_DESTINATION_PROVIDER_WINS`

The change made on the destination replica always wins. This supports the case in which the destination replica does not consume changes that are made by remote clients.

### `CRP_SOURCE_PROVIDER_WINS`

The change made on the source replica always wins. This supports a read-only synchronization solution in which the destination replica is not to be trusted.

### `CRP_LAST`

A placeholder for the last element in the enumeration. Do not use this value.

## Remarks

The members of **CONFLICT_RESOLUTION_POLICY** are used by a synchronization application to specify the policy that the change applier uses to resolve concurrency conflicts that occur during synchronization. Concurrency conflicts occur when the same item or change unit is changed on two different replicas that are later synchronized.

## See also

[IKnowledgeSyncProvider::ProcessChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-processchangebatch)

[IKnowledgeSyncProvider::ProcessFullEnumerationChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-processfullenumerationchangebatch)

[Windows Sync Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-enumerations)