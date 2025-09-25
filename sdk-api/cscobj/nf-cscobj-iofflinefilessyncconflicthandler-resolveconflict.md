# IOfflineFilesSyncConflictHandler::ResolveConflict

## Description

Provides a resolution decision for a sync conflict.

## Parameters

### `pszPath` [in]

The fully qualified UNC path of the item in conflict.

### `fStateKnown` [in]

Indicates if the sync state was based on the client state, server state, or both. This parameter can be one or both of the following flag values.

#### OFFLINEFILES_SYNC_STATE_LOCAL_KNOWN (0x00000001)

The sync state was based on the client state.

#### OFFLINEFILES_SYNC_STATE_REMOTE_KNOWN (0x00000002)

The sync state was based on the server state.

### `state` [in]

A value from the [OFFLINEFILES_SYNC_STATE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_sync_state) enumeration indicating the state of the item in conflict.

### `fChangeDetails` [in]

In cases where the *state* code indicates a change in item state, this value describes the change in further detail. The value can be either **OFFLINEFILES_CHANGES_NONE** (0x00000000) or one or more of the following flag values:

#### OFFLINEFILES_CHANGES_LOCAL_SIZE (0x00000001)

Local file size has changed.

#### OFFLINEFILES_CHANGES_LOCAL_ATTRIBUTES (0x00000002)

Local file attributes have changed.

#### OFFLINEFILES_CHANGES_LOCAL_TIME (0x00000004)

Local file change time has changed.

#### OFFLINEFILES_CHANGES_REMOTE_SIZE (0x00000008)

Remote file size has changed.

#### OFFLINEFILES_CHANGES_REMOTE_ATTRIBUTES (0x00000010)

Remote file attributes have changed.

#### OFFLINEFILES_CHANGES_REMOTE_TIME (0x00000020)

Remote file change time has changed.

### `pConflictResolution` [out]

Receives the desired resolution code. Specify a value from the [OFFLINEFILES_SYNC_CONFLICT_RESOLVE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_sync_conflict_resolve) enumeration.

### `ppszNewName` [out]

If the value of the *pConflictResolution* parameter is **OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPALLCHANGES**, the conflict handler must provide a new name for the item. This new name is used for the new copies created remotely and locally. Note that this is a file name, not a fully qualified path.

The name string must be allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc).

This parameter may be **NULL** if a new name is not required by the resolution.

The Offline Files conflict handler used by Sync Center creates a name of the following format:

<original name> (<user name> v*N*).<original ext>

where *N* is a version number. Therefore, if the original file name is "samples.doc" and the user's name is "Alice", the new file name will be:

"samples (Alice v1).doc"

If a file of that name exists the Offline Files conflict handler increments *N* until a unique name is found, for example:

* samples (Alice v2).doc
* samples (Alice v3).doc

This description is provided only to illustrate how the Offline Files conflict handler in Sync Center creates new file names. An implementation of [IOfflineFilesSyncConflictHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncconflicthandler) is free to use any name format that it wishes to define.

## Return value

The return value is ignored.

## See also

[IOfflineFilesSyncConflictHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncconflicthandler)