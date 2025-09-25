# _DSM_Load_Balance_Policy_V2 structure

## Description

The DSM_Load_Balance_Policy_V2 structure is used to represent a load balance policy that is applied to a LUN. It is similar to the DSM_Load_Balance_Policy structure, except that it uses the MPIO_DSM_Path_V2 structure to capture and expose path information.

## Members

### `Version`

The version of WMI class supported. Set to 2.

### `LoadBalancePolicy`

An unsigned 32-bitfield that represents the load balance policy type that is currently being applied to the LUN if the LUN is being queried, or the new policy to apply to the LUN if the LUN is being set.

### `DSMPathCount`

An unsigned 32-bitfield that represents the number of paths that expose the LUN's instances.

### `Reserved`

Should be zero.

### `DSM_Paths`

An array of MPIO_DSM_Path_V2 structures that represent path attributes for each of the LUN's instances.