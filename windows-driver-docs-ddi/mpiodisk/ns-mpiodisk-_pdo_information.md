# _PDO_INFORMATION structure

## Description

The PDO_INFORMATION structure represents a device-path pairing, which is an instance of a LUN through a particular path.

## Members

### `ScsiAddress`

A PDOSCSI_ADDR structure that represents the SCSI address of the LUN's instance that corresponds to a particular path.

### `DeviceState`

An unsigned 32-bitfield that represents whether the path, through which this instance of the LUN was exposed, is usable.

### `PathIdentifier`

An unsigned 64-bitfield that represents the identifier that is associated with the path through which this instance of the LUN is exposed.

### `IdentifierType`

An unsigned 32-bitfield that represents the identifier type of the LUN's controller.

### `IdentifierLength`

An unsigned 32-bitfield that represents the length of the identifier of the LUN's controller.

### `Identifier`

An unsigned 64-bitfield that represents the identifier that is associated with the path through which this instance of the LUN is exposed.

### `Pad`

Should be zero.