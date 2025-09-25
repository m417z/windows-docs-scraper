# IOfflineFilesConnectionInfo::SetConnectState

## Description

Sets the connection state for an item.

Note that the entire scope of the item is transitioned, not just the item. An item's scope is defined as the closest ancestor shared folder of the item.

## Parameters

### `hwndParent` [in]

Provides a parent window handle used for any interactive user interface elements such as credential request dialogs. This parameter may be **NULL**. This parameter is ignored if the OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE flag is not specified in the *dwFlags* parameter.

### `dwFlags` [in]

One or more of the following flag values:

#### OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE (0x00000001)

Set this flag if the operation is allowed to display user interface elements as necessary. An example is the system's credential-request dialog. If this flag is set, the value in the *hwndParent* parameter is used as the parent window for any user interface elements displayed.

#### OFFLINEFILES_TRANSITION_FLAG_CONSOLE (0x00000002)

This flag is ignored if the OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE flag is not set. If the OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE flag is set, this flag indicates that any UI produced should be directed to the console window associated with the process invoking the operation.

### `ConnectState` [in]

Specify one of the following [OFFLINEFILES_CONNECT_STATE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_connect_state) enumeration values.

#### OFFLINEFILES_CONNECT_STATE_OFFLINE

Transition the item to offline. Note that this operation will fail if there are currently open handles to affected files that are not cached by Offline Files. The [IOfflineFilesConnectionInfo::TransitionOffline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitionoffline) method allows you to control the closing of such handles.

#### OFFLINEFILES_CONNECT_STATE_ONLINE

Transitions the item online if possible. This is equivalent to the [IOfflineFilesConnectionInfo::TransitionOnline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitiononline) method.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

The [IOfflineFilesConnectionInfo::TransitionOnline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitiononline) and [IOfflineFilesConnectionInfo::TransitionOffline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitionoffline) methods are preferred over this method as they provide greater control over the handling and detecting of open handles in the online-to-offline transition.

## See also

[IOfflineFilesConnectionInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesconnectioninfo)

[IOfflineFilesConnectionInfo::TransitionOffline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitionoffline)

[IOfflineFilesConnectionInfo::TransitionOnline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitiononline)

[OFFLINEFILES_CONNECT_STATE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_connect_state)