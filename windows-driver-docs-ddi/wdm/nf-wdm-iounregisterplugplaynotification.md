## Description

This routine is obsolete in Windows 7 and later versions of Windows. For more information, see the **Remarks** section below.

The **IoUnregisterPlugPlayNotification** routine removes the registration of a driver's callback routine for a PnP event.

## Parameters

### `NotificationEntry` [in]

Pointer to an opaque value representing the registration to be removed. The value was returned by a previous call to [IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification).

## Return value

**IoUnregisterPlugPlayNotification** always returns STATUS_SUCCESS if *NotificationEntry* is valid.

## Remarks

In Windows 7 and later versions of Windows, this function is obsolete and is provided only to support existing drivers. Use the [IoUnregisterPlugPlayNotificationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregisterplugplaynotificationex) routine instead.

The system does not synchronize between the execution of the notification routine and **IoUnregisterPlugPlayNotification**. Therefore, the routine can be called after the **IoUnregisterPlugPlayNotification** method has returned. If necessary, a driver should implement its own mechanism to ignore any notifications after **IoUnregisterPlugPlayNotification** has been called.

**IoUnregisterPlugPlayNotification** removes one PnP notification registration; that is, the registration of one driver callback routine for one PnP event category.

Drivers should unregister a notification first, then free any related context buffer.

A driver cannot be unloaded until it removes all of its PnP notification registrations because there is a reference on its driver object for each active registration.

## See also

[IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)

[IoUnregisterPlugPlayNotificationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregisterplugplaynotificationex)