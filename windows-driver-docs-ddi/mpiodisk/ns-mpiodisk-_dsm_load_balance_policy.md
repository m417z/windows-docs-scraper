# _DSM_Load_Balance_Policy structure

## Description

The DSM_Load_Balance_Policy structure is used to represent a load balance policy that is applied to a LUN.

## Members

### `Version`

The version of WMI class supported. Set to 1.

### `LoadBalancePolicy`

An unsigned 32-bitfield that represents the load balance policy type that is currently being applied to the LUN if the LUN is queried, or the new policy to apply to the LUN if the LUN is being set.

### `DSMPathCount`

An unsigned 32-bitfield that represents the number of paths that expose the LUN's instances.

### `Reserved`

Should be zero.

### `DSM_Paths`

An array of MPIO_DSM_Path structures that represent path attributes for each of the LUN's instances.