# OFFLINEFILES_SYNC_STATE enumeration

## Description

Describes the sync state of an Offline Files item.

## Constants

### `OFFLINEFILES_SYNC_STATE_Stable:0`

The client and server copies of the file are in sync.

### `OFFLINEFILES_SYNC_STATE_FileOnClient_DirOnServer`

The file exists on the client. The directory exists on the server.

### `OFFLINEFILES_SYNC_STATE_FileOnClient_NoServerCopy`

The file exists only on the client.

### `OFFLINEFILES_SYNC_STATE_DirOnClient_FileOnServer`

The directory exists on the client. The file exists on the server.

### `OFFLINEFILES_SYNC_STATE_DirOnClient_FileChangedOnServer`

The directory exists on the client. The server copy of the file has changed.

### `OFFLINEFILES_SYNC_STATE_DirOnClient_NoServerCopy`

The directory exists only on the client.

### `OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_NoServerCopy`

The file was created on the client. There is no server copy of the file.

### `OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileChangedOnServer`

The file was created on the client. The server copy of the file has changed.

### `OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirChangedOnServer`

The file was created on the client. The directory on the server has changed.

### `OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileOnServer`

The file was created on the client. The server has a file with the same name.

### `OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirOnServer`

The file was created on the client. A directory with the same name exists on the server.

### `OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DeletedOnServer`

The file was created on the client. The server copy of the file was deleted.

### `OFFLINEFILES_SYNC_STATE_FileChangedOnClient_ChangedOnServer`

The client copy of the file has changed. The server copy of the file has changed. This value represents the classic change/change sync conflict.

### `OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirOnServer`

The client copy of the file has changed. The directory exists on the server.

### `OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirChangedOnServer`

The client copy of the file has changed. The directory on the server has changed.

### `OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DeletedOnServer`

The client copy of the file has changed. The server copy of the file has been deleted.

### `OFFLINEFILES_SYNC_STATE_FileSparseOnClient_ChangedOnServer`

The file is sparsely cached on the client. The server copy of the file has changed.

### `OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DeletedOnServer`

The file is sparsely cached on the client. The server copy of the file has been deleted.

### `OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DirOnServer`

The file is sparsely cached on the client. The directory exists on the server.

### `OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DirChangedOnServer`

The file is sparsely cached on the client. The directory on the server has changed.

### `OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_NoServerCopy`

The directory has been created on the client. There is no server copy of the directory.

### `OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DirOnServer`

The directory has been created on the client. A directory with the same name exists on the server.

### `OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileOnServer`

The directory has been created on the client. A file with the same name exists on the server.

### `OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileChangedOnServer`

The directory has been created on the client. The server copy of the file has changed.

### `OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DirChangedOnServer`

The directory has been created on the client. The directory on the server has changed.

### `OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DeletedOnServer`

The directory has been created on the client. The directory on the server has been deleted.

### `OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileOnServer`

The client directory has changed. The server has a copy of the file.

### `OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileChangedOnServer`

The client directory has changed. The server copy of the file has been changed.

### `OFFLINEFILES_SYNC_STATE_DirChangedOnClient_ChangedOnServer`

The client directory has changed. The server directory has also changed.

### `OFFLINEFILES_SYNC_STATE_DirChangedOnClient_DeletedOnServer`

The client directory has changed. The directory on the server has been deleted.

### `OFFLINEFILES_SYNC_STATE_NoClientCopy_FileOnServer`

The file exists only on the server.

### `OFFLINEFILES_SYNC_STATE_NoClientCopy_DirOnServer`

The directory exists only on the server.

### `OFFLINEFILES_SYNC_STATE_NoClientCopy_FileChangedOnServer`

The file exists only on the server, and the server copy of the file has changed.

### `OFFLINEFILES_SYNC_STATE_NoClientCopy_DirChangedOnServer`

The directory exists only on the server, and the server directory has changed.

### `OFFLINEFILES_SYNC_STATE_DeletedOnClient_FileOnServer`

The file exists only on the server, because the client copy of the file has been deleted.

### `OFFLINEFILES_SYNC_STATE_DeletedOnClient_DirOnServer`

The directory exists only on the server, because the client directory has been deleted.

### `OFFLINEFILES_SYNC_STATE_DeletedOnClient_FileChangedOnServer`

The client copy of the file has been deleted, and the server copy of the file has changed. This value represents the classic delete/change conflict.

### `OFFLINEFILES_SYNC_STATE_DeletedOnClient_DirChangedOnServer`

The client copy of the directory has been deleted, and the server copy of the directory has changed.

### `OFFLINEFILES_SYNC_STATE_FileSparseOnClient`

The file is sparsely cached on the client.

### `OFFLINEFILES_SYNC_STATE_FileChangedOnClient`

The file has been changed on the client.

### `OFFLINEFILES_SYNC_STATE_FileRenamedOnClient`

This value is reserved for future use.

### `OFFLINEFILES_SYNC_STATE_DirSparseOnClient`

The directory is sparsely cached on the client.

### `OFFLINEFILES_SYNC_STATE_DirChangedOnClient`

The directory has been changed on the client.

### `OFFLINEFILES_SYNC_STATE_DirRenamedOnClient`

This value is reserved for future use.

### `OFFLINEFILES_SYNC_STATE_FileChangedOnServer`

The server copy of the file has been changed.

### `OFFLINEFILES_SYNC_STATE_FileRenamedOnServer`

This value is reserved for future use.

### `OFFLINEFILES_SYNC_STATE_FileDeletedOnServer`

The server copy of the file has been deleted.

### `OFFLINEFILES_SYNC_STATE_DirChangedOnServer`

The server directory has been changed.

### `OFFLINEFILES_SYNC_STATE_DirRenamedOnServer`

This value is reserved for future use.

### `OFFLINEFILES_SYNC_STATE_DirDeletedOnServer`

The server directory has been deleted.

### `OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_FileOnServer`

The file has been replaced and deleted on the client. The server has a copy of the file.

### `OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_FileChangedOnServer`

The file has been replaced and deleted on the client. The server copy of the file has changed.

### `OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_DirOnServer`

The file has been replaced and deleted on the client. The directory exists on the server.

### `OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_DirChangedOnServer`

The file has been replaced and deleted on the client. The directory has changed on the server.

### `OFFLINEFILES_SYNC_STATE_NUMSTATES`

## See also

[IOfflineFilesSyncConflictHandler::ResolveConflict](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncconflicthandler-resolveconflict)

[OFFLINEFILES_SYNC_CONFLICT_RESOLVE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_sync_conflict_resolve)