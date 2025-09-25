# TXFS_LIST_TRANSACTION_LOCKED_FILES structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains a list of files locked by a transacted writer.

## Members

### `KtmTransaction`

The KTM transaction to enumerate locked files for in this RM.

### `NumberOfFiles`

The number of files involved for the specified transaction on this resource manager.

### `BufferSizeRequired`

The length of the buffer required to hold the complete list of files at the time of this call. This is not guaranteed to be the same length as any other subsequent call.

### `Offset`

The offset from the beginning of this structure to the beginning of the first [TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_list_transaction_locked_files_entry) structure.

## See also

[FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_list_transaction_locked_files)

[TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_list_transaction_locked_files_entry)