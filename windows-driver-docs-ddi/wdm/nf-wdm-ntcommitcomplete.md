# NtCommitComplete function

## Description

The **ZwCommitComplete** routine notifies KTM that the calling resource manager has finished committing a transaction's data.

## Parameters

### `EnlistmentHandle` [in]

A handle to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects) that was obtained by a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment). The handle must have ENLISTMENT_SUBORDINATE_RIGHTS access to the object.

### `TmVirtualClock` [in, optional]

A pointer to a [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values). This parameter is optional and can be **NULL**.

## Return value

**ZwCommitComplete** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to an enlistment object. |
| **STATUS_INVALID_HANDLE** | The object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the enlistment object. |
| **STATUS_TRANSACTION_NOT_REQUESTED** | The transaction or its enlistment is not in the correct state. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A resource manager must call **ZwCommitComplete** after it has finished servicing a TRANSACTION_NOTIFY_COMMIT [notification](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-notifications).

For more information about **ZwCommitComplete**, see [Handling Commit Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-commit-operations).

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[TmCommitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcommitcomplete)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)