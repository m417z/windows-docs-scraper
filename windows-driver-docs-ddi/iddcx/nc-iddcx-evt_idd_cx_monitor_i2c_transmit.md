# EVT_IDD_CX_MONITOR_I2C_TRANSMIT callback function

## Description

**EVT_IDD_CX_MONITOR_I2C_TRANSMIT** is called by the OS to return data received to an I2C device in a monitor.

## Parameters

### `MonitorObject` [in]

A handle used by the OS to identify the monitor to return I2C data to.

### `pInArgs` [in]

Input arguments used by **EVT_IDD_CX_MONITOR_I2C_TRANSMIT**.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

**EVT_IDD_CX_MONITOR_I2C_TRANSMIT** is responsible for signaling the I2C start condition, sending the I2C address, sending the data in the buffer, checking for acknowledgments from the receiver, and signaling the stop condition. For details about the I2C bus, see the I2C Bus Specification, published by Philips Semiconductors. The specification defines a protocol for initiating I2C communication, reading and writing bytes over the I2C data line, and terminating I2C
communication.

**EVT_IDD_CX_MONITOR_I2C_TRANSMIT** is required to transmit data to an I2C device that has address 0x6E but is permitted to refuse to transmit data to any I2C device that has a different address.

**EVT_IDD_CX_MONITOR_I2C_TRANSMIT** is permitted to block if another part of the display driver or graphics hardware is using the specified monitor's I2C bus. It is also permitted to block if the display driver is using the I2C bus to send or receive High-bandwidth Digital Content Protection (HDCP) data.
**EVT_IDD_CX_MONITOR_I2C_TRANSMIT** has a 5 second timeout and must complete in that time limit.

If the display adapter supports HDCP, **EVT_IDD_CX_MONITOR_I2C_TRANSMIT** must refuse to send data to an I2C device if the device has an I2C address that is used by HDCP.
**EVT_IDD_CX_MONITOR_I2C_TRANSMIT** must never transmit data to an I2C device on the display adapter. That is, this function can transmit data to an I2C device in a monitor that is connected to the display adapter, but not to an I2C device that is on the display adapter itself.