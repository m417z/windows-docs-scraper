# BTH_HCI_EVENT_INFO structure

## Description

The **BTH_HCI_EVENT_INFO** structure is used in connection with obtaining WM_DEVICECHANGE messages for Bluetooth.

## Members

### `bthAddress`

Address of the remote device, in the form of a [BTH_ADDR](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices) structure.

### `connectionType`

Type of connection. Valid values are **HCI_CONNECTION_TYPE_ACL** or **HCI_CONNECTION_TYPE_SCO**.

### `connected`

Status of the connection. If nonzero, the connection has been established. If zero, the connection has been terminated.

## See also

[BTH_ADDR](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices)

[Bluetooth and WM_DEVICECHANGE
Messages](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenablediscovery)