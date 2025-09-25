## Description

The **ACX_PHYSICAL_CONNECTION** structure describes a physical audio connection between two ACXCIRCUIT objects.

## Members

### `Size`

The size of all of the data in the **ACX_PHYSICAL_CONNECTION** structure in bytes.

### `Flags`

A value from the [ACX_PHYSICAL_CONNECTION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_physical_connection_flags) enum that specifies the type of physical connection.

### `FromPin`

A union that identifies the from pin of the physical connection.

### `FromPin.Object`

An **ACXPIN** object used to identify the *FromPin*.

### `FromPin.Id`

The ID used to identify the *FromPin*.

### `TargetName`

A string containing the name of the target pin.

### `TargetPinId`

The ID of the target pin.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_PHYSICAL_CONNECTION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_physical_connection_flags)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)