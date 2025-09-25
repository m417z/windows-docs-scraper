# TmRecoverResourceManager function

## Description

The **TmRecoverResourceManager** routine tries to recover the transaction that is associated with each enlistment of a specified [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects).

## Parameters

### `ResourceManager` [in]

A pointer to a resource manager object. To obtain this pointer, your component must call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager) or [ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager) provided.

## Return value

**TmRecoverResourceManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return the following value:

| Return code | Description |
| --- | --- |
| **STATUS_TRANSACTIONMANAGER_NOT_ONLINE** | The transaction manager that is associated with the specified resource manager is not online. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmRecoverResourceManager** routine is a pointer-based version of the [ZwRecoverResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecoverresourcemanager) routine.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager)

[ZwRecoverResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecoverresourcemanager)