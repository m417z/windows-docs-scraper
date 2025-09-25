# NtRollbackTransaction function

## Description

The **ZwRollbackTransaction** routine initiates a rollback operation for a specified transaction.

## Parameters

### `TransactionHandle` [in]

A handle to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects) that was obtained by a previous call to [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) or [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction). The handle must have TRANSACTION_ROLLBACK access to the object.

### `Wait` [in]

A Boolean value that the caller sets to **TRUE** for synchronous operation or **FALSE** for asynchronous operation. If this parameter is set to **TRUE**, the call does not return until the rollback operation is complete.

## Return value

**ZwRollbackTransaction** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The handle that the *TransactionHandle* parameter specifies is not a handle to a transaction object. |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the transaction object. |
| **STATUS_TRANSACTION_ALREADY_COMMITTED** | The transaction cannot be rolled back because it has already been committed. |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The transaction has not been committed but its current state does not permit rollback. |
| **STATUS_PENDING** | Rollback notifications have been queued to resource managers, and the caller specified **FALSE** for the *Wait* parameter. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For more information about **ZwRollbackTransaction**, see [Handling Rollback Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-rollback-operations).

**NtRollbackEnlistment** and **ZwRollbackEnlistment** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommittransaction)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)

[ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)