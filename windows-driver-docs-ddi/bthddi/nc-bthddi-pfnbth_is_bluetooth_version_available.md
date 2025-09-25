# PFNBTH_IS_BLUETOOTH_VERSION_AVAILABLE callback function

## Description

The
*IsBluetoothVersionAvailable* function checks whether a given Bluetooth version is supported by the
operating system.

## Parameters

### `MajorVersion` [in]

This parameter specifies the major version number of Bluetooth that is requested.

### `MinorVersion` [in]

This parameter specifies the minor version number of Bluetooth that is requested.

## Return value

*IsBluetoothVersionAvailable* returns **TRUE** if the Bluetooth version that the operating system
provides is greater than or equal to the Bluetooth version number that is being requested.

## Remarks

Bluetooth profile drivers should call this function before performing any operations that are not
supported in all Bluetooth versions.