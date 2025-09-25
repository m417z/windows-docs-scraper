# BLUETOOTH_DEVICE_INFO_STRUCT structure

## Description

The
**BLUETOOTH_DEVICE_INFO** structure provides information about a Bluetooth device.

## Members

### `dwSize`

Size of the
**BLUETOOTH_DEVICE_INFO** structure, in bytes.

### `Address`

Address of the device.

### `ulClassofDevice`

Class of the device.

### `fConnected`

Specifies whether the device is connected.

### `fRemembered`

Specifies whether the device is a remembered device. Not all remembered devices are authenticated.

### `fAuthenticated`

Specifies whether the device is authenticated, paired, or bonded. All authenticated devices are remembered.

### `stLastSeen`

Last time the device was seen, in the form of a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure.

### `stLastUsed`

Last time the device was used, in the form of a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure.

### `szName`

Name of the device.

## Remarks

See the [Bluetooth class-of-device (CoD) codes](https://www.bluetooth.com/specifications/assigned-numbers/baseband/) for more information.

## See also

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)