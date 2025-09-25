# TXFS_SAVEPOINT_INFORMATION structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

The
**FSCTL_TXFS_SAVEPOINT_INFORMATION** structure
specifies the action to perform, and on which transaction.

## Members

### `KtmTransaction`

Handle to the transaction on which to perform the savepoint operation.

### `ActionCode`

Specifies the savepoint action to perform. Valid values are:

| Value | Meaning |
| --- | --- |
| **TXFS_SAVEPOINT_SET**<br><br>1 (0x1) | Creates a new savepoint. |
| **TXFS_SAVEPOINT_ROLLBACK**<br><br>2 (0x2) | Rolls back to the savepoint specified by the **SavepointId** member. |
| **TXFS_SAVEPOINT_CLEAR**<br><br>4 (0x4) | Clears the most recently set savepoint for the specified transaction. |
| **TXFS_SAVEPOINT_CLEAR_ALL**<br><br>16 (0x10) | Clears all savepoints for the transaction. |

### `SavepointId`

If **ActionCode** is **TXFS_SAVEPOINT_SET**, on output,
returns the newly-created savepoint ID.

If **ActionCode** is **TXFS_ROLLBACK_TO_SAVEPOINT**, on
input, specifies the savepoint ID to roll back to. Remains unchanged on output.

If **ActionCode** is **TXFS_SAVEPOINT_CLEAR** or
**TXFS_SAVEPOINT_CLEAR_ALL**, this member is not used; therefore, on input, specify
**NULL**.

## See also

[FSCTL_TXFS_SAVEPOINT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_savepoint_information)