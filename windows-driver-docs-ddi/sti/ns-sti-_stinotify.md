# _STINOTIFY structure

## Description

The STINOTIFY structure is used as a parameter to the [IStillImage::LaunchApplicationForDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543796(v=vs.85)), [IStiDevice::GetLastNotificationData](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getlastnotificationdata), and [IStiUSD::GetNotificationData](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-getnotificationdata) methods.

## Members

### `dwSize`

Caller-supplied size, in bytes, of the STINOTIFY structure.

### `guidNotificationCode`

GUID of the event. For more information, see [Still Image Device Events](https://learn.microsoft.com/windows-hardware/drivers/image/still-image-device-events).

### `abNotificationData`

Byte array containing optional, vendor-defined information.