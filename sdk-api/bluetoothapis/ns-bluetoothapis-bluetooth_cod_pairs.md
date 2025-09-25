# BLUETOOTH_COD_PAIRS structure

## Description

The
**BLUETOOTH_COD_PAIRS** structure provides for specification and retrieval of Bluetooth Class Of Device (COD) information.

## Members

### `ulCODMask`

A mask to compare to determine the class of device. The major and minor codes of **ulCODMask** are used to compare the class of device found. If a major code is provided it must match the major code returned by the remote device, such that GET_COD_MAJOR(ulCODMask) is equal to GET_COD_MAJOR([class of device of the remote device]).

### `pcszDescription`

Descriptive string of the mask.

## Remarks

If a minor code is provided in **ulCODMask** it must also match the minor code returned by the remote device. A major code must be set if a minor code is specified; zero is not a valid major code.

See the Bluetooth specification at
[www.bluetooth.com](https://www.bluetooth.com/) for Class Of Device information.

## See also

[BLUETOOTH_SELECT_DEVICE_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_select_device_params)