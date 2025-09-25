# DXGKDDI_I2C_RECEIVE_DATA_FROM_DISPLAY callback function

## Description

The *DxgkDdiI2CReceiveDataFromDisplay* returns data received from an I2C device in a monitor.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem.

### `VidPnTargetId` [in]

An integer that identifies one of the video present targets on the display adapter.

### `SevenBitI2CAddress` [in]

The address of the I2C device from which data will be received.

### `Flags` [in]

A value that specifies whether the length of the data is supplied as part of the data transmitted by the I2C device. This parameter must be set to one of the following values.

|Value|Meaning|
|--- |--- |
|I2C_NO_FLAGS|The data length is supplied by the DataLength parameter. The I2C device does not supply the data length as part of the data that it transmits.|
|I2C_DEVICE_TRANSMITS_DATA_LENGTH|The data length is supplied by the I2C device as part of the data that it transmits. The I2C device transmits at least two bytes. The seven least significant bits of the second byte transmitted contain the intermediate length. You can calculate the number of bytes that will be transmitted after the byte that contains the intermediate length by adding one to the intermediate length.|

### `DataLength` [in]

The length, in bytes, of the buffer pointed to by *Data*.

### `Data` [out]

A pointer to a buffer that receives the data. The buffer can be in paged memory.

## Return value

*DxgkDdiI2CReceiveDataFromDisplay*returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*. The following list gives some of the possible error codes that can be returned.

|Return code|Description|
|--- |--- |
|STATUS_GRAPHICS_MONITOR_NOT_CONNECTED|There is no monitor connected to the video output identified by VidPnTargetId.|
|STATUS_GRAPHICS_I2C_NOT_SUPPORTED|The video output identified by VidPnTargetId does not have an I2C bus.|
|STATUS_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST|No device acknowledged the I2C address supplied in SevenBitI2CAddress. This could mean that no device on the I2C bus has the specified address or that an error occurred when the address was transmitted.|
|STATUS_GRAPHICS_I2C_ERROR_RECEIVING_DATA|The I2C address was successfully transmitted, but there was an error receiving data from the I2C device.|
|STATUS_BUFFER_TOO_SMALL|The value supplied in DataLength is less than the required data buffer size. This return value is meaningful only if the I2C_DEVICE_TRANSMITS_DATA_LENGTH flag is set.|

## Remarks

The video present target identified by *VidPnTargetId* is associated with one of the video outputs on the display adapter. The data is received from an I2C device in the monitor that is connected to that video output.

*DxgkDdiI2CReceiveDataFromDisplay* function is responsible for signaling the I2C start condition, sending the I2C address, receiving the data from the I2C device, sending acknowledgments, and signaling the stop condition. For details about the I2C bus, see the *I2C Bus Specification*, published by Philips Semiconductors. The specification defines a protocol for initiating I2C communication, reading and writing bytes over the I2C data line, and terminating I2C communication. (This resource may not be available in some languages

and countries.)

*DxgkDdiI2CReceiveDataFromDisplay*is required to receive data from an I2C device that has address 0x6F but is permitted to refuse to receive data from any I2C device that has a different address.

*DxgkDdiI2CReceiveDataFromDisplay* is permitted to block if another part of the display miniport driver or graphics hardware is using the specified monitor's I2C bus. It is also permitted to block if the display miniport driver is using the I2C bus to send or receive High-bandwidth Digital Content Protection (HDCP) data.

If the display adapter supports HDCP, *DxgkDdiI2CReceiveDataFromDisplay* must refuse to receive data from an I2C device if the device has an I2C address that is used by HDCP.

*DxgkDdiI2CReceiveDataFromDisplay* must never receive data from an I2C device on the display adapter. That is, this function can receive data from an I2C device in a monitor that is connected to the display adapter, but not from an I2C device that is on the display adapter itself.

*DxgkDdiI2CReceiveDataFromDisplay* should be made pageable.

## See also

[DxgkDdiI2CTransmitDataToDisplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_i2c_transmit_data_to_display)