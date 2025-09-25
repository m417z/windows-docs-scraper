# CM_Query_And_Remove_SubTree_ExW function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Query_And_Remove_SubTree](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtreew) instead.]

The **CM_Query_And_Remove_SubTree_Ex** function checks whether a device instance and its children can be removed and, if so, it removes them.

## Parameters

### `dnAncestor` [in]

Caller-supplied device instance handle to the device at the root of the subtree to be removed. This device instance handle is bound to the machine handle supplied by *hMachine*.

### `pVetoType` [out, optional]

(*Optional*) If the caller does not pass **NULL** and the removal request is vetoed (that is, the function returns CR_REMOVE_VETOED), on return this points to a [PNP_VETO_TYPE](https://learn.microsoft.com/windows/desktop/api/cfg/ne-cfg-pnp_veto_type)-typed value that indicates the reason for the veto.

### `pszVetoName` [out, optional]

(*Optional*) If the caller does not pass **NULL** and the removal request is vetoed (that is, the function returns CR_REMOVE_VETOED), on return this points to a text string that is associated with the veto type. The type of information this string provides is dependent on the value received by *pVetoType*. For information about these strings, see [PNP_VETO_TYPE](https://learn.microsoft.com/windows/desktop/api/cfg/ne-cfg-pnp_veto_type).

### `ulNameLength` [in]

(*Optional*.) Caller-supplied value representing the length (number of characters) of the string buffer supplied by *pszVetoName*. This should be set to MAX_PATH.

### `ulFlags` [in]

A bitwise OR of the caller-supplied flag constants that are described in the **Remarks** section.

### `hMachine` [in, optional]

Caller-supplied machine handle to which the caller-supplied device instance handle is bound.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

The purpose of the **CM_Query_And_Remove_SubTree_Ex** function is to allow an application to prepare a device for safe removal from a remote machine. Use this function to remove devices only if a driver has not set the **SurpriseRemovalOK** member of [DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-_device_capabilities). If a driver has set **SurpriseRemovalOK**, the application should call [CM_Request_Device_Eject_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_device_eject_exw) instead of **CM_Query_And_Remove_SubTree_Ex**.

**CM_Query_And_Remove_SubTree_Ex** supports setting the flags parameter *ulFlags* with one of the following two flags; these flags apply only if Windows or an installer vetoes the removal of a device:

Beginning with Windows XP, **CM_Query_And_Remove_SubTree_Ex** also supports setting the following additional flag; this flag applies only if the function successfully removes the device instance:

[Device installation applications](https://learn.microsoft.com/windows-hardware/drivers/) that do not require the low-level operation of **CM_Query_And_Remove_SubTree_Ex** should use the [DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange) request to disable a device instead of using **CM_Query_And_Remove_SubTree_Ex** to remove a device. The DIF_PROPERTYCHANGE request can be used to enable, disable, restart, stop, or change the properties of a device.

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

[CM_Query_And_Remove_SubTree](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtreew)

[CM_Reenumerate_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_reenumerate_devnode)

[CM_Request_Device_Eject_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_device_eject_exw)

[CM_Setup_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_setup_devnode)

[DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange)