# TmRecoverEnlistment function

## Description

The **TmRecoverEnlistment** routine initiates a recovery operation for the transaction that is associated with a specified enlistment.

## Parameters

### `Enlistment` [in]

A pointer to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects). Your component can receive this pointer as input to a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. Alternatively, your component can call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment), [TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment), or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment) provided.

### `EnlistmentKey` [in]

A pointer to the enlistment key value that the resource manager previously specified as the *EnlistmentKey* parameter to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) or [TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment). This parameter is optional and can be **NULL** if the resource manager did not provide an enlistment key when it called **ZwCreateEnlistment** or **TmCreateEnlistment**.

## Return value

**TmRecoverEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to an enlistment object. |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The transaction or its enlistment is not in the correct state. |
| **STATUS_PENDING** | KTM has added a commit, rollback, or in-doubt notification to the resource manager's notification queue, and the resource manager is not using a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmRecoverEnlistment** routine is a pointer-based version of the [ZwRecoverEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecoverenlistment) routine.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

For more information about recovery operations, see [Handling Recovery Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-recovery-operations).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[TRANSACTION_NOTIFICATION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff564813(v=vs.85))

[TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)

[ZwRecoverEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecoverenlistment)