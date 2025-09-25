# DXGKDDI_I2C_TRANSMIT_DATA_TO_DISPLAY callback function

## Description

The **DXGKDDI_I2C_TRANSMIT_DATA_TO_DISPLAY** callback function transmits data to an I2C device in a monitor.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem.

### `VidPnTargetId` [in]

An integer that identifies one of the video present targets on the display adapter.

### `SevenBitI2CAddress` [in]

The address of the I2C device to which data will be transmitted.

### `DataLength` [in]

The length, in bytes, of the data to be transmitted. This parameter must be between 1 and 64, inclusive.

### `Data` [in]

A pointer to a buffer that holds the data to be transmitted.

## Return value

**DXGKDDI_I2C_TRANSMIT_DATA_TO_DISPLAY** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*. The following list gives some of the possible error codes that can be returned.

|Return code|Description|
|--- |--- |
|STATUS_GRAPHICS_MONITOR_NOT_CONNECTED|There is no monitor connected to the video output identified by VidPnTargetId.|
|STATUS_GRAPHICS_I2C_NOT_SUPPORTED|The video output identified by VidPnTargetId does not have an I2C bus.|
|STATUS_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST|No device acknowledged the I2C address supplied in SevenBitI2CAddress. This could mean that no device on the I2C bus has the specified address or that an error occurred when the address was transmitted.|
|STATUS_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA|The I2C address was successfully transmitted, but there was an error transmitting data to the I2C device.|

## Remarks

The video present target identified by **VidPnTargetId** is associated with one of the video outputs on the display adapter. The data is transmitted to an I2C device in the monitor that is connected to that video output.

**DxgkDdiI2CTransmitDataToDisplay** is responsible for signaling the I2C start condition, sending the I2C address, sending the data in the buffer, checking for acknowledgments from the receiver, and signaling the stop condition. For details about the I2C bus, see the *I2C Bus Specification*, published by Philips Semiconductors. The specification defines a protocol for initiating I2C communication, reading and writing bytes over the I2C data line, and terminating I2C communication.

**DxgkDdiI2CTransmitDataToDisplay** is required to transmit data to an I2C device that has address 0x6E but is permitted to refuse to transmit data to any I2C device that has a different address.

**DxgkDdiI2CTransmitDataToDisplay** is permitted to block if another part of the display miniport driver or graphics hardware is using the specified monitor's I2C bus. It is also permitted to block if the display miniport driver is using the I2C bus to send or receive High-bandwidth Digital Content Protection (HDCP) data.

If the display adapter supports HDCP, the **DxgkDdiI2CTransmitDataToDisplay** function must refuse to send data to an I2C device if the device has an I2C address that is used by HDCP.

**DxgkDdiI2CTransmitDataToDisplay** must never transmit data to an I2C device on the display adapter. That is, this function can transmit data to an I2C device in a monitor that is connected to the display adapter, but not to an I2C device that is on the display adapter itself.

**DxgkDdiI2CTransmitDataToDisplay** should be made pageable.

## See also

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiI2CReceiveDataFromDisplay**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_i2c_receive_data_from_display)