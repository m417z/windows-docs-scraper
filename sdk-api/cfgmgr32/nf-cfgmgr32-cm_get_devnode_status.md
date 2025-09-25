## Description

The **CM_Get_DevNode_Status** function obtains the status of a device instance from its device node ([devnode](https://learn.microsoft.com/windows-hardware/drivers/)) in the local machine's [device tree](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-tree).

> [!NOTE]
> In Windows Vista, and later, the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-) uses the [**DEVPKEY_Device_DevNodeStatus**](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-devnodestatus) [property key](https://learn.microsoft.com/windows-hardware/drivers/install/property-keys) to represent the device instance identifier. For details, see [Retrieving the status and problem code for a device instance](https://learn.microsoft.com/windows-hardware/drivers/install/retrieving-the-status-and-problem-code-for-a-device-instance).

## Parameters

### `pulStatus` [out]

Address of a location to receive status bit flags. The function can set any combination of the **DN_-** prefixed bit flags defined in *Cfg.h*.

### `pulProblemNumber` [out]

Address of a location to receive one of the **CM_PROB_**-prefixed problem values defined in *Cfg.h*. Used only if DN_HAS_PROBLEM is set in *pulStatus*.

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Get_DevNode_Status_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status_ex)