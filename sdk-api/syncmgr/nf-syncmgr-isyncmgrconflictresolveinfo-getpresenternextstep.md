# ISyncMgrConflictResolveInfo::GetPresenterNextStep

## Description

Gets what the presenter wants to do as the next step in the sync manager conflict resolution.

## Parameters

### `pnPresenterNextStep` [out]

Type: **[SYNCMGR_PRESENTER_NEXT_STEP](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_presenter_next_step)***

When this method returns, contains a pointer to the next step in conflict resolution. One of the members of the [SYNCMGR_PRESENTER_NEXT_STEP](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_presenter_next_step) enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISyncMgrConflictResolveInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolveinfo)

[ISyncMgrConflictResolveInfo::SetPresenterNextStep](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictresolveinfo-setpresenternextstep)