# TXFS_LIST_TRANSACTIONS_ENTRY structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains information about a transaction.

## Members

### `TransactionId`

The GUID of the transaction.

### `TransactionState`

The current state of the transaction.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

### `Reserved3`

Reserved.

## See also

[FSCTL_TXFS_LIST_TRANSACTIONS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_list_transactions)

[TXFS_LIST_TRANSACTIONS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-txfs_list_transactions)