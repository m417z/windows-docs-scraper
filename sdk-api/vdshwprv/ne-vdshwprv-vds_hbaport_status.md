# VDS_HBAPORT_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
the set of valid statuses for an HBA port. These values are used in the
**status** member of the
[VDS_HBAPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hbaport_prop) structure. These states correspond to
the HBA_PORTSTATE values in the HBA API.

## Constants

### `VDS_HPS_UNKNOWN:1`

The HBA port status is unknown.

HBA_PORTSTATE_UNKNOWN

### `VDS_HPS_ONLINE:2`

The HBA port is operational.

HBA_PORTSTATE_ONLINE

### `VDS_HPS_OFFLINE:3`

The HBA port has been set offline by a user.

HBA_PORTSTATE_OFFLINE

### `VDS_HPS_BYPASSED:4`

The HBA port is bypassed.

HBA_PORTSTATE_BYPASSED

### `VDS_HPS_DIAGNOSTICS:5`

The HBA port is in diagnostics mode.

HBA_PORTSTATE_DIAGNOSTICS

### `VDS_HPS_LINKDOWN:6`

The HBA port link is down.

HBA_PORTSTATE_LINKDOWN

### `VDS_HPS_ERROR:7`

The HBA port has an error.

HBA_PORTSTATE_ERROR

### `VDS_HPS_LOOPBACK:8`

The HBA port is loopback.

HBA_PORTSTATE_LOOPBACK

## Remarks

**Note** Additional constants might be added to the **VDS_HBAPORT_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_HBAPORT_STATUS** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_HBAPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hbaport_prop)