# TmEnableCallbacks function

## Description

The **TmEnableCallbacks** routine enables a callback routine that receives [transaction notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-notifications).

## Parameters

### `ResourceManager` [in]

A pointer to a [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects). To obtain this pointer, your component must call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager) or [ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager) provided.

### `CallbackRoutine` [in]

A pointer to a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) routine.

### `RMKey` [in, optional]

A caller-defined context value that uniquely identifies the resource manager. The caller's *ResourceManagerNotification* routine receives this value as input.

## Return value

**TmEnableCallbacks** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return the following value:

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | The *CallbackRoutine* pointer is **NULL**. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Your resource manager can call **TmEnableCallbacks** to enable a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. Use **TmEnableCallbacks** to enable asynchronous notifications. Use [ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager) to obtain notifications synchronously.

Resource managers can register one callback routine for each resource manager object.

For more information about the **TmEnableCallbacks** routine, see [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager)

[ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager)