# SYNCMGR_PRESENTER_CHOICE enumeration

## Description

Describes what choice a user makes about a sync manager conflict resolution. Used by [ISyncMgrConflictPresenter](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictpresenter).

## Constants

### `SYNCMGR_PC_NO_CHOICE:0`

The user is skipping this conflict, or conflict resolution is being canceled.

### `SYNCMGR_PC_KEEP_ONE`

The user chooses to keep only one item.

### `SYNCMGR_PC_KEEP_MULTIPLE`

The user chooses to keep multiple items.

### `SYNCMGR_PC_KEEP_RECENT`

The user chooses to keep the most recent item.

### `SYNCMGR_PC_REMOVE_FROM_SYNC_SET`

The item is to be removed from the sync set.

### `SYNCMGR_PC_SKIP`

The item is not being resolved now but is instead being skipped so that it can be resolved later.

## See also

[ISyncMgrConflictResolveInfo::GetPresenterChoice](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-getpresenterchoice)

[ISyncMgrConflictResolveInfo::SetPresenterChoice](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-setpresenterchoice)