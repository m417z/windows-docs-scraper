# BluetoothSelectDevicesFree function

## Description

The
**BluetoothSelectDevicesFree** function frees resources associated with a previous call to
[BluetoothSelectDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothselectdevices).

## Parameters

### `pbtsdp`

A pointer to a
[BLUETOOTH_SELECT_DEVICE_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_select_device_params) structure that identifies the Bluetooth device resources to free.

## Return value

Returns **TRUE** upon success. Returns **FALSE** if there are no resources to free.

## Remarks

Only call the **BluetoothSelectDevicesFree** function if a previous call to the [BluetoothSelectDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothselectdevices) function returned **TRUE**.

## See also

[BLUETOOTH_SELECT_DEVICE_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_select_device_params)

[BluetoothSelectDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothselectdevices)