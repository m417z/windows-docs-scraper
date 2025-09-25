# IStillImageW::GetSTILaunchInformation

## Description

The **IStillImage::GetSTILaunchInformation** method returns the reason the calling still image application was started, if the still image event monitor started it.

## Parameters

### `pwszDeviceName` [out]

Caller-supplied pointer to a buffer, STI_MAX_INTERNAL_NAME_LENGTH bytes in length, to receive the internal device name of the still image device for which the application was started.

### `pdwEventCode` [out, optional]

Reserved for future use.

### `pwszEventName` [out]

Caller-supplied pointer to a buffer that is large enough to receive a string representation of a GUID. The GUID represents the [Still Image Device Events](https://learn.microsoft.com/windows-hardware/drivers/image/still-image-device-events) for which the application was started.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

If the still image event monitor started the application, the *pwszDeviceName* and *pwszEventName* values identify the **/StiDevice** and **/StiEvent** command-line arguments (see the description of [IStillImage::RegisterLaunchApplication](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543798(v=vs.85))). If the event monitor did not start the application, the method returns STIERR_GENERIC.

Before calling **IStillImage::GetSTILaunchInformation**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.