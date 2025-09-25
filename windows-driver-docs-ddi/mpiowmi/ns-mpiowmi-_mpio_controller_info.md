# _MPIO_CONTROLLER_INFO structure

## Description

The MPIO_CONTROLLER_INFO structure represents a storage controller.

## Members

### `IdentifierType`

An unsigned 32-bitfield that represents the identifier type for the controller.

### `IdentifierLength`

An unsigned 32-bitfield that represents the length of the controller's identifier.

### `Identifier`

A 32-byte array that contains the actual identifier (serial number) of the controller.

### `ControllerState`

An unsigned 32-bitfield that represents the controller state.

### `Pad`

Should be zero.

### `AssociatedDsm`

A string field of maximum length 63 characters. This string field returns the friendly name of the DSM that controls the devices that are exposed by this controller.