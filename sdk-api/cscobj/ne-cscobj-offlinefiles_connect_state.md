# OFFLINEFILES_CONNECT_STATE enumeration

## Description

Describes the connection state of an item in the Offline Files cache.

## Constants

### `OFFLINEFILES_CONNECT_STATE_UNKNOWN:0`

Returned by [IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) if the method fails.

### `OFFLINEFILES_CONNECT_STATE_OFFLINE`

Returned by [IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) if the item is offline. Pass this value to [IOfflineFilesConnectionInfo::SetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-setconnectstate) to transition the item to offline.

### `OFFLINEFILES_CONNECT_STATE_ONLINE`

Returned by [IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) if the item is online. Pass this value to [IOfflineFilesConnectionInfo::SetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-setconnectstate) to transition the item to online.

### `OFFLINEFILES_CONNECT_STATE_TRANSPARENTLY_CACHED`

Returned by [IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) if the item is transparently cached.

**Windows Server 2008 and Windows Vista:** This value is not supported before Windows Server 2008 R2 and Windows 7.

### `OFFLINEFILES_CONNECT_STATE_PARTLY_TRANSPARENTLY_CACHED`

Returned by [IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate) if the item contains both transparently cached data and data that can be made available offline.

**Windows Server 2008 and Windows Vista:** This value is not supported before Windows Server 2008 R2 and Windows 7.

## Remarks

Transparently cached data is accessible only when the client is connected to the server.

## See also

[IOfflineFilesConnectionInfo::GetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-getconnectstate)

[IOfflineFilesConnectionInfo::SetConnectState](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-setconnectstate)