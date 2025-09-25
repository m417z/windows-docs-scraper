# ZwGetNotificationResourceManager function

## Description

The **ZwGetNotificationResourceManager** routine retrieves the next [transaction notification](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-notifications) from a specified resource manager's notification queue.

## Parameters

### `ResourceManagerHandle` [in]

A handle to a [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects) that was obtained by a previous call to [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager) or [ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager). The handle must have RESOURCEMANAGER_GET_NOTIFICATION access to the object.

### `TransactionNotification` [out]

A pointer to a caller-allocated buffer that receives information about the retrieved notification. The buffer must be large enough to contain a [TRANSACTION_NOTIFICATION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff564813(v=vs.85)) structure plus additional notification-specific arguments.

### `NotificationLength` [in]

The length, in bytes, of the buffer that the *TransactionNotification* parameter points to.

### `Timeout` [in]

A pointer to a value that specifies a relative or absolute time, in units of 100 nanoseconds. This pointer is optional and can be **NULL**.

If the pointer is **NULL**, **ZwGetNotificationResourceManager** does not return until a transaction notification is available. If a time value is specified, **ZwGetNotificationResourceManager** returns when a notification is available or after the specified time elapses, whichever comes first.

A negative value specifies a time that is relative to the current system time. For example, a relative time value of five seconds causes **ZwGetNotificationResourceManager** to time out five seconds after it is called.

A positive value specifies an absolute time, which is actually relative to 00:00, January 1, 1601. If an absolute time value is specified, the operating system adds the absolute time value to the time value that represents 00:00, January 1, 1601.

If the caller specifies a zero value (instead of a **NULL** pointer), **ZwGetNotificationResourceManager** returns immediately, whether a notification is available or not.

### `ReturnLength` [out, optional]

An optional pointer to a variable. If this pointer is not **NULL**, and if the *NotificationLength* parameter's value is too small, **ZwGetNotificationResourceManager** supplies the required length in the variable and returns STATUS_BUFFER_TOO_SMALL.

### `Asynchronous` [in]

A ULONG value that must be zero. **ZwGetNotificationResourceManager** does not support asynchronous notifications. Use [TmEnableCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmenablecallbacks) to enable asynchronous notifications.

### `AsynchronousContext` [in, optional]

A pointer to a ULONG value. This pointer must be **NULL**.

## Return value

**ZwGetNotificationResourceManager** returns STATUS_SUCCESS if the operation succeeds and a notification is available. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_TIMEOUT** | The time-out interval that *Timeout* specifies elapsed before a notification became available. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to a resource manager object. |
| **STATUS_INVALID_HANDLE** | The object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the resource manager object. |
| **STATUS_BUFFER_TOO_SMALL** | The *NotificationLength* parameter's value is too small. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Use the **ZwGetNotificationResourceManager** routine to obtain notifications synchronously. Use the [TmEnableCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmenablecallbacks) routine to enable asynchronous notifications.

The received [TRANSACTION_NOTIFICATION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff564813(v=vs.85)) structure contains the enlistment key that the resource manager specified when it called [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment). You can use the enlistment key to identify the enlistment that the notification applies to.

For more information about the **ZwGetNotificationResourceManager** routine, see [Creating a Resource Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-resource-manager).

**NtGetNotificationResourceManager** and **ZwGetNotificationResourceManager** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[TRANSACTION_NOTIFICATION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff564813(v=vs.85))

[TmEnableCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmenablecallbacks)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwOpenResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenresourcemanager)