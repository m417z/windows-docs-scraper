# IStillImageW::GetDeviceValue

## Description

The **IStillImage::GetDeviceValue** method returns registry information associated with a specified still image device.

## Parameters

### `pwszDeviceName` [in]

Caller-supplied pointer to a string representing an internal device name, obtained by calling [IStillImage::GetSTILaunchInformation](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543790(v=vs.85)) or [IStillImage::GetDeviceList](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543784(v=vs.85)).

### `pValueName` [in]

Caller-supplied pointer to a string representing a registry value name.

### `pType` [out]

Receives a constant representing the data type of the returned registry value.

### `pData` [out]

Caller-supplied pointer to a buffer to receive a returned value.

### `cbData` [in, out]

Caller-supplied size, in bytes, of the buffer pointed to by *pData*. The method modifies this value to represent the size of the returned data. If the specified buffer size is too small, the method supplies the required buffer size and returns an error code.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The purpose of the **IStillImage::GetDeviceValue** method is to return the values currently assigned to device-specific [Registry Entries for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/registry-entries-for-still-image-devices). The method calls **RegQueryValueEx** (described in the Microsoft Windows SDK documentation).

The **IStillImage::GetDeviceValue** method can return either an ANSI or a Unicode string. It can return a Unicode string only if your code is built as Unicode with Unicode defined.

Before calling **IStillImage::GetDeviceValue**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.

## See also

[IStillImage::SetDeviceValue](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543801(v=vs.85))

[IStillImageW](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)