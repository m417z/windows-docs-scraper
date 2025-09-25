# IStillImageW::GetDeviceList

## Description

The **IStillImage::GetDeviceList** method returns hardware characteristics for all installed still image devices.

## Parameters

### `dwType`

Reserved parameter, use **NULL**.

### `dwFlags`

Reserved parameter, use **NULL**.

### `pdwItemsReturned` [out]

Receives the number of STI_DEVICE_INFORMATION structures supplied in the buffer referenced by *ppBuffer*.

### `ppBuffer` [out]

Receives a handle to an STI-allocated buffer. This buffer will contain an array of [STI_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_informationw) structures.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStillImage::GetDeviceList** method returns an [STI_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_informationw) structure for each installed still-image device. Structure contents are typically used for creating user interface displays and for finding a device's internal name.

Before calling **IStillImage::GetDeviceList**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.

When the caller has finished using the array of STI_DEVICE_INFORMATION structures referenced by *ppBuffer*, it must deallocate the array by calling **LocalFree** (described in the Microsoft Windows SDK documentation).

## See also

[IStillImage::GetDeviceInfo](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543782(v=vs.85))

[IStillImageW](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)