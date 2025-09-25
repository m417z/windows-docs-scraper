# TXFS_TRANSACTION_ACTIVE_INFO structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains the flag that indicates whether transactions were active or not when a snapshot was taken.

## Members

### `TransactionsActiveAtSnapshot`

This member is **TRUE** if the mounted snapshot volume had active transactions when the snapshot was taken; and **FALSE** otherwise.

## See also

[FSCTL_TXFS_TRANSACTION_ACTIVE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_transaction_active)