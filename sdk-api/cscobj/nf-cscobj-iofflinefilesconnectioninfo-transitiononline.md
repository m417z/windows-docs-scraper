# IOfflineFilesConnectionInfo::TransitionOnline

## Description

Transitions an item online if possible.

## Parameters

### `hwndParent` [in]

Provides a parent window handle used for any interactive user interface elements such as credential request dialogs. This parameter may be **NULL**. This parameter is ignored if the OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE flag is not specified in the *dwFlags* parameter.

### `dwFlags` [in]

One or more of the following flag values:

#### OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE (0x00000001)

Set this flag if the operation is allowed to display user interface elements as necessary. An example is the system's credential-request dialog. If this flag is set, the value in hwndParent is used as the parent for any user interface elements displayed.

#### OFFLINEFILES_TRANSITION_FLAG_CONSOLE (0x00000002)

This flag is ignored if the OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE flag is not set. If the OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE flag is set, this flag indicates that any UI produced should be directed to the console window associated with the process invoking the operation.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Note that the entire scope of the item is transitioned online, not just the item. An item's scope is defined as the closest ancestor shared folder of the item.

## See also

[IOfflineFilesConnectionInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesconnectioninfo)

[IOfflineFilesConnectionInfo::TransitionOffline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitionoffline)