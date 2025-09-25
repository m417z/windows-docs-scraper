## Description

A still image minidriver's **IStiUSD::GetNotificationData* method returns a description of the most recent event that occurred on a still image device.

## Parameters

### `lpNotify`

Caller-supplied pointer to an [STINOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_stinotify) structure to receive event information.

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h*. If no events have occurred since the last time the method was called, the method should return STIERR_NOEVENTS.

## Remarks

Each time a device event occurs, the still image event monitor calls**IStiUSD::GetNotificationData to obtain an event description. These descriptions are added to a linked list and when an application calls [IStiDevice::GetLastNotificationData](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getlastnotificationdata), the most recent addition to the list is returned.