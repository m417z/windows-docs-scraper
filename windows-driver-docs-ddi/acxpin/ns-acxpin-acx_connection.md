## Description

The **ACX_CONNECTION** structure is used to define a connection between two pins.

## Members

### `Size`

The size of this **ACX_CONNECTION** structure for verification purposes.

### `Flags`

A combination of [ACX_CONNECTION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_connection_flags) values that indicate how to identify the pins of the *FromObject* and *ToObject*.

### `FromObject`

An **ACXOBJECT** representing the source.

### `FromPin`

The pin associated with the *FromObject*.

### `FromPin.Object`

An **ACXPIN** object used to identify the *FromPin* object.

### `FromPin.Id`

The ID used to identify the *FromPin* object.

### `ToObject`

An **ACXOBJECT** representing the sink.

### `ToPin`

### `ToPin.Object`

An **ACXPIN** object used to identify the *ToPin* object.

### `ToPin.Id`

The ID used to identify the *ToPin* object.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)