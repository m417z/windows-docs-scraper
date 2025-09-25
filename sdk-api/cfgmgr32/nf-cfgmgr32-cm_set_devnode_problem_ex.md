# CM_Set_DevNode_Problem_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Set_DevNode_Problem](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_set_devnode_problem) instead.]

The **CM_Set_DevNode_Problem_Ex** function sets a problem code for a device that is installed in a local or a remote machine.

## Parameters

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the machine handle supplied by *hMachine*.

### `ulProblem` [in]

Supplies a problem code, which is zero or one of the CM_PROB_Xxx flags that are described in [Device Manager Error Messages](https://learn.microsoft.com/windows-hardware/drivers/install/device-manager-error-messages). A value of zero indicates that a problem code is not set for the device.

### `ulFlags` [in]

Must be set to zero.

### `hMachine` [in, optional]

Caller-supplied machine handle to which the caller-supplied device instance handle is bound.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, the function returns one of the CR_-prefixed error codes that are defined in *Cfgmgr32.h*.

## Remarks

Use this function to set a problem code for a device that is installed in a local or a remote machine. You can also use the following functions to set a device's problem code and to obtain the problem code set for the device:

* [CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status) returns the problem code set for a device installed in a local machine.
* [CM_Get_DevNode_Status_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status_ex) returns the problem code set for a device installed in a local or a remote machine.
* [CM_Set_DevNode_Problem](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_set_devnode_problem) sets a problem code for a device installed in a local machine.

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

[CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status)

[CM_Get_DevNode_Status_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status_ex)

[CM_Set_DevNode_Problem](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_set_devnode_problem)