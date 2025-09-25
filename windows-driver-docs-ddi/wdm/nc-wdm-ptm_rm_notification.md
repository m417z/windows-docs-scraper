# PTM_RM_NOTIFICATION callback function

## Description

A resource manager's *ResourceManagerNotification* callback routine receives and handles [transaction notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-notifications).

## Parameters

### `EnlistmentObject` [in]

A pointer to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects). The *ResourceManagerNotification* callback routine is receiving a notification for the enlistment that this object represents.

### `RMContext` [in]

The value that the resource manager previously specified for the *RMKey* parameter of the [TmEnableCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmenablecallbacks) routine.

### `TransactionContext` [in]

The value that the resource manager previously specified for the *EnlistmentKey* parameter of the [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) routine.

### `TransactionNotification` [in]

One of the TRANSACTION_NOTIFY_*XXX* values that are defined in Ktmtypes.h. This value specifies the type of transaction notification that KTM sent to the caller.

### `TmVirtualClock` [in, out]

A pointer to a location that contains the [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values) at the time that KTM prepared the notification for delivery to the resource manager. If the callback routine increases this value before it returns, KTM updates the virtual clock to the new value. (Typically, resource managers do not modify the virtual clock value.)

### `ArgumentLength` [in]

The length, in bytes, of the buffer that the *Argument* parameter points to. This parameter is zero if a buffer is not available.

### `Argument` [in]

A pointer to a buffer that contains notification-specific arguments. This parameter is **NULL** if the notification that the *TransactionNotification* parameter specifies does not require an argument buffer.

For a list of notifications that include an additional argument buffer, see the Remarks section of [TRANSACTION_NOTIFICATION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff564813(v=vs.85)).

## Return value

*ResourceManagerNotification* callback routine must return STATUS_SUCCESS or another status value for which NT_SUCCESS(**status**) equals **TRUE** if the operation is successful.

Typically, the resource manager returns STATUS_SUCCESS if it services the notification synchronously and STATUS_PENDING if it services the notification asynchronously, but it can return STATUS_PENDING in either case. However, the resource manager can return STATUS_PENDING only for notifications that it responds to by calling one of the **Tm*Xxx*Complete** or **Zw*Xxx*Complete** routines.

In other words, if the resource manager must respond to a notification by calling one of the **Tm*Xxx*Complete** or **Zw*Xxx*Complete** routines, it can return STATUS_PENDING for the notification and later call the appropriate **Tm*Xxx*Complete** or **Zw*Xxx*Complete** routine.

If an error occurs, the callback routine must return a status value for which NT_SUCCESS(status) equals **FALSE**.

## Remarks

To register a *ResourceManagerNotification* callback routine, your resource manager must call [TmEnableCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmenablecallbacks).

Note that *ResourceManagerNotification* callback routines receive a pointer, instead of a handle, to an enlistment object. You can pass the enlistment object pointer to the enlistment object's [TmXxx routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

For more information about *ResourceManagerNotification* callback routines, see [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

The *ResourceManagerNotification* callback routine is called at IRQL = PASSIVE_LEVEL, and it must return at IRQL = PASSIVE_LEVEL.

## See also

[TRANSACTION_NOTIFICATION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff564813(v=vs.85))

[TmEnableCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmenablecallbacks)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager)