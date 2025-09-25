# CM_Request_Device_EjectA function

## Description

The **CM_Request_Device_Eject** function prepares a local device instance for safe removal, if the device is removable. If the device can be physically ejected, it will be.

## Parameters

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `pVetoType` [out, optional]

(*Optional*.) If not **NULL**, this points to a location that, if the removal request fails, receives a [PNP_VETO_TYPE](https://learn.microsoft.com/windows/desktop/api/cfg/ne-cfg-pnp_veto_type)-typed value indicating the reason for the failure.

### `pszVetoName` [out, optional]

(*Optional*.) If not **NULL**, this is a caller-supplied pointer to a string buffer that receives a text string. The type of information this string provides is dependent on the value received by *pVetoType*. For information about these strings, see [PNP_VETO_TYPE](https://learn.microsoft.com/windows/desktop/api/cfg/ne-cfg-pnp_veto_type).

### `ulNameLength` [in]

(*Optional*.) Caller-supplied value representing the length of the string buffer supplied by *pszVetoName*. This should be set to MAX_PATH.

### `ulFlags` [in]

Not used.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

If *pszVetoName* is **NULL**, the PnP manager displays a message to the user indicating the device was removed or, if the request failed, identifying the reason for the failure. If *pszVetoName* is not **NULL**, the PnP manager does not display a message. (Note, however, that for Microsoft Windows 2000 only, the PnP manager displays a message even if *pszVetoName* is not **NULL**, if the device's CM_DEVCAP_DOCKDEVICE capability is set.)

Callers of **CM_Request_Device_Eject** sometimes require **SeUndockPrivilege** or **SeLoadDriverPrivilege**, as follows:

* If the device's CM_DEVCAP_DOCKDEVICE capability is set (the device is a "dock" device), callers must have **SeUndockPrivilege**. (**SeLoadDriverPrivilege** is not required.)
* If the device's CM_DEVCAP_DOCKDEVICE capability is not set (the device is not a "dock" device), *and* if the calling process is either not interactive or is running in a multi-user environment in a session not attached to the physical console (such as a remote Terminal Services session), callers of this function must have **SeLoadDriverPrivilege**.

Privileges are described in the Microsoft Windows SDK documentation.

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)
[CM_Query_And_Remove_SubTree](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtreea)
[CM_Query_And_Remove_SubTree_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtree_exa)
[CM_Request_Device_Eject_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_device_eject_exa)