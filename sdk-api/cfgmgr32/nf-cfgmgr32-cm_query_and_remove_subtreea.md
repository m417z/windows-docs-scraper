# CM_Query_And_Remove_SubTreeA function

## Description

The **CM_Query_And_Remove_SubTree** function checks whether a device instance and its children can be removed and, if so, it removes them.

## Parameters

### `dnAncestor` [in]

Caller-supplied device instance handle to the device at the root of the subtree to be removed. This device instance handle is bound to the local machine.

### `pVetoType` [out, optional]

(*Optional*) If the caller does not pass **NULL** and the removal request is vetoed (that is, the function returns CR_REMOVE_VETOED), on return this points to a [PNP_VETO_TYPE](https://learn.microsoft.com/windows/desktop/api/cfg/ne-cfg-pnp_veto_type)-typed value that indicates the reason for the veto.

### `pszVetoName` [out, optional]

(*Optional*) If the caller does not pass **NULL** and the removal request is vetoed (that is, the function returns CR_REMOVE_VETOED), on return this points to a text string that is associated with the veto type. The type of information this string provides is dependent on the value received by *pVetoType*. For information about these strings, see [PNP_VETO_TYPE](https://learn.microsoft.com/windows/desktop/api/cfg/ne-cfg-pnp_veto_type).

### `ulNameLength` [in]

Caller-supplied value representing the length (number of characters) of the string buffer supplied by *pszVetoName*. This should be set to MAX_PATH.

### `ulFlags` [in]

A bitwise OR of the caller-supplied flag constants that are described in the **Remarks** section.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the other CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

The purpose of the **CM_Query_And_Remove_SubTree** function is to allow an application to prepare a device for safe removal from the local machine. Use this function to remove devices only if a driver has not set the **SurpriseRemovalOK** member of [DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-_device_capabilities). If a driver has set **SurpriseRemovalOK**, the application should call [CM_Request_Device_Eject](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_device_ejecta) instead of **CM_Query_And_Remove_SubTree**.

**CM_Query_And_Remove_SubTree** supports setting the flags parameter *ulFlags* with one of the following two flags; these flags apply only if Windows or an installer vetoes the removal of a device:

| Flag | Description |
|------|-------------|
| CM_REMOVE_UI_OK | The function allows a user dialog box to be displayed to indicate the reason for the veto. This is the default flag setting. |
| CM_REMOVE_UI_NOT_OK | The function suppresses the display of a user dialog box that indicates the reason for the veto. |

Beginning with Windows XP, **CM_Query_And_Remove_SubTree** also supports setting the following additional flag; this flag applies only if the function successfully removes the device instance:

| Flag | Description |
|------|-------------|
| CM_REMOVE_NO_RESTART | If this flag is set, the function configures the device status such that the device cannot be restarted until after the device status is reset. |

The device status is reset by the one of the following:
- Calling [CM_Setup_DevNode](https://learn.microsoft.com/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_setup_devnode) for the device and specifying CM_SETUP_DEVNODE_RESET. After the device status is reset in this manner, the device can be restarted by calling [CM_Reenumerate_DevNode](https://learn.microsoft.com/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_reenumerate_devnode) for the device instance. After resetting the device status, any other operation that enumerates the device will also restart the device, for example, if the Device Manager is used to reenumerate devices.
- The device is detached and reattached, or the computer is restarted. In this case, the device status will be reset and the device will be restarted.
- If this flag is not set, the device status does not have to be reset. You can restart the removed device by a calling **CM_Setup_DevNode** for the device and by specifying CM_SETUP_DEVNODE_READY. Any other operation that reenumerates the device will also restart the device. An example of an operation that reenumerates a device is calling **CM_Reenumerate_DevNode** for the device, detaching and reattaching the device, or restarting the computer. |

Windows applications that do not require the low-level operation **CM_Query_And_Remove_SubTree** should use the [DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange) request to disable a device instead of using **CM_Query_And_Remove_SubTree** to remove a device. The DIF_PROPERTYCHANGE request can be used to enable, disable, restart, stop, or change the properties of a device.

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)
[CM_Query_And_Remove_SubTree_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtree_exa)
[CM_Reenumerate_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_reenumerate_devnode)
[CM_Request_Device_Eject](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_device_ejecta)
[CM_Setup_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_setup_devnode)
[DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange)