# IStillImageW::LaunchApplicationForDevice

## Description

The **IStillImage::LaunchApplicationForDevice** method starts a specified application for a specified still image device.

## Parameters

### `pwszDeviceName` [in]

Caller-supplied pointer to a string representing an internal device name, obtained by calling [IStillImage::GetSTILaunchInformation](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543790(v=vs.85)) or [IStillImage::GetDeviceList](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543784(v=vs.85)).

### `pwszAppName` [in]

Caller-supplied pointer to a string representing the short name of an application that was registered by calling [IStillImage::RegisterLaunchApplication](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543798(v=vs.85)).

### `pStiNotify` [in]

Caller-supplied pointer to an [STINOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_stinotify) structure describing a device event. Typically, the event's GUID is obtained by calling [IStiDevice::GetLastNotificationData](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getlastnotificationdata).

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStillImage::LaunchApplicationForDevice** method can only start applications that have registered themselves by calling [IStillImage::RegisterLaunchApplication](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543798(v=vs.85)). The specified event must be one that the specified device supports. The method mimics the occurrence of a device event, and is useful for applications that intercept events from devices and reroute them. When a user starts the scanner, such an application might, for example, ask the user whether they want to store the scanned image, make a copy, or send a fax.

Before calling **IStillImage::LaunchApplicationForDevice**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.

### Examples

```cpp
HRESULT hRes;
hRes = pStiDevice->GetLastNotificationData(&pNotify);
if (!SUCCEEDED(hRes))
{
    DisplayOutput("->GetLastNotificationData returned %xh %u",
        hReturn,hReturn);
}

// Process or filter events here

// Send event on to app
hRes = pSti->LaunchApplicationForDevice(pStiInfoPtr->szDeviceInternalName,
     L"AppName",
     pNotify);
if (!SUCCEEDED(hRes))
{
    DisplayOutput("->LaunchApplicationForDevice on %S returned %xh %u",
        pStiInfoPtr->szDeviceInternalName,hReturn,hReturn);
}
```