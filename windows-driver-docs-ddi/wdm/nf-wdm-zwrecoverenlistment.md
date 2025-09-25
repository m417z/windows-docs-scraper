# ZwRecoverEnlistment function

## Description

The **ZwRecoverEnlistment** routine initiates a recovery operation for the transaction that is associated with a specified enlistment.

## Parameters

### `EnlistmentHandle` [in]

A handle to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects) that was obtained by a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment). The handle must have ENLISTMENT_RECOVER access to the object.

### `EnlistmentKey` [in, optional]

A pointer to the enlistment key value that the resource manager previously specified as the *EnlistmentKey* parameter to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment). This parameter is optional and can be **NULL** if the resource manager did not provide an enlistment key when it called **ZwCreateEnlistment**.

## Return value

**ZwRecoverEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to an enlistment object. |
| **STATUS_INVALID_HANDLE** | The object handle is invalid. |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The transaction or its enlistment is not in the correct state. |
| **STATUS_PENDING** | KTM has added a commit, rollback, or in-doubt notification to the resource manager's notification queue, and the resource manager is not using a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the enlistment object. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

After a resource manager calls **ZwRecoverEnlistment**, KTM delivers either a TRANSACTION_NOTIFY_COMMIT, TRANSACTION_NOTIFY_ROLLBACK, or TRANSACTION_NOTIFY_INDOUBT [notification](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-notifications) for the enlistment. Therefore, unless the resource manager is using a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine, it must immediately call [ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager) if **ZwRecoverEnlistment** returns STATUS_SUCCESS or STATUS_PENDING.

For more information about **ZwRecoverEnlistment**, see [Handling Recovery Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-recovery-operations).

**NtRecoverEnlistment** and **ZwRecoverEnlistment** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[TmRecoverEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmrecoverenlistment)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)