# DEDUP_CONTAINER_EXTENT structure

## Description

A logical container file may be stored in a single segment or multiple segments in the backup store.
**DEDUP_CONTAINER_EXTENT** represents a single
extent of a specific container file as stored in the backup store. The extent may be the full container file or a
portion of the file.

## Members

### `ContainerIndex`

The index in the container list passed to
[IDedupReadFileCallback::OrderContainersRestore](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupreadfilecallback-ordercontainersrestore)
to which this container extent structure corresponds.

### `StartOffset`

Offset, in bytes, from the beginning of the container to the beginning of the extent.

### `Length`

Length, in bytes, of the extent.

## Remarks

For example, in an incremental backup scheme, the container may reside in the store either as one complete file
generated in a full backup, or as multiple incremental files that contain changes in the file since the previous
backup.

## See also

[IDedupReadFileCallback::OrderContainersRestore](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupreadfilecallback-ordercontainersrestore)