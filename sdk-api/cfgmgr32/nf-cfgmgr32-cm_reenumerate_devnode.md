# CM_Reenumerate_DevNode function

## Description

The **CM_Reenumerate_DevNode** function enumerates the devices identified by a specified device node and all of its children.

## Parameters

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `ulFlags` [in]

Caller-supplied flags that specify how reenumeration should occur. This parameter can be set to a combination of the following flags, as noted:

#### CM_REENUMERATE_ASYNCHRONOUS

Reenumeration should occur asynchronously. The call to this function returns immediately after the PnP manager receives the reenumeration request. If this flag is set, the CM_REENUMERATE_SYNCHRONOUS flag should not also be set.

#### CM_REENUMERATE_NORMAL

Specifies default reenumeration behavior, in which reenumeration occurs synchronously. This flag is functionally equivalent to CM_REENUMERATE_SYNCHRONOUS.

#### CM_REENUMERATE_RETRY_INSTALLATION

Specifies that Plug and Play should make another attempt to install any devices in the specified subtree that have been detected but are not yet configured, or are marked as needing reinstallation, or for which installation must be completed. This flag can be set along with *either* the CM_REENUMERATE_SYNCHRONOUS flag *or* the CM_REENUMERATE_ASYNCHRONOUS flag.

This flag must be used with extreme caution, because it can cause the PnP manager to prompt the user to perform installation of any such devices. Currently, only components such as Device Manager and Hardware Wizard use this flag, to allow the user to retry installation of devices that might already have been detected but are not currently installed.

#### CM_REENUMERATE_SYNCHRONOUS

Reenumeration should occur synchronously. The call to this function returns when all devices in the subtree of the specified device have had reenumeration requests sent to them and those requests have been completed by the device stack. This does not guarantee that the drivers in the device stacks of those devices have rescanned their bus and reported updates. It also does not guarantee that any new devices reported are in the started state. If this flag is set, the CM_REENUMERATE_ASYNCHRONOUS flag should not also be set. This flag is functionally equivalent to CM_REENUMERATE_NORMAL.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

If the specified device node represents a hardware or software bus device, the PnP manager queries the device's drivers for a list of children, then attempts to configure and start any child devices that were not previously configured. The PnP manager also initiates surprise-removal of devices that are no longer present (see [IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal)). However, drivers may choose to update the bus relations they are reporting to the PnP manager asynchronous of the reenumeration request, so the appearance of new devices and removal of devices that are no longer present may not be complete when the reenumeration operation completes.

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)

[CM_Reenumerate_DevNode_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_reenumerate_devnode_ex)

[IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal)