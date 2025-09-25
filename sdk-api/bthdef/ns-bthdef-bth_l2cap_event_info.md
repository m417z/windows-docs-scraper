# BTH_L2CAP_EVENT_INFO structure

## Description

The **BTH_L2CAP_EVENT_INFO** structure contains data about events associated with an L2CAP channel.

## Members

### `bthAddress`

Remote radio address with which the L2CAP event is associated, in the form of a [BTH_ADDR](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices) structure.

### `psm`

Channel number established or terminated.

### `connected`

Status of the connection. If nonzero, the channel has been established. If zero, the channel has been terminated.

### `initiated`

Provides connection information. If nonzero, the local radio initiated the L2CAP connection. If zero, the remote Bluetooth device initiated the L2CAP connection. If **connected** is zero, this member is undefined and not applicable.

## Remarks

Notifications for a destroyed channel are only to be sent for channels that have been successfully established.

## See also

[BTH_ADDR](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatemultipledevices)

[Bluetooth and WM_DEVICECHANGE
Messages](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothenablediscovery)