# BluetoothIsVersionAvailable function

## Description

The **BluetoothIsVersionAvailable** function indicates if the installed Bluetooth binary set supports the requested version.

## Parameters

### `MajorVersion` [in]

The major version number.

### `MinorVersion` [in]

The minor version number.

## Return value

**TRUE** if the installed bluetooth binaries support the specified *MajorVersion* and *MinorVersion*; otherwise, **FALSE**.

## Remarks

This functionality is only exported in Bluetooth for Windows version 2.1 and later.