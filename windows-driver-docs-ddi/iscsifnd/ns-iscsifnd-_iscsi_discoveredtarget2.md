# _ISCSI_DiscoveredTarget2 structure

## Description

The ISCSI_DiscoveredTarget2 structure contains information that is related to a discovered target device.

## Members

### `TargetPortalGroupCount`

The number of portal groups that are associated with the target.

### `TargetName`

A name for the target that uniquely identifies the target anywhere in the world. For more information about how to specify this name, see the *iSCSI* specification that is published by the Internet Engineering Task Force (IETF) of the IP storage working group.

### `TargetAlias`

The human-readable name or description that is assigned to the target device by its host operating system. You can use this name in user interfaces, but it is not unique, so you should not use it in authentication decisions.

### `TargetDiscoveredPortalGroups`

A variable-length array of [ISCSI_DiscoveredTargetPortalGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportalgroup2) structures that contains information about the portal groups that the initiator can use to connect to the target.

## Remarks

The WMI tool suite automatically generates a declaration of the ISCSI_DiscoveredTarget2 structure when it compiles the [ISCSI_DiscoveredTarget2 WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtarget2-wmi-class) in *Discover.mof*.

The only difference between the ISCSI_DiscoveredTarget2 structure and the [ISCSI_DiscoveredTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtarget) structure is that the **TargetDiscoveredPortalGroups** member of ISCSI_DiscoveredTarget2 is a [ISCSI_DiscoveredTargetPortalGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportalgroup2) structure instead of a [ISCSI_DiscoveredTargetPortalGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportalgroup) structure.

## See also

[ISCSI_DiscoveredTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtarget)

[ISCSI_DiscoveredTarget WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtarget-wmi-class)

[ISCSI_DiscoveredTarget2 WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtarget2-wmi-class)

[ISCSI_DiscoveredTargetPortalGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportalgroup)