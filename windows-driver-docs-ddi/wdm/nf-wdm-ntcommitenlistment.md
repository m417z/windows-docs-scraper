# NtCommitEnlistment function

## Description

The **ZwCommitEnlistment** routine initiates the commit operation for a specified enlistment's transaction.

## Parameters

### `EnlistmentHandle` [in]

A handle to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects) that was obtained by a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment). The object must represent a [superior enlistment](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) and the handle must have ENLISTMENT_SUPERIOR_RIGHTS access to the object.

### `TmVirtualClock` [in, optional]

A pointer to a [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values). This parameter is optional and can be **NULL**.

## Return value

**ZwCommitEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to an enlistment object. |
| **STATUS_INVALID_HANDLE** | The object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the enlistment object. |
| **STATUS_ENLISTMENT_NOT_SUPERIOR** | The caller is not a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) for the enlistment. |
| **STATUS_TRANSACTION_RESPONSE_NOT_ENLISTED** | The caller did not register to receive TRANSACTION_NOTIFY_COMMIT_COMPLETE notifications. |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The enlistment's transaction is not in a state that allows it to be committed. |
| **STATUS_TRANSACTION_NOT_ACTIVE** | The commit operation for this transaction has already been started. |
| **STATUS_TRANSACTION_ALREADY_ABORTED** | The transaction cannot be committed because it has been rolled back. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Only superior transaction managers can call **ZwCommitEnlistment**.

Callers of **ZwCommitEnlistment** must register to receive TRANSACTION_NOTIFY_COMMIT_COMPLETE [notifications](https://learn.microsoft.com/windows-hardware/drivers/mobilebroadband/notifications).

The **ZwCommitEnlistment** routine causes KTM to send TRANSACTION_NOTIFY_COMMIT notifications to all resource managers that have enlisted in the transaction.

For more information about **ZwCommitEnlistment**, see [Creating a Superior Transaction Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) and [Handling Commit Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-commit-operations).

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[TmCommitEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcommitenlistment)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)