# _IRB_REQ_GET_CONFIG_ROM structure

## Description

This structure contains the fields necessary for the bus driver to carry out a GetConfigRom request.

## Members

### `GenerationCount`

Receives the generation of the bus for which the contents of this configuration ROM was retrieved.

### `ConfigRom`

Receives a pointer to a **ConfigRom** object.

### `UnitDirectoryIndex`

Receives the index to the node's unit directory in its configuration ROM. This is an index to the **Entries** array in the **u.GetConfigRom.ConfigRom** structure.

### `UnitDependentDirectoryIndex`

Receives the index to the node's unit dependent directory in its configuration ROM. This is an index to the **Entries** array in the **u.GetConfigRom.ConfigRom** structure.

### `VendorLeafIndex`

Receives the index to the node's vendor textual leaf in the configuration ROM. This is an index to the **Entries** array in the **u.GetConfigRom.ConfigRom** structure.

### `ModelLeafIndex`

Receives the index to the node's model textual leaf in the configuration ROM. This is an index to the **Entries** array in the **u.GetConfigRom.ConfigRom** structure.