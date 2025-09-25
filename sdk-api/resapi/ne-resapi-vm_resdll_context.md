# VM_RESDLL_CONTEXT enumeration

## Description

Contains actions for a virtual machine to perform.

## Constants

### `VmResdllContextTurnOff:0`

Turns off the virtual machine.

### `VmResdllContextSave:1`

Saves the virtual machine.

### `VmResdllContextShutdown:2`

Shuts down the virtual machine.

### `VmResdllContextShutdownForce:3`

Forces a shutdown of the virtual machine.

### `VmResdllContextLiveMigration:4`

Performs a live migration of the virtual machine.

## Remarks

The values in this enumeration can be used in a
[property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) as input for the
[MoveClusterGroupEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-moveclustergroupex) function's
*lpInBuffer* parameter to specify actions to take on a virtual machine. The resource type
name to use in the [CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))
structure is "Virtual Machine" or "Virtual Machine Configuration", and the
proper [CLUSTER_PROPERTY_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_format) enumeration value to
specify for the data format is **CLUSPROP_FORMAT_DWORD**.

## See also

[CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))

[CLUSTER_PROPERTY_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_format)

[MoveClusterGroupEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-moveclustergroupex)

[Property Lists](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists)