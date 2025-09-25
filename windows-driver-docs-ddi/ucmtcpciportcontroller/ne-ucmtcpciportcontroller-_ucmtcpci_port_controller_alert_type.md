# _UCMTCPCI_PORT_CONTROLLER_ALERT_TYPE enumeration

## Description

Defines generic alert values that are used to indicate the type of hardware alert received on the port controller.

## Constants

### `UcmTcpciPortControllerAlertInvalid`

The alert is invalid.

### `UcmTcpciPortControllerAlertCCStatus`

Indicates a
CC status change alert.

### `UcmTcpciPortControllerAlertPowerStatus`

Indicates a
power status change alert.

### `UcmTcpciPortControllerAlertReceiveSOPMessageStatus`

Indicates an SOP message alert.

### `UcmTcpciPortControllerAlertReceivedHardReset`

Indicates a hard Reset alert.

### `UcmTcpciPortControllerAlertTransmitSOPMessageFailed`

Indicates that the SOP message transmission was not successful.

### `UcmTcpciPortControllerAlertTransmitSOPMessageDiscarded`

Indicates that the
SOP message transmission was not sent due to an incoming receive message.

### `UcmTcpciPortControllerAlertTransmitSOPMessageSuccessful`

Indicates that the SOP message transmission was successful.

### `UcmTcpciPortControllerAlertVbusVoltageAlarmHi`

Indicates a high-voltage alarm.

### `UcmTcpciPortControllerAlertVbusVoltageAlarmLo`

Indicates a low-voltage alarm.

### `UcmTcpciPortControllerAlertFault`

Indicates that a Fault has occurred.

### `UcmTcpciPortControllerAlertRxBufferOverflow`

Indicates that the
TCPC Rx buffer has overflowed.

### `UcmTcpciPortControllerAlertVbusSinkDisconnectDetected`

Indicates that a VBUS Sink Disconnect Threshold crossing has been detected

## See also

[UCMTCPCI_PORT_CONTROLLER_ALERT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_alert_data)