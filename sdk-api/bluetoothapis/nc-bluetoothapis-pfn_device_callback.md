# PFN_DEVICE_CALLBACK callback function

## Description

The **PFN_DEVICE_CALLBACK** function is a callback prototype used in association with selecting Bluetooth devices. The
**PFN_DEVICE_CALLBACK** function can be set to **NULL** if no specialized filtering is required.

## Parameters

### `pvParam`

A parameter passed in from the **pvParam** member of the
[BLUETOOTH_SELECT_DEVICE_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_select_device_params) structure through the [BluetoothSelectDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothselectdevices) function.

### `pDevice`

Remote Bluetooth address queried; this is the address inserted into the user-presented list of Bluetooth devices.

## Return value

Returning **FALSE** prevents the device from being added to the list view of Bluetooth devices.

## Remarks

The
[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure pointed to in *pDevice* is the device that the
[BluetoothSelectDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothselectdevices) function is querying to determine if that device should be added to the list view.

If the callback performs SDP queries for each device, the list of devices from which the user can choose will be delayed until all devices can be queried. A recommended approach is to use the service to call bitfield in the class of device, available through **GET_COD_SERVICE**, to determine whether the device should be displayed to the user. The service class bitfield is available in the **pDevice** parameter through the **ulClassOfDevice** member.

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BLUETOOTH_SELECT_DEVICE_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_select_device_params)

[BluetoothSelectDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothselectdevices)