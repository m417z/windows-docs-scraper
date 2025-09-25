# ISyncMgrConflictResolveInfo::SetPresenterChoice

## Description

Sets what kind of choice was made about a sync manager conflict resolution and whether to apply the choice to all subsequent conflicts in the set.

## Parameters

### `nPresenterChoice` [in]

Type: **[SYNCMGR_PRESENTER_CHOICE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_presenter_choice)**

The choice that was made about the conflict resolution. One of the members of the [SYNCMGR_PRESENTER_CHOICE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_presenter_choice) enumeration.

### `fApplyToAll` [in]

Type: **BOOL**

If **TRUE**, then apply the given choice to all subsequent conflicts in the set. In this case, [ISyncMgrConflictResolveInfo::SetItemChoices](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-setitemchoices) must also be called.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISyncMgrConflictResolveInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolveinfo)

[ISyncMgrConflictResolveInfo::GetPresenterChoice](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-getpresenterchoice)