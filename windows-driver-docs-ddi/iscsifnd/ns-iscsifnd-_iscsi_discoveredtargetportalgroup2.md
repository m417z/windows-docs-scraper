# _ISCSI_DiscoveredTargetPortalGroup2 structure

## Description

The ISCSI_DiscoveredTargetPortalGroup2 structure contains information about a discovered target portal group.

## Members

### `PortalCount`

The number of portals in the group.

### `Tag`

A tag number that identifies the portal group.

### `Portals`

An array of [ISCSI_DiscoveredTargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportal) structures, which describe target portals.

## Remarks

The WMI tool suite automatically generates a declaration of the ISCSI_DiscoveredTargetPortalGroup2 structure when it compiles the [ISCSI_DiscoveredTargetPortalGroup2 WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtargetportalgroup2-wmi-class) in *Discover.mof*.

## See also

[ISCSI_DiscoveredTargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportal)

[ISCSI_DiscoveredTargetPortalGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportalgroup)

[ISCSI_DiscoveredTargetPortalGroup WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtargetportalgroup-wmi-class)

[ISCSI_DiscoveredTargetPortalGroup2 WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtargetportalgroup2-wmi-class)