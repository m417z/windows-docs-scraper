# _ISCSI_DiscoveredTarget structure

## Description

The ISCSI_DiscoveredTarget structure contains information that is related to a discovered target device.

## Members

### `TargetPortalGroupCount`

The number of portal groups that are associated with the target.

### `TargetName`

A name for the target that uniquely identifies the target anywhere in the world. For information about how to specify this name, see the *iSCSI* specification that is published by the Internet Engineering Task Force (IETF) of the IP storage working group.

### `TargetAlias`

The human-readable name or description that is assigned to the target device by its host operating system. You can use this name in user interfaces, but it is not unique, you should not use it in authentication decisions.

### `TargetDiscoveredPortalGroups`

A variable-length array of [ISCSI_DiscoveredTargetPortalGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportalgroup) structures that contains information about the portal groups that the initiator can use to connect to the target.

## Remarks

The WMI tool suite automatically generates a declaration of the ISCSI_DiscoveredTarget structure when it compiles the [ISCSI_DiscoveredTarget WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtarget-wmi-class) in *Discover.mof*.

## See also

[ISCSI_DiscoveredTarget WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtarget-wmi-class)

[ISCSI_DiscoveredTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtarget2)

[ISCSI_DiscoveredTargetPortalGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportalgroup)