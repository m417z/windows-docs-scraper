# ZwRollforwardTransactionManager function

## Description

The **ZwRollforwardTransactionManager** routine initiates recovery operations for all of the in-progress transactions that are assigned to a specified transaction manager.

## Parameters

### `TransactionManagerHandle` [in]

A handle to a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects) that was obtained by a previous call to [ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager) or [ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager). The handle must have TRANSACTIONMANAGER_RECOVER access to the object.

### `TmVirtualClock` [in, optional]

A pointer to a [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values). This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section.

## Return value

**ZwRollforwardTransactionManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to a transaction manager object. |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the transaction manager object. |
| **STATUS_TM_VOLATILE** | The specified transaction manager object does not have a log file, so recovery is not available. |
| **STATUS_UNSUCCESSFUL** | The specified transaction manager object is in an unexpected state. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **ZwRollforwardTransactionManager** routine recovers all logged activity that KTM finds in the transaction manager's log file, up to and including the virtual clock value that the *TmVirtualClock* parameter supplies.

Your component can traverse the log file incrementally by calling **ZwRollforwardTransactionManager** repetitively and setting the *VirtualClock* parameter to a higher value before each call.

If the *TmVirtualClock* parameter is **NULL**, calling **ZwRollforwardTransactionManager** is equivalent to calling [ZwRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecovertransactionmanager).

For more information about recovery operations, see [Handling Recovery Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-recovery-operations).

**NtRollforwardTransactionManager** and **ZwRollforwardTransactionManager** are two versions of the same Windows Native System Services routine. The **NtRollforwardTransactionManager** routine in the Windows kernel is not directly accessible to kernel-mode drivers. However, kernel-mode drivers can access this routine indirectly by calling the **ZwRollforwardTransactionManager** routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[TmRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmrecovertransactionmanager)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager)

[ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager)

[ZwRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecovertransactionmanager)