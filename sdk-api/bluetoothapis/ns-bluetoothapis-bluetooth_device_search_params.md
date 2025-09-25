# BLUETOOTH_DEVICE_SEARCH_PARAMS structure

## Description

The **BLUETOOTH_DEVICE_SEARCH_PARAMS** structure specifies search criteria for Bluetooth device searches.

## Members

### `dwSize`

The size, in bytes, of the structure.

### `fReturnAuthenticated`

A value that specifies that the search should return authenticated Bluetooth devices.

### `fReturnRemembered`

A value that specifies that the search should return remembered Bluetooth devices.

### `fReturnUnknown`

A value that specifies that the search should return unknown Bluetooth devices.

### `fReturnConnected`

A value that specifies that the search should return connected Bluetooth devices.

### `fIssueInquiry`

A value that specifies that a new inquiry should be issued.

### `cTimeoutMultiplier`

A value that indicates the time out for the inquiry, expressed in increments of 1.28 seconds. For example, an inquiry of 12.8 seconds has a **cTimeoutMultiplier** value of 10. The maximum value for this member is 48. When a value greater than 48 is used, the calling function immediately fails and returns **E_INVALIDARG**.

### `hRadio`

A handle for the radio on which to perform the inquiry. Set to **NULL** to perform the inquiry on all local Bluetooth radios.

## See also

[BluetoothDisplayDeviceProperties](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothdisplaydeviceproperties)

[BluetoothFindDeviceClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfinddeviceclose)

[BluetoothFindFirstDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstdevice)

[BluetoothFindNextDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextdevice)

[BluetoothGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetdeviceinfo)

[BluetoothRemoveDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothremovedevice)

[BluetoothUpdateDeviceRecord](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothupdatedevicerecord)