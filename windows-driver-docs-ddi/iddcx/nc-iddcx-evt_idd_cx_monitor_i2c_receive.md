# EVT_IDD_CX_MONITOR_I2C_RECEIVE callback function

## Description

**EVT_IDD_CX_MONITOR_I2C_RECEIVE** is called by the OS to return data received from an I2C device in a monitor.

## Parameters

### `MonitorObject` [in]

A handle used by the OS to identify the monitor to receive I2C data from.

### `pInArgs` [in]

Input arguments used by **EVT_IDD_CX_MONITOR_I2C_RECEIVE**.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

The **EVT_IDD_CX_MONITOR_I2C_RECEIVE** function is responsible for signaling the I2C start condition, sending the I2C address, receiving the data from the I2C device, sending acknowledgments, and signaling the stop condition. For details about the I2C bus, see the I2C Bus Specification, published by Philips Semiconductors. The specification defines a protocol for initiating I2C communication, reading and writing bytes over the I2C data line, and terminating I2C communication. (This resource may not be available in some languages and countries.)

**EVT_IDD_CX_MONITOR_I2C_RECEIVE** is required to receive data from an I2C device that has address 0x6F, but is permitted to refuse to receive data from any I2C device that has a different address.

**EVT_IDD_CX_MONITOR_I2C_RECEIVE** is permitted to block if another part of the display driver or graphics hardware is using the specified monitor's I2C bus. It is also permitted to block if the display driver is using the I2C bus to send or receive High-bandwidth Digital Content Protection (HDCP) data.

**EVT_IDD_CX_MONITOR_I2C_RECEIVE** has a 5 second timeout and must complete in that time limit.

If the display adapter supports HDCP, **EVT_IDD_CX_MONITOR_I2C_RECEIVE** must refuse to receive data from an I2C device if the device has an I2C address that is used by HDCP. This function can receive data from an I2C device in a monitor that is connected to the display adapter, but must never receive data from an I2C device that is on the display adapter itself.