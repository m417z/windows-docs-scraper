# ZwCommitTransaction function

## Description

The **ZwCommitTransaction** routine initiates a commit operation for a specified transaction.

## Parameters

### `TransactionHandle` [in]

A handle to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects). Your component receives this handle from [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) or [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction). The handle must have TRANSACTION_COMMIT access to the object.

### `Wait` [in]

A Boolean value that the caller sets to **TRUE** for synchronous operation or **FALSE** for asynchronous operation. If this parameter is **TRUE**, the call returns after the commit operation is complete.

## Return value

**ZwCommitTransaction** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The handle that was specified for the *TransactionHandle* parameter is not a handle to a transaction object. |
| **STATUS_INVALID_HANDLE** | The specified transaction object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the transaction object. |
| **STATUS_TRANSACTION_SUPERIOR_EXISTS** | The caller cannot commit the transaction because a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) exists. |
| **STATUS_TRANSACTION_ALREADY_ABORTED** | The transaction cannot be committed because it has been rolled back. |
| **STATUS_TRANSACTION_ALREADY_COMMITTED** | The transaction is already committed. |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The commit operation for this transaction has already been started. |
| **STATUS_PENDING** | Commit notifications have been queued to resource managers, and the caller specified **FALSE** for the *Wait* parameter. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For more information about how transaction clients should use the **ZwCommitTransaction** routine, see [Creating a Transactional Client](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-transactional-client).

For more information about commit operations, see [Handling Commit Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-commit-operations).

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[TmCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcommittransaction)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)