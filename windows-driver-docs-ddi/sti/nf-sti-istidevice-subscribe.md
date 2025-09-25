## Description

The **IStiDevice::Subscribe** method registers the caller to receive notifications of device events.

## Parameters

### `lpSubsribe` [in, out]

Caller-supplied pointer to an [STISUBSCRIBE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_stisubscribe) structure containing subscription parameter values.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDevice::Subscribe** method is typically called by applications that intercept events from devices and reroute them. The method allows these applications to be notified of [Still Image Device Events](https://learn.microsoft.com/windows-hardware/drivers/image/still-image-device-events) so they can then dispatch control to appropriate display applications.

Based on contents supplied in the [STISUBSCRIBE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_stisubscribe) structure, the caller can request to be notified of device events by Windows messages or by Win32 events (by means of **SetEvent** calls).

When the application receives notification of an event, it can call [IStiDevice::GetLastNotificationData](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getlastnotificationdata) to find out which event occurred.

Before calling **IStiDevice::Subscribe**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.

## See also

[IStiDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)

[IStiDevice::UnSubscribe](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unsubscribe)

[IStillImage::LaunchApplicationForDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543796(v=vs.85))