# CM_Get_Sibling_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_Sibling](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_sibling) instead.]

The **CM_Get_Sibling_Ex** function obtains a device instance handle to the next sibling node of a specified device node, in a local or a remote machine's [device tree](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-tree).

## Parameters

### `pdnDevInst` [out]

Caller-supplied pointer to the device instance handle to the sibling node that this function retrieves. The retrieved handle is bound to the machine handle specified by *hMachine*.

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

To enumerate all children of a device node in the local machine's device tree, first call [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex) to obtain a handle to the first child node, then call **CM_Get_Sibling_Ex** to obtain handles for the rest of the children.

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

[CM_Get_Sibling](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_sibling)