# IPort::GetDeviceProperty

## Description

The GetDeviceProperty method provides simplified access to device properties that are contained in the registry for Plug and Play devices.

## Parameters

### `DeviceProperty`

Identifies the particular device property that the caller is requesting. The valid values for this parameter are the same as those that are defined for the IoGetDeviceProperty call's DeviceProperty parameter.

### `BufferLength`

Specifies the length in bytes of the buffer that is to receive the requested information.

### `PropertyBuffer`

Pointer to the property buffer. This parameter points to a caller-allocated buffer into which the method writes the requested property information. The buffer must be large enough to contain the number of bytes specified in BufferLength.

### `ResultLength`

Output pointer to the length of the returned data. This parameter points to a caller-allocated ULONG variable into which the method writes a count specifying the number of bytes actually written to the PropertyBuffer buffer. If the buffer is too small to contain the information, however, the method instead outputs the required buffer size.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code. If the property buffer provided by the caller is too small, the method will return STATUS_BUFFER_TOO_SMALL and output the needed size in ReturnLength.

## Remarks

This method retrieves the audio adapter's device properties. It is similar in operation to the PcGetDeviceProperty function, except that it automatically retrieves the device properties of the audio adapter rather than requiring a device object to explicitly specify a target device.

## See also

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)