# CM_Get_Sibling function

## Description

The **CM_Get_Sibling** function obtains a device instance handle to the next sibling node of a specified device node ([devnode](https://learn.microsoft.com/windows-hardware/drivers/)) in the local machine's [device tree](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-tree).

> [!NOTE]
> In Windows Vista and later versions of Windows, the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-) uses the [**DEVPKEY_Device_Siblings**](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-siblings) [property key](https://learn.microsoft.com/windows-hardware/drivers/install/property-keys) to represent device siblings. See [Retrieving Device Relations](https://learn.microsoft.com/windows-hardware/drivers/install/retrieving-device-relations) for details.

## Parameters

### `pdnDevInst` [out]

Caller-supplied pointer to the device instance handle to the sibling node that this function retrieves. The retrieved handle is bound to the local machine.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

To enumerate all children of a devnode in the local machine's device tree, first call [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child) to obtain a handle to the first child node, then call **CM_Get_Sibling** to obtain handles for the rest of the children.

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_Sibling_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_sibling_ex)