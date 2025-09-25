# TmCreateEnlistment function

## Description

The **TmCreateEnlistment** routine creates a new [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects) for a transaction.

## Parameters

### `EnlistmentHandle` [out]

A pointer to a caller-allocated variable that receives a handle to the new enlistment object if the call to **TmCreateEnlistment** succeeds.

### `PreviousMode` [in]

The processor mode of the process that will use the enlistment handle to access the enlistment object. This value must be either **UserMode** or **KernelMode**.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the caller's requested access to the enlistment object. For more information about this parameter, see the description of the *DesiredAccess* parameter for [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment).

### `ObjectAttributes` [in]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**. This parameter is optional and can be **NULL**.

### `ResourceManager` [in]

A pointer to a [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects). To obtain this pointer, your component must call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager) or [ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager) provided.

### `Transaction` [in]

A pointer to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects). To obtain this pointer, your component must call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) or [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction) provided. KTM adds this transaction to the list of transactions that the calling resource manager is handling.

### `CreateOptions` [in, optional]

Enlistment option flags. The following table contains the only available flag.

| *CreateOptions* flag | Meaning |
| --- | --- |
| ENLISTMENT_SUPERIOR | The caller is enlisting as a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) for the specified transaction. |

This parameter is optional and can be zero.

### `NotificationMask` [in]

A bitwise OR of the TRANSACTION_NOTIFY_*XXX* values that are defined in Ktmtypes.h. This mask value specifies the types of [transaction notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-notifications) that KTM sends to the caller.

### `EnlistmentKey` [in, optional]

A pointer to caller-defined information that uniquely identifies the enlistment. The resource manager receives this pointer when it calls [ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager) or when KTM calls the [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. The resource manager can maintain a reference count for this key by calling [TmReferenceEnlistmentKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmreferenceenlistmentkey) and [TmDereferenceEnlistmentKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmdereferenceenlistmentkey). This parameter is optional and can be **NULL**.

## Return value

**TmCreateEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The value of the *CreateOptions* or *NotificationMask* parameter is invalid, or KTM could not find the transaction that the *Transaction* parameter specifies. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory allocation failed. |
| **STATUS_TRANSACTIONMANAGER_NOT_ONLINE** | The enlistment failed because KTM or the resource manager is not in an operational state. |
| **STATUS_TRANSACTION_NOT_ACTIVE** | The enlistment failed because the transaction that the *Transaction* parameter specifies is not active. |
| **STATUS_TRANSACTION_SUPERIOR_EXISTS** | The caller tried to register as a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) but a superior enlistment already exists. |
| **STATUS_TM_VOLATILE** | The caller is trying to register as a superior transaction manager, but the caller's resource manager object is [volatile](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager) while the associated transaction manager object is not volatile. |
| **STATUS_ACCESS_DENIED** | The value of the *DesiredAccess* parameter is invalid. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmCreateEnlistment** routine is a pointer-based version of the [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) routine.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager)

[ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)