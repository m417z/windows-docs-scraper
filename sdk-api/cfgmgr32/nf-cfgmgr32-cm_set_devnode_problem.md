# CM_Set_DevNode_Problem function

## Description

The **CM_Set_DevNode_Problem** function sets a problem code for a device that is installed in a local machine.

## Parameters

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `ulProblem` [in]

Supplies a problem code, which is zero or one of the CM_PROB_Xxx flags that are described in [Device Manager Error Messages](https://learn.microsoft.com/windows-hardware/drivers/install/device-manager-error-messages). A value of zero indicates that a problem is not set for the device.

### `ulFlags` [in]

Must be set to zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, the function returns one of the CR_-prefixed error codes that are defined in *Cfgmgr32.h*.

## Remarks

Use this function to set a problem code for a device that is installed in a local machine. You can also use the following functions to set a device's problem code and to obtain the problem code set for the device:

* [CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status) returns the problem code set for a device installed in a local machine.
* [CM_Get_DevNode_Status_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status_ex) returns the problem code set for a device installed in a local or a remote machine.
* [CM_Set_DevNode_Problem_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_set_devnode_problem_ex) sets a problem code for a device installed in a local or a remote machine.

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status)

[CM_Get_DevNode_Status_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status_ex)

[CM_Set_DevNode_Problem_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_set_devnode_problem_ex)