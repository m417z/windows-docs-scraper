# CM_Delete_DevNode_Key function

## Description

The **CM_Delete_DevNode_Key** function deletes the specified user-accessible registry keys that are associated with a device.

## Parameters

### `dnDevNode` [in]

Device instance handle that is bound to the local machine.

### `ulHardwareProfile` [in]

The hardware profile to delete if *ulFlags* includes CM_REGISTRY_CONFIG. If this value is zero, the key for the current hardware profile is deleted. If this value is 0xFFFFFFFF, the registry keys for all hardware profiles are deleted.

### `ulFlags` [in]

Delete device node key flags. Indicates the scope and type of registry storage key to delete. Can be a combination of the following flags:

#### CM_REGISTRY_HARDWARE

Delete the device’s hardware key. Do not combine with CM_REGISTRY_SOFTWARE.

#### CM_REGISTRY_SOFTWARE

Delete the device’s software key. Do not combine with CM_REGISTRY_HARDWARE.

#### CM_REGISTRY_USER

Delete the per-user key for the current user. Do not combine with CM_REGISTRY_CONFIG.

#### CM_REGISTRY_CONFIG

Delete the key that stores hardware profile-specific configuration information. Do not combine with CM_REGISTRY_USER.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## See also

[CM_Open_DevNode_Key](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_open_devnode_key)

[SetupDiDeleteDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdideletedevregkey)