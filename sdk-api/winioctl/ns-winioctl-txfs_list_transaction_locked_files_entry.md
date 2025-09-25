# TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains information about a locked transaction.

## Members

### `Offset`

The offset, in bytes, from the beginning of the
[TXFS_LIST_TRANSACTION_LOCKED_FILES](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-txfs_list_transaction_locked_files)
structure to the next
**TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY**.

### `NameFlags`

Indicates whether the current name was deleted or created in the current transaction. Note that both flags
may appear if the name was both created and deleted in the same transaction. In that case, the
**FileName** member will contain only an empty string with a terminating null character
("\0") because there is no meaningful name to report.

#### TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_CREATED (0x00000001)

#### TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_DELETED (0x00000002)

### `FileId`

The NTFS File ID of the file.

### `Reserved1`

Reserved. Specify zero.

### `Reserved2`

Reserved. Specify zero.

### `Reserved3`

Reserved. Specify zero.

### `FileName`

The path to the file, relative to the volume root. The file name is a NULL-terminated Unicode string.

## See also

[FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_list_transaction_locked_files)

[TXFS_LIST_TRANSACTION_LOCKED_FILES](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-txfs_list_transaction_locked_files)