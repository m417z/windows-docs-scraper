# ISyncMgrConflictFolder::GetConflictIDList

## Description

Maps a conflict to its [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

## Parameters

### `pConflict` [in]

Type: **[ISyncMgrConflict](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflict)***

A pointer to an [ISyncMgrConflict](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflict) interface.

### `ppidlConflict` [out]

Type: **PIDLIST_RELATIVE***

A pointer to a PIDL, specified relative to the folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.