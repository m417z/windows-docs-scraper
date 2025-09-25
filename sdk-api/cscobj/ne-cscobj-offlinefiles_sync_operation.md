# OFFLINEFILES_SYNC_OPERATION enumeration

## Description

Indicates the type of sync operation that was being performed when a sync error was encountered.

## Constants

### `OFFLINEFILES_SYNC_OPERATION_CREATE_COPY_ON_SERVER:0`

Operation was creating a new file or directory copy on the server.

### `OFFLINEFILES_SYNC_OPERATION_CREATE_COPY_ON_CLIENT`

Operation was creating a new file or directory copy on the client.

### `OFFLINEFILES_SYNC_OPERATION_SYNC_TO_SERVER`

Operation was synchronizing a file or directory from the client to the server.

### `OFFLINEFILES_SYNC_OPERATION_SYNC_TO_CLIENT`

Operation was synchronizing a file or directory from the server to the client.

### `OFFLINEFILES_SYNC_OPERATION_DELETE_SERVER_COPY`

Operation was deleting a copy from the server.

### `OFFLINEFILES_SYNC_OPERATION_DELETE_CLIENT_COPY`

Operation was deleting a copy from the local cache on the client.

### `OFFLINEFILES_SYNC_OPERATION_PIN`

Operation was pinning a file or directory into the local cache.

### `OFFLINEFILES_SYNC_OPERATION_PREPARE`

Operation was preparing for the synchronization. Preparation involves obtaining directory listings from the client and server, comparing the two, and building a list of items to be synchronized.

## See also

[IOfflineFilesSyncErrorInfo::GetSyncOperation](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncerrorinfo-getsyncoperation)