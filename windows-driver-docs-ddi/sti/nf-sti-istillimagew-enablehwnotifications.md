# IStillImageW::EnableHwNotifications

## Description

The **IStillImage::EnableHwNotifications** method requests the still image event monitor to enable or disable the notification of applications when [Still Image Device Events](https://learn.microsoft.com/windows-hardware/drivers/image/still-image-device-events) occur for a specified device.

## Parameters

### `pwszDeviceName` [in]

Caller-supplied pointer to a string representing an internal device name, obtained by calling [IStillImage::GetSTILaunchInformation](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543790(v=vs.85)) or [IStillImage::GetDeviceList](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543784(v=vs.85)).

### `bNewState`

Caller-supplied value, set to **TRUE** to enable notifications and **FALSE** to disable them.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStillImage::EnableHwNotifications** method enables or disables notifications of still image device events for *all* applications, not just for the calling application. Event notifications are enabled by default. This method is meant for use by applications that intercept events from devices and reroute them.

Before calling **IStillImage::EnableHwNotifications**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.

## See also

[IStillImage::LaunchApplicationForDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543796(v=vs.85))

[IStillImageW](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)