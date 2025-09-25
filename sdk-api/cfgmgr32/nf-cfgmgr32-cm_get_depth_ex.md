# CM_Get_Depth_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_Depth](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_depth) instead.]

The **CM_Get_Depth_Ex** function is used to obtain the depth of a specified device node ([devnode](https://learn.microsoft.com/windows-hardware/drivers/)) within a local or a remote machine's [device tree](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-tree).

## Parameters

### `pulDepth` [out]

Caller-supplied address of a location to receive a depth value, where zero represents the device tree's root node, one represents the root node's children, and so on.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the machine handle supplied by *hMachine*.

### `ulFlags` [in]

Not used, must be zero.

### `hMachine` [in, optional]

Caller-supplied machine handle to which the caller-supplied device instance handle is bound.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

[CM_Get_Depth](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_depth)