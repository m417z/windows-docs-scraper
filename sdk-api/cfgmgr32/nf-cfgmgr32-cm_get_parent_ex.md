# CM_Get_Parent_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_Parent](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_parent) instead.]

The **CM_Get_Parent_Ex** function obtains a device instance handle to the parent node of a specified device node ([devnode](https://learn.microsoft.com/windows-hardware/drivers/)) in a local or a remote machine's [device tree](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-tree).

## Parameters

### `pdnDevInst` [out]

Caller-supplied pointer to the device instance handle to the parent node that this function retrieves. The retrieved handle is bound to the machine handle specified by *hMachine*.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the machine handle specified by *hMachine*.

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

[CM_Get_Parent](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_parent)