# IStiDevice::GetLastNotificationData

## Description

The **IStiDevice::GetLastNotificationData** method returns a description of the most recent event that occurred on a still image device.

## Parameters

### `lpNotify` [out]

Caller-supplied pointer to an [STINOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_stinotify) structure to receive event information.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

Each time a [Still Image Device Events](https://learn.microsoft.com/windows-hardware/drivers/image/still-image-device-events) occurs, the still image event monitor calls [IStiUSD::GetNotificationData](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-getnotificationdata) (exported by a vendor-supplied minidriver) to obtain an event description. These descriptions are added to a linked list. If a client of the **IStiDevice** COM interface has called [IStiDevice::Subscribe](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-subscribe), it is notified each time a device event occurs. It can then call **IStiDevice::GetLastNotificationData** to obtain the most recent addition to the linked list of events.

Before calling **IStiDevice::GetLastNotificationData**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.