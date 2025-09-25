# PGET_DEVICE_INFORMATION callback function

## Description

The `GetDeviceInformation` routine retrieves information about the HD Audio controller device.

The function pointer type for a `GetDeviceInformation` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface) or the [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2) structure.

### `DeviceInformation` [in, out]

Retrieves information about the HD Audio controller device. This parameter points to a caller-allocated [HDAUDIO_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_device_information) structure into which the routine writes the device information.

## Return value

`GetDeviceInformation` returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows a possible return status code.

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | Indicates that the size specified at the beginning of the *deviceInformation* buffer is too small. |

## Remarks

This routine retrieves device-dependent information that is static-that is, the information does not change dynamically over time.

The *deviceInformation* parameter is a pointer to a buffer that contains an HDAUDIO_DEVICE_INFORMATION structure into which the routine writes information about the HD Audio controller. Before calling `GetDeviceInformation`, the caller allocates the buffer and writes the buffer's size in bytes into the **Size** member at the beginning of the buffer.

## See also

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[HDAUDIO_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_device_information)