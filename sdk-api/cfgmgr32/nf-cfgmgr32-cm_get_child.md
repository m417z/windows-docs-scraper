# CM_Get_Child function

## Description

The **CM_Get_Child** function is used to retrieve a device instance handle to the first child node of a specified device node ([devnode](https://learn.microsoft.com/windows-hardware/drivers/)) in the local machine's [device tree](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-tree).

> [!NOTE]
> In Windows Vista and later versions of Windows, the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-) uses the [**DEVPKEY_Device_Children**](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-children) [property key](https://learn.microsoft.com/windows-hardware/drivers/install/property-keys) to represent device children. See [Retrieving Device Relations](https://learn.microsoft.com/windows-hardware/drivers/install/retrieving-device-relations) for details.

## Parameters

### `pdnDevInst` [out]

Caller-supplied pointer to the device instance handle to the child node that this function retrieves. The retrieved handle is bound to the local machine. See the **Remarks** section.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

To enumerate all children of a devnode in the local machine's device tree, first call **CM_Get_Child** to obtain a device instance handle to the first child node, then call [CM_Get_Sibling](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_sibling) to obtain handles for the rest of the children.

**Using Device Instance Handles**

Device instance handle that you use with [PnP configuration manager functions](https://learn.microsoft.com/windows/win32/api/cfgmgr32/) are bound to machine handles, as follows:

* All local device instance handles are bound to a NULL-valued local machine handle.
* If you use a remote machine handle to obtain a device instance handle, the resulting remote device instance handle is bound to the remote machine handle.
* A device instance handle can be used only with the machine handle to which it is bound.
* A device instance handle can be used with another device instance handle only if both device instance handles are bound to the same machine handle.

To obtain a device instance handle that is bound to the local machine, do one of the following.

* Use one of the following functions that retrieve only local device instance handles: [CM_Locate_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_locate_devnodea), **CM_Get_Child**, [CM_Get_Parent](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_parent), or [CM_Get_Sibling](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_sibling).
* Use one of the following functions, which retrieves local and remote device instance handles, to retrieve a local device instance handle: [CM_Locate_DevNode_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_locate_devnode_exw), [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex), [CM_Get_Parent_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_parent_ex), or [CM_Get_Sibling_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_sibling_ex).

You can also use the [device installation functions](https://learn.microsoft.com/windows-hardware/drivers/install/using-device-installation-functions#ddk-update-driver-function-dg) to obtain local device instance handles from a device information set that is bound to the local machine. Do the following steps:

1. Obtain a device information set that is bound to the local machine. (A device instance handle obtained from a device information set is bound to the machine handle to which the device information set is bound. You obtain the machine handle for a device information set from the **RemoteMachineHandle** member of its [SP_DEVINFO_LIST_DETAIL_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_list_detail_data_a) structure. For a local device information set that is bound to the local machine, the value of **RemoteMachineHandle** is **NULL**. Call [SetupDiGetDeviceInfoListDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistdetaila) to obtain an SP_DEVINFO_LIST_DETAIL_DATA structure.)
2. Obtain an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure for a device instance in the device information set.
3. Obtain the device instance handle for the device instance from the **DevInst** member of the SP_DEVINFO_DATA structure.

## See also

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

[CM_Get_Parent](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_parent)

[CM_Get_Parent_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_parent_ex)

[CM_Get_Sibling](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_sibling)

[CM_Get_Sibling_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_sibling_ex)

[CM_Locate_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_locate_devnodea)

[CM_Locate_DevNode_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_locate_devnode_exw)

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SP_DEVINFO_LIST_DETAIL_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_list_detail_data_a)

[SetupDiGetDeviceInfoListDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistdetaila)