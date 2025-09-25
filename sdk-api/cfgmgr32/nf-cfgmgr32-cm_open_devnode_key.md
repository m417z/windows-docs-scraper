# CM_Open_DevNode_Key function

## Description

The **CM_Open_DevNode_Key** function opens a registry key for device-specific configuration information.

## Parameters

### `dnDevNode` [in]

Caller-supplied device instance handle that is bound to the local machine

### `samDesired` [in]

The registry security access that is required for the requested key.

### `ulHardwareProfile` [in]

The hardware profile to open if *ulFlags* includes CM_REGISTRY_CONFIG. If this value is zero, the key for the current hardware profile is opened.

### `Disposition` [in]

Specifies how the registry key is to be opened. May be one of the following values:

#### RegDisposition_OpenAlways

Open the key if it exists. Otherwise, create the key.

#### RegDisposition_OpenExisting

Open the key only if it exists.

### `phkDevice` [out]

Pointer to an HKEY that will receive the opened key upon success.

### `ulFlags` [in]

Open device node key flags. Indicates the scope and type of registry storage key to open. Can be a combination of the following flags:

#### CM_REGISTRY_HARDWARE

Open the device’s hardware key. Do not combine with CM_REGISTRY_SOFTWARE.

#### CM_REGISTRY_SOFTWARE

Open the device’s software key. Do not combine with CM_REGISTRY_HARDWARE.

#### CM_REGISTRY_USER

Open the per-user key for the current user. Do not combine with CM_REGISTRY_CONFIG.

#### CM_REGISTRY_CONFIG

Open the key that stores hardware profile-specific configuration information. Do not combine with CM_REGISTRY_USER.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

Close the handle returned from this function by calling **RegCloseKey**.

## See also

[CM_Delete_DevNode_Key](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_delete_devnode_key)

[SetupDiOpenDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendevregkey)