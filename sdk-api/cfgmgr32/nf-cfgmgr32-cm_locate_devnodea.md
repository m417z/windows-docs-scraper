# CM_Locate_DevNodeA function

## Description

The **CM_Locate_DevNode** function obtains a device instance handle to the device node that is associated with a specified [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) on the local machine.

## Parameters

### `pdnDevInst` [out]

A pointer to a device instance handle that **CM_Locate_DevNode** retrieves. The retrieved handle is bound to the local machine.

### `pDeviceID` [in, optional]

A pointer to a NULL-terminated string representing a [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids). If this value is **NULL**, or if it points to a zero-length string, the function retrieves a device instance handle to the device at the root of the [device tree](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-tree).

### `ulFlags` [in]

A variable of ULONG type that supplies one of the following flag values that apply if the caller supplies a device instance identifier:

#### CM_LOCATE_DEVNODE_NORMAL

The function retrieves the device instance handle for the specified device only if the device is currently configured in the device tree.

#### CM_LOCATE_DEVNODE_PHANTOM

The function retrieves a device instance handle for the specified device if the device is currently configured in the device tree or the device is a [nonpresent device](https://learn.microsoft.com/windows-hardware/drivers/) that is not currently configured in the device tree.

#### CM_LOCATE_DEVNODE_CANCELREMOVE

The function retrieves a device instance handle for the specified device if the device is currently configured in the device tree or in the process of being removed from the device tree. If the device is in the process of being removed, the function cancels the removal of the device.

#### CM_LOCATE_DEVNODE_NOVALIDATION

Not used.

## Return value

If the operation succeeds, **CM_Locate_DevNode** returns CR_SUCCESS. Otherwise, the function returns one of the CR_*Xxx* error codes that are defined in *Cfgmgr32.h*.

## Remarks

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

> [!NOTE]
> The cfgmgr32.h header defines CM_Locate_DevNode as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Locate_DevNode_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_locate_devnode_exw)