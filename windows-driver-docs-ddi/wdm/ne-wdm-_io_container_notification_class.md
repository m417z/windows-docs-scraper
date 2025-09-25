# _IO_CONTAINER_NOTIFICATION_CLASS enumeration

## Description

The **IO_CONTAINER_NOTIFICATION_CLASS** enumeration contains constants that indicate the classes of events for which a kernel-mode driver can register to receive notifications.

## Constants

### `IoSessionStateNotification`

Session state notifications. The driver uses this enumeration constant to request notifications about changes in the state of user sessions that the driver is interested in.

### `IoMaxContainerNotificationClass`

Specifies the maximum value in this enumeration type.

## Remarks

To register for notifications, a driver calls the [IoRegisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistercontainernotification) routine and sets this routine's *NotificationClass* parameter to an **IO_CONTAINER_NOTIFICATION_CLASS** constant (other than **IoMaxContainerNotificationClass**). Currently, **IoRegisterContainerNotification** supports only *NotificationClass* = **IoSessionStateNotification**.

## See also

[IoRegisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistercontainernotification)