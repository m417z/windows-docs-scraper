# _PosDeviceInformation structure

## Description

This structure provides device information as defined in and required by the Unified Point of Service (UPOS) standard.

## Members

### `UnifiedPOSVersion`

Indicates the version of the UPOS specification supported.

### `DeviceCategory`

Indicates the device category (for example, POSPrinter or CashDrawer).

### `ManufacturerName`

Indicates the name of the device manufacturer.

### `ModelName`

Indicates the model name of the device.

### `SerialNumber`

Indicates the serial number of the device.

### `ManufactureDate`

Indicates the date the device was manufactured.

### `MechanicalRevision`

Indicates the device hardware revision.

### `FirmwareRevision`

Indicates the device firmware revision.

### `Interface`

Indicates the device hardware interface (for example, serial or USB).

### `InstallationDate`

Indicates the device installation date.

## Remarks

These strings must be NULL terminated, and the maximum length of the strings is `STATISTICS_STRING_SIZE - 1`.