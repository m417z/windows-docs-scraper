# IOfflineFilesConnectionInfo::TransitionOffline

## Description

Transitions an item offline if possible.

## Parameters

### `hwndParent` [in]

Provides a parent window handle used for any interactive user interface elements such as credential request dialogs. This parameter may be **NULL**. This parameter is ignored if the **OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE** flag is not set.

### `dwFlags` [in]

One or more of the following flag values:

#### OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE (0x00000001)

Set this flag if the operation is allowed to display user interface elements as necessary. An example is the system's credential-request dialog. If this flag is set, the value in *hwndParent* is used as the parent for any user interface elements displayed.

#### OFFLINEFILES_TRANSITION_FLAG_CONSOLE (0x00000002)

This flag is ignored if the **OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE** flag is not set. If the **OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE** flag is set, this flag indicates that any UI produced should be directed to the console window associated with the process invoking the operation.

### `bForceOpenFilesClosed` [in]

By default, any open handles to files that are not cached by Offline Files prevent the transition to offline. If this parameter is **TRUE**, the operation will forcibly close these files handles, allowing the scope to transition offline.

**Note** If file handles are forcibly closed, this can cause unexpected consequences, depending on the applications that are using those files.

### `pbOpenFilesPreventedTransition` [out]

Receives **TRUE** if open files prevented the transition, or **FALSE** otherwise. This value is useful only if **FALSE** was specified for the *bForceOpenFilesClosed* parameter.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Note that the entire scope of the item is transitioned offline, not just the item. An item's scope is defined as the closest ancestor shared folder of the item.

If open handles prevent the offline transition, the function returns a success value and **pbOpenFilesPreventTransition* receives **TRUE**.

Here is an example of how this method is used: When transitioning a scope offline through Windows Vista Explorer's Work Offline button, this method is first called with the *bForceOpenFilesClosed* parameter set to **FALSE**. If the function indicates that open files prevented the offline transition, Windows Explorer presents a dialog asking the user if they want to force those files closed and repeat the attempt. If they respond affirmatively, the function call is repeated with the *bForceOpenFilesClosed* parameter set to **TRUE**.

## See also

[IOfflineFilesConnectionInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesconnectioninfo)

[IOfflineFilesConnectionInfo::TransitionOnline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesconnectioninfo-transitiononline)