# TmRequestOutcomeEnlistment function

## Description

The **TmRequestOutcomeEnlistment** routine asks KTM to try to provide an immediate outcome (commit or rollback) for the transaction that is associated with a specified enlistment.

## Parameters

### `Enlistment` [in]

A pointer to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects). Your component can receive this pointer as input to a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. Alternatively, your component can call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment), [TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment), or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment) provided.

### `TmVirtualClock` [in]

A pointer to a [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values). This parameter is optional and can be **NULL**.

## Return value

**TmRequestOutcomeEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return the following value:

| Return code | Description |
| --- | --- |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The specified enlistment is a [superior enlistment](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager). |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmRequestOutcomeEnlistment** routine asks KTM to try to provide an immediate outcome (result) for the transaction. A resource manager can call **TmRequestOutcomeEnlistment** after it has called [TmPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmpreparecomplete) or [ZwPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntpreparecomplete), if it later discovers that it cannot wait for an outcome because, for example, a surprise-removal of the disk has occurred. KTM might be able to force a rollback if all resource managers have not finished their prepare operations.

For information about when to use KTM's **Tm*Xxx*** routines instead of Zw*Xxx* routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

For more information about **TmCreateEnlistment**, see [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment)

[TmPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmpreparecomplete)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)

[ZwPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntpreparecomplete)