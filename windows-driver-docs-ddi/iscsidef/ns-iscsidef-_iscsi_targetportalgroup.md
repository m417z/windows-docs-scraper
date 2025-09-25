# _ISCSI_TargetPortalGroup structure

## Description

The ISCSI_TargetPortalGroup structure provides a definition of a target portal group.

## Members

### `PortalCount`

The number of portals in the portal group.

### `Portals`

A variable-length array of [ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal) structures, which describe portals in the target portal group. The number of elements in the array is specified by the PortalCount field.

## See also

[ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal)

[ISCSI_TargetPortalGroup WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-targetportalgroup-wmi-class)