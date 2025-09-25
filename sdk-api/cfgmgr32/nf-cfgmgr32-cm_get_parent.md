# CM_Get_Parent function

## Description

The **CM_Get_Parent** function obtains a device instance handle to the parent node of a specified device node ([devnode](https://learn.microsoft.com/windows-hardware/drivers/)) in the local machine's device tree.

> [!NOTE]
> In Windows Vista and later versions of Windows, the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-) uses the [**DEVPKEY_Device_Parent**](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-parent) [property key](https://learn.microsoft.com/windows-hardware/drivers/install/property-keys) to represent device parent. See [Retrieving Device Relations](https://learn.microsoft.com/windows-hardware/drivers/install/retrieving-device-relations) for details.

## Parameters

### `pdnDevInst` [out]

Caller-supplied pointer to the device instance handle to the parent node that this function retrieves. The retrieved handle is bound to the local machine.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

For information about using a device instance handle that is bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_Parent_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_parent_ex)