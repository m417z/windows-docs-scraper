# DDP_FILE_EXTENT structure

## Description

**DDP_FILE_EXTENT** represents the extent of data in a
file that is to be read in a pending call to
[ReadBackupFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupreadfilecallback-readbackupfile).

## Members

### `Length`

Length, in bytes, of the extent.

### `Offset`

Offset, in bytes, from the beginning of the file to the beginning of the extent.

## Remarks

Data Deduplication needs to read only the portions of a container file that back the restore target file.

## See also

[IDedupReadFileCallback::PreviewContainerRead](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupreadfilecallback-previewcontainerread)