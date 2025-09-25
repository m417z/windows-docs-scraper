# ISyncMgrConflict::Resolve

## Description

Resolves the conflict using its own sync handler, controls UI.

## Parameters

### `pResolveInfo` [in]

Type: **[ISyncMgrConflictResolveInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolveinfo)***

A pointer to a [ISyncMgrConflictResolveInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolveinfo).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Note that the store must tell the sync center if the conflict was removed by calling [UpdateConflicts](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updateconflicts) after the conflict is resolved. The conflict is assumed to still exist until the store notifies the sync center of changes. The resolution choices for user selection are available through [ISyncMgrConflictResolveInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolveinfo).