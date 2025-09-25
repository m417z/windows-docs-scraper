# _CONFIG_ROM structure

## Description

The CONFIG_ROM structure is used to contain the first 24 bytes of an IEEE 1394 device's configuration ROM.

## Members

### `CR_Info`

Specifies the first 4 bytes of the configuration ROM.

### `CR_Signiture`

Specifies a signature that will be the same for all 1394 devices.

### `CR_BusInfoBlockCaps`

Specifies the bus capabilities of the device.

### `CR_Node_UniqueID`

Specifies the node's 64-bit vendor-assigned unique ID.

### `CR_Root_Info`

Specifies the first 4 bytes of the root directory information.