# TXFS_GET_METADATA_INFO_OUT structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains the version information about the miniversion that is created.

## Members

### `TxfFileId`

### `TxfFileId.LowPart`

The lower half of the TxfId of the file referenced by the handle used to call [FSCTL_TXFS_GET_METADATA_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_get_metadata_info). It is unique within a resource manager.

### `TxfFileId.HighPart`

The higher half of the TxfId of the file referenced by the handle used to call [FSCTL_TXFS_GET_METADATA_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_get_metadata_info). It is unique within a resource manager.

### `LockingTransaction`

The **GUID** of the transaction that locked the specified file locked, if the file is locked.

### `LastLsn`

 Receives the last LSN for the most recent log record written for file. It is a property of the file that refers to the log, and references the last log entry of the file.

### `TransactionState`

Indicates the state of the transaction that has locked the file. Valid values are:

#### TXFS_TRANSACTION_STATE_ACTIVE

#### TXFS_TRANSACTION_STATE_NONE

#### TXFS_TRANSACTION_STATE_NOTACTIVETXFS_TRANSACTION_STATE_NOTACTIVE

#### TXFS_TRANSACTION_STATE_PREPARED

## See also

[FSCTL_TXFS_GET_METADATA_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_get_metadata_info)