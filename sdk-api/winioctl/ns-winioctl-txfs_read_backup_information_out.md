# TXFS_READ_BACKUP_INFORMATION_OUT structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains a Transactional NTFS (TxF) specific structure. This information should only be used when
calling
[TXFS_WRITE_BACKUP_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-txfs_write_backup_information).

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.BufferLength`

If the buffer is not large enough, this member receives the required buffer size.

### `DUMMYUNIONNAME.Buffer`

The buffer for the data.

## See also

[FSCTL_TXFS_READ_BACKUP_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_read_backup_information)