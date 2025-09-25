# IPortClsNotifications::FreeNotificationBuffer

## Description

Frees a previously allocated IPortClsNotifications buffer. The buffer is used in sending notifications, to allow for communications between audio modules and UWP apps.

For more information about audio modules, see [Implementing Audio Module Discovery](https://learn.microsoft.com/windows-hardware/drivers/audio/implementing-audio-module-communication).

## Parameters

### `NotificationBuffer` [in]

The address of the notification buffer returned in the [IPortClsNotifications::AllocNotificationBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclsnotifications-allocnotificationbuffer) call.

## See also

[IPortClsNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsnotifications)