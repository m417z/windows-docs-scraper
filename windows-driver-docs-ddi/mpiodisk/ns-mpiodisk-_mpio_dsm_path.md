# _MPIO_DSM_Path structure

## Description

The MPIO_DSM_Path structure is used to represent the DSM's definition of a path.

## Members

### `DsmPathId`

An unsigned 64-bitfield that is used as a unique identifier to distinguish paths that are known to the DSM.

### `Reserved`

Should be zero.

### `PathWeight`

An unsigned 32-bitfield that holds the weight associated with the given path. The assigned value determines the order in which the DSM will pick the paths if the load balance policy is set to Weighted Path. This means that a user can assign weights to each path that is available for a device and if the Load Balance Policy for the device is set as "Weighted Path," MPIO uses this PathWeight value to determine which path to use.

### `PrimaryPath`

An unsigned 32-bitfield that is used as a flag to indicate the path state when accessing a particular LUN.