# SYNC_TRANSFER_STATUS enumeration

## Description

Specifies possible status values used in the System.SyncTransferStatus property.

## Constants

### `STS_NONE:0`

There is no current sync activity.

### `STS_NEEDSUPLOAD:0x1`

The file is pending upload.

### `STS_NEEDSDOWNLOAD:0x2`

The file is pending download.

### `STS_TRANSFERRING:0x4`

The file is currently being uploaded or downloaded.

### `STS_PAUSED:0x8`

The current transfer is paused.

### `STS_HASERROR:0x10`

An error was encountered during the last sync operation.

### `STS_FETCHING_METADATA:0x20`

The sync engine is retrieving metadata from the cloud.

### `STS_USER_REQUESTED_REFRESH:0x40`

### `STS_HASWARNING:0x80`

### `STS_EXCLUDED:0x100`

### `STS_INCOMPLETE:0x200`

### `STS_PLACEHOLDER_IFEMPTY:0x400`