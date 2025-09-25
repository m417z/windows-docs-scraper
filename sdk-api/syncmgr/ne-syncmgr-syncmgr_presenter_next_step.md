# SYNCMGR_PRESENTER_NEXT_STEP enumeration

## Description

Describes the next step that is to occur in sync manager conflict resolution. Used by [ISyncMgrConflictPresenter](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictpresenter).

## Constants

### `SYNCMGR_PNS_CONTINUE:0`

The conflict has been resolved and subsequent
selected conflicts should continue to be resolved.

### `SYNCMGR_PNS_DEFAULT`

The default conflict presenter should be used.

### `SYNCMGR_PNS_CANCEL`

All conflict resolution should be canceled.

## See also

[ISyncMgrConflictResolveInfo::GetPresenterNextStep](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-getpresenternextstep)

[ISyncMgrConflictResolveInfo::SetPresenterNextStep](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-setpresenternextstep)