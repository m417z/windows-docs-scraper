# CM_Request_Device_Eject_ExW function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Request_Device_Eject](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_device_ejectw) instead.]

The **CM_Request_Device_Eject_Ex** function prepares a local or a remote device instance for safe removal, if the device is removable. If the device can be physically ejected, it will be.

## Parameters

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the machine handle supplied by *hMachine*.

### `pVetoType` [out, optional]

(*Optional*.) If not **NULL**, this points to a location that, if the removal request fails, receives a [PNP_VETO_TYPE](https://learn.microsoft.com/windows/desktop/api/cfg/ne-cfg-pnp_veto_type)-typed value indicating the reason for the failure.

### `pszVetoName` [out, optional]

(*Optional*.) If not **NULL**, this is a caller-supplied pointer to a string buffer that receives a text string. The type of information this string provides is dependent on the value received by *pVetoType*. For information about these strings, see [PNP_VETO_TYPE](https://learn.microsoft.com/windows/desktop/api/cfg/ne-cfg-pnp_veto_type).

### `ulNameLength` [in]

(*Optional*.) Caller-supplied value representing the length of the string buffer supplied by *pszVetoName*. This should be set to MAX_PATH.

### `ulFlags` [in]

Not used.

### `hMachine` [in, optional]

Caller-supplied machine handle to which the caller-supplied device instance handle is bound.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

If *pszVetoName* is **NULL**, the PnP manager displays a message to the user indicating the device was removed or, if the request failed, identifying the reason for the failure. If *pszVetoName* is not **NULL**, the PnP manager does not display a message. (Note, however, that for Microsoft Windows 2000 only, the PnP manager displays a message even if *pszVetoName* is not **NULL**, if the device's CM_DEVCAP_DOCKDEVICE capability is set.)

For remote machines, this function only works for "dock" device instances. That is, the function can only be used remotely to undock a machine. In that case, the caller must have **SeUndockPrivilege**.

Callers of **CM_Request_Eject_Ex** sometimes require **SeUndockPrivilege** or **SeLoadDriverPrivilege**, as follows:

* If the device's CM_DEVCAP_DOCKDEVICE capability is set (the device is a "dock" device), callers must have **SeUndockPrivilege**. (**SeLoadDriverPrivilege** is not required.)
* If the device's CM_DEVCAP_DOCKDEVICE capability is not set (the device is not a "dock" device), *and* if the calling process is either not interactive or is running in a multi-user environment in a session not attached to the physical console (such as a remote Terminal Services session) callers of this function must have **SeLoadDriverPrivilege**.

(Privileges are described in the Microsoft Windows SDK documentation.)

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)

[CM_Query_And_Remove_SubTree](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtreew)

[CM_Query_And_Remove_SubTree_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtree_exw)

[CM_Request_Device_Eject](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_device_ejectw)