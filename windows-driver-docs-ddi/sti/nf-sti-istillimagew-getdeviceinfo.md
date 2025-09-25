# IStillImageW::GetDeviceInfo

## Description

The **IStillImage::GetDeviceInfo** method returns hardware characteristics for a specified still image device.

## Parameters

### `pwszDeviceName` [in]

Caller-supplied pointer to a string representing an internal device name, obtained by calling [IStillImage::GetSTILaunchInformation](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543790(v=vs.85)) or [IStillImage::GetDeviceList](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543784(v=vs.85)).

### `ppBuffer` [out]

Receives a handle to an [STI_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_informationw) structure.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStillImage::GetDeviceInfo** method returns an [STI_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_informationw) structure for the specified still-image device. Structure contents are typically used for creating user interface displays.

Before calling **IStillImage::GetDeviceInfo**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.

When the caller has finished using the STI_DEVICE_INFORMATION structure referenced by *ppBuffer*, it must deallocate the buffer by calling **LocalFree** (described in the Microsoft Windows SDK documentation).

## See also

[IStillImage::GetDeviceList](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543784(v=vs.85))

[IStillImageW](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)