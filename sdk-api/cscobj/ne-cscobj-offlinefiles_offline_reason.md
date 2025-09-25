# OFFLINEFILES_OFFLINE_REASON enumeration

## Description

Indicates the reason why an item is offline.

## Constants

### `OFFLINEFILES_OFFLINE_REASON_UNKNOWN:0`

The reason is unknown because the method failed.

### `OFFLINEFILES_OFFLINE_REASON_NOT_APPLICABLE`

The item is online.

### `OFFLINEFILES_OFFLINE_REASON_CONNECTION_FORCED`

[IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) returns this value if the item is offline because the item's scope was forced offline using the [IOfflineFilesConnectionInfo::TransitionOffline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitionoffline) method. When an item has been transitioned offline by the Work Offline button in Windows Explorer, the offline reason is forced. When an item is forced offline, its entire scope is also forced offline. Assuming the remote share is reachable, a scope that is forced offline may be transitioned online using the [IOfflineFilesConnectionInfo::TransitionOnline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitiononline) method.

### `OFFLINEFILES_OFFLINE_REASON_CONNECTION_SLOW`

[IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) returns this value if the item is offline because the item's connection is considered slow. The parameters that define a slow connection are defined by Group Policy. When an item is offline because of a slow connection, its entire scope is also offline for the same reason. Assuming the remote share is reachable, a scope that is offline because of a slow connection may be transitioned online using the [IOfflineFilesConnectionInfo::TransitionOnline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitiononline) method.

### `OFFLINEFILES_OFFLINE_REASON_CONNECTION_ERROR`

[IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) returns this value if the item is offline because of an error in network communications. This normally means that the client computer is disconnected from the network, the server computer is unavailable, or the network shared folder is no longer available. After the source of the error is corrected and the remote share is again reachable, the scope is automatically transitioned online by Offline Files.

### `OFFLINEFILES_OFFLINE_REASON_ITEM_VERSION_CONFLICT`

[IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) returns this value if the item is offline because of an unresolved sync conflict. While working offline, an item was changed both on the client and the server. A subsequent sync operation detected the sync conflict and placed a record of that conflict in the sync conflict store. Sync conflicts may be reviewed in Sync Center's Sync Conflicts folder. To resolve a conflict programmatically, call [IOfflineFilesCache::Synchronize](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-synchronize) with the appropriate conflict resolution mechanism. For more information, see **IOfflineFilesCache::Synchronize**.

### `OFFLINEFILES_OFFLINE_REASON_ITEM_SUSPENDED`

[IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) returns this value if the item is offline because it was suspended. Suspending an item is a way to force it to be always available offline. It is primarily used by Windows features that want to use the offline availability and synchronization capabilities of Offline Files but that also want to control the synchronization. Suspended items are never synchronized automatically by Offline Files.

## See also

[IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate)

[IOfflineFilesConnectionInfo::SetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-setconnectstate)