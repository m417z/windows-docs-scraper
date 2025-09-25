# IOfflineFilesConnectionInfo::GetConnectState

## Description

Determines whether an item is online or offline and, if offline, why.

## Parameters

### `pConnectState` [out]

Receives an [OFFLINEFILES_CONNECT_STATE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_connect_state) enumeration value that indicates whether the item is online or offline.

**Note** This value sets the Offline Status property value in Windows Explorer.

### `pOfflineReason` [out]

If the item is offline, this parameter receives an [OFFLINEFILES_OFFLINE_REASON](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_offline_reason) enumeration value that indicates why the item is offline.

**Note** This value generates the parenthesized suffix in the Offline Status property value in Windows Explorer when the status is offline.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

This method requires that the item have connection state information. If that information is unavailable at the time of this method call, the method call will initiate the extra query of the cache item to obtain the current connection state.

## See also

[IOfflineFilesConnectionInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesconnectioninfo)