# _MPIO_DSM_Path_V2 structure

## Description

The MPIO_DSM_Path_V2 structure is used to represent the DSM's definition of a path. It is a superset of the previously existing MPIO_DSM_Path class.

## Members

### `DsmPathId`

An unsigned 64-bitfield that is used as a unique identifier to distinguish paths known to the DSM.

### `Reserved`

Should be zero.

### `PathWeight`

An unsigned 32-bitfield that holds the weight associated with the given path.

### `PrimaryPath`

An unsigned 32-bitfield that is used as a flag to indicate the path state when accessing a particular LUN.

### `OptimizedPath`

An unsigned 32-bitfield that is used in conjunction with *PrimaryPath* to indicate the path state for accessing a LUN.

### `PreferredPath`

An unsigned 32-bitfield that is used as a flag to indicate whether this is the preferred path for accessing the LUN.

### `FailedPath`

A 32-bit unsigned field that is used as a flag to indicate if the path has failed.

### `TargetPortGroup_State`

An unsigned 32-bitfield that is used to indicate the access state of the target port group to which this instance of the LUN belongs.

### `ALUASupport`

An unsigned 32-bitfield that returns the Asymmetrical Logical Unit Access (ALUA) state transition support that is indicated by the LUN.

### `SymmetricLUA`

An unsigned 8-bitfield that is used as a flag to indicate to the application if logical unit access is symmetric.

### `TargetPortGroup_Preferred`

An unsigned 8-bitfield that is used as a flag. This field indicates if the LUN's target port group that corresponds to this path is preferred for the LUN access.

### `TargetPortGroup_Identifier`

An unsigned 16-bitfield that contains the identifier of the LUN's target port group that corresponds to this path.

### `TargetPort_Identifier`

An unsigned 32-bitfield that contains the identifier of the target port that corresponds to this path through which the LUN has been exposed.

### `Reserved32`

Should be zero.

### `Reserved64`

Should be zero.