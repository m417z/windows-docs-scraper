# CM_Locate_DevNode_ExA function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Locate_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_locate_devnodea) instead.]

The **CM_Locate_DevNode_Ex** function obtains a device instance handle to the device node that is associated with a specified [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids), on a local machine or a remote machine.

## Parameters

### `pdnDevInst` [out]

### `pDeviceID` [in, optional]

### `ulFlags` [in]

A variable of ULONG type that supplies one of the following flag values that apply if the caller supplies a device instance identifier:

#### CM_LOCATE_DEVNODE_NORMAL

The function retrieves the device instance handle for the specified device only if the device is currently configured in the device tree.

#### CM_LOCATE_DEVNODE_PHANTOM

The function retrieves a device instance handle for the specified device if the device is currently configured in the device tree or the device is a [nonpresent device](https://learn.microsoft.com/windows-hardware/drivers/) that is not currently configured in the device tree.

#### CM_LOCATE_DEVNODE_CANCELREMOVE

The function retrieves a device instance handle for the specified device if the device is currently configured in the device tree or in the process of being removed for the device tree. If the device is in the process of being removed, the function cancels the removal of the device.

#### CM_LOCATE_DEVNODE_NOVALIDATION

Not used.

### `hMachine` [in, optional]

A machine handle obtained from a call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinea), or a machine handle to which a device information set is bound. The machine handle for a device information set is obtained from the **RemoteMachineHandle** member of the [SP_DEVINFO_LIST_DETAIL_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_list_detail_data_a) structure for the device information set. Call [SetupDiGetDeviceInfoListDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistdetaila) to obtain an SP_DEVINFO_LIST_DETAIL_DATA structure.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, **CM_Locate_DevNode** returns CR_SUCCESS. Otherwise, the function returns one of the CR_-prefixed error codes that are defined in *Cfgmgr32.h*.

## Remarks

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)
[CM_Locate_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_locate_devnodea)