# CM_Setup_DevNode function

## Description

The **CM_Setup_DevNode** function restarts a device instance that is not running because there is a problem with the device configuration.

## Parameters

### `dnDevInst` [in]

A device instance handle that is bound to the local system.

### `ulFlags` [in]

One of the following flag values:

#### CM_SETUP_DEVNODE_READY

Restarts a device instance that is not running because of a problem with the device configuration.

#### CM_SETUP_DEVNODE_RESET (Windows XP and later versions of Windows)

Resets a device instance that has the no restart device status flag set. The no restart device status flag is set if a device is removed by calling **CM_Query_And_Remove_SubTree** or **CM_Query_And_Remove_SubTree_Ex** and specifying the CM_REMOVE_NO_RESTART flag.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise it returns one of the error codes with "CR_" prefix that are defined in *Cfgmgr32.h*.

## Remarks

[Device installation applications](https://learn.microsoft.com/windows-hardware/drivers/) should use the [DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange) request to restart a device instead of using this function. The DIF_PROPERTYCHANGE request can be used to enable, disable, restart, stop, or change the properties of a device.

If a device instance does not have a problem and is already started, **CM_Setup_DevNode** returns without changing the status of the device instance.

Call [CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status) or [CM_Get_DevNode_Status_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status_ex) to determine the status and problem code for a device instance.

## See also

[CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status)

[CM_Get_DevNode_Status_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status_ex)

[CM_Query_And_Remove_SubTree](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtreew)

[CM_Query_And_Remove_SubTree_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtree_exw)

[DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange)