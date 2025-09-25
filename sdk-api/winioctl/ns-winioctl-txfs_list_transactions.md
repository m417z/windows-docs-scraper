# TXFS_LIST_TRANSACTIONS structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains a list of transactions.

## Members

### `NumberOfTransactions`

The number of transactions for this resource manager.

### `BufferSizeRequired`

The length of the buffer required to hold the complete list of transactions at the time of this call. The number of transactions returned from one call to the next can change depending on the number of active transactions at any given point in time. If this call returns a request for a larger buffer, that size may or may not be adequate for the next call, based on the number of active transactions at the time of the next call.

## See also

[FSCTL_TXFS_LIST_TRANSACTIONS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_list_transactions)

[TXFS_LIST_TRANSACTIONS_ENTRY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-txfs_list_transactions_entry)