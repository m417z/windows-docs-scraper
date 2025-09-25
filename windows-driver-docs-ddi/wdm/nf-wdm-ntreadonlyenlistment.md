# NtReadOnlyEnlistment function

## Description

The **ZwReadOnlyEnlistment** routine sets a specified enlistment to be read-only.

## Parameters

### `EnlistmentHandle` [in]

A handle to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects) that was obtained by a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment). The handle must have ENLISTMENT_SUBORDINATE_RIGHTS access to the object.

### `TmVirtualClock` [in, optional]

A pointer to a [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values). This parameter is optional and can be **NULL**.

## Return value

**ZwReadOnlyEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to an enlistment object. |
| **STATUS_INVALID_HANDLE** | The object handle is invalid. |
| **STATUS_TRANSACTION_NOT_REQUESTED** | The transaction or its enlistment is not in the correct state. For example, an enlistment cannot be read-only if the ENLISTMENT_SUPERIOR flag was specified to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment). |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the enlistment object. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Your component cannot call **ZwReadOnlyEnlistment** for a [superior enlistment](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager).

For more information about **ZwReadOnlyEnlistment**, see [Creating a Read-Only Enlistment](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

**NtReadOnlyEnlistment** and **ZwReadOnlyEnlistment** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)