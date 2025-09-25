# ISyncMgrConflictResolveInfo::GetPresenterChoice

## Description

Gets what kind of choice was made and whether to apply the choice to all subsequent conflicts in the set.

## Parameters

### `pnPresenterChoice` [out]

Type: **[SYNCMGR_PRESENTER_CHOICE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_presenter_choice)***

When this method returns, contains a pointer to the choice that was made about the conflict resolution. One of the members of the [SYNCMGR_PRESENTER_CHOICE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_presenter_choice) enumeration.

### `pfApplyToAll` [out]

Type: **BOOL***

When this method returns, contains a pointer to a flag. If **TRUE**, then the given choice is to be applied to all subsequent conflicts in the set, and [ISyncMgrConflictResolveInfo::GetItemChoice](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-getitemchoice) and [ISyncMgrConflictResolveInfo::GetItemChoiceCount](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-getitemchoicecount) have information on how to apply this choice. Otherwise **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISyncMgrConflictResolveInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolveinfo)

[ISyncMgrConflictResolveInfo::SetPresenterChoice](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-setpresenterchoice)