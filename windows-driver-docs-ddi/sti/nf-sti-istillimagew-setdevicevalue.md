# IStillImageW::SetDeviceValue

## Description

The **IStillImage::SetDeviceValue** method sets registry information for a specified still image device.

## Parameters

### `pwszDeviceName` [in]

Caller-supplied pointer to a string representing an internal device name, obtained by calling [IStillImage::GetSTILaunchInformation](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543790(v=vs.85)) or [IStillImage::GetDeviceList](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543784(v=vs.85)).

### `pValueName` [in]

Caller-supplied pointer to a string representing a registry value name.

### `Type`

Caller-supplied REG_-prefixed registry value type. For more information, see **RegSetValueEx** in the Microsoft Windows SDK documentation.

### `pData` [in]

Caller-supplied pointer to the data to be stored.

### `cbData`

Caller-supplied size, in bytes, of the data pointed to by *pData*. For NULL-terminated strings, include the NULL character.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The purpose of the **IStillImage::SetDeviceValue** method is to set values for device-specific [Registry Entries for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/registry-entries-for-still-image-devices). The method calls **RegSetValueEx** (described in the Microsoft Windows SDK documentation).

Before calling **IStillImage::SetDeviceValue**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.

## See also

[IStillImage::GetDeviceValue](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543786(v=vs.85))

[IStillImageW](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)