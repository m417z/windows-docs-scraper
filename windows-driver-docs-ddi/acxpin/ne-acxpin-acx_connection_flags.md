## Description

The **ACX_CONNECTION_FLAGS** enumeration is used by the [ACX_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_connection) structure to specify the ACX object identifier types.

## Constants

### `AcxConnectionNoFlags`

Indicates that there are no flags set.

### `AcxConnectionFromPinId`

Indicates that the connection is *from* a pin ID.

### `AcxConnectionFromPinObject`

Indicates that the connection is *from* an object.

### `AcxConnectionToPinId`

Indicates that the connection is *to* a pin ID.

### `AcxConnectionToPinObject`

Indicates that the connection is *to* a pin object.

### `AcxConnectionValidFlags`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)