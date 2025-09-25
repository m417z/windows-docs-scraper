# CM_Get_Depth function

## Description

The **CM_Get_Depth** function is used to obtain the depth of a specified device node ([devnode](https://learn.microsoft.com/windows-hardware/drivers/)) within the local machine's [device tree](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-tree).

## Parameters

### `pulDepth` [out]

Caller-supplied address of a location to receive a depth value, where zero represents the device tree's root node, one represents the root node's children, and so on.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_Depth_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_depth_ex)