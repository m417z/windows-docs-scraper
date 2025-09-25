# IStillImageW::GetHwNotificationState

## Description

The **IStillImage::GetHwNotificationState** method indicates whether applications will be notified when [Still Image Device Events](https://learn.microsoft.com/windows-hardware/drivers/image/still-image-device-events) occur on a specified device.

## Parameters

### `pwszDeviceName` [in]

Caller-supplied pointer to a string representing an internal device name, obtained by calling [IStillImage::GetSTILaunchInformation](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543790(v=vs.85)) or [IStillImage::GetDeviceList](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543784(v=vs.85)).

### `pbCurrentState` [out]

Receives **TRUE** if event notification is enabled, or **FALSE** otherwise.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

Before calling **IStillImage::GetHwNotificationState**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.

## See also

[IStillImage::EnableHwNotifications](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543780(v=vs.85))

[IStillImageW](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)