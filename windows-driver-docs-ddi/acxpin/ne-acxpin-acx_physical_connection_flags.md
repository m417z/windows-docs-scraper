## Description

The **ACX_PHYSICAL_CONNECTION_FLAGS** enumeration is used by the [ACX_PHYSICAL_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_physical_connection) structure to initialize a physical connection.

## Constants

### `AcxPhysicalConnectionNoFlags`

Indicates that no flags are set.

### `AcxPhysicalConnectionFromPinId`

Indicates that the physical connection is from a PIN whose ID is specified.

### `AcxPhysicalConnectionFromPinObject`

Indicates that the physical connection is from a PIN which is represented by the specified PIN object.

### `AcxPhysicalConnectionValidFlags`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_PHYSICAL_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_physical_connection)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)