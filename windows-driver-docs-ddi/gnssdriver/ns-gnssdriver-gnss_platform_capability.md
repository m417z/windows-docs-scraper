## Description

The **GNSS_PLATFORM_CAPABILITY** structure is used to communicate the platform/HLOS capabilities to the underlying GNSS driver.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `SupportAgnssInjection`

Indicates that the platform supports AGNSS injection via the location platform.

### `AgnssFormatSupported`

Specifies a bitmask containing the different AGNSS formats (GNSS_AGNSSFORMAT_*) that the GNSS driver or device supports.

### `Unused`

Padding buffer reserved for future use.

## Remarks

 This is a list of individual capability support of the GNSS adapter. The platform capability is represented in the same way as the device capabilities are represented.