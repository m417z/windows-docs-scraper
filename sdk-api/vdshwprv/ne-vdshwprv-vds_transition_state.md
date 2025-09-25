# VDS_TRANSITION_STATE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
the set of the valid transition state values for a VDS object.

## Constants

### `VDS_TS_UNKNOWN:0`

This value is reserved.

### `VDS_TS_STABLE:1`

The object is stable. No configuration activity is currently in progress.

### `VDS_TS_EXTENDING:2`

The object is being extended.

### `VDS_TS_SHRINKING:3`

The object is being shrunk.

### `VDS_TS_RECONFIGING:4`

The object is being automagically reconfigured.

### `VDS_TS_RESTRIPING:5`

The object is being restriped.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

Transition state enumeration values apply to the VDS objects as shown in the following table. Y indicates that the value
applies to the object, and N indicates that the value does not apply to the object.

| Transition state enumeration value | LUN | LUN plex | Volume | Volume plex |
| --- | --- | --- | --- | --- |
| **VDS_TS_UNKNOWN** | Y | Y | N | N |
| **VDS_TS_STABLE** | Y | Y | Y | Y |
| **VDS_TS_EXTENDING** | Y | Y | N | N |
| **VDS_TS_SHRINKING** | Y | Y | N | N |
| **VDS_TS_RECONFIGING** | Y | Y | N | N |
| **VDS_TS_RESTRIPING** | Y | Y | N | N |

The [VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop),
[VDS_LUN_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_plex_prop),
[VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop), [VDS_VOLUME_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop2), and
[VDS_VOLUME_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_plex_prop) structures include a **VDS_TRANSITION_STATE**
value as a member to report the transition state of each object.

If your application encounters a **VDS_TRANSITION_STATE** value that it does not recognize, it should display the transition state as unknown. It should not attempt to map the unrecognized transition state to another transition state.

**Note** Additional constants might be added to the **VDS_TRANSITION_STATE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_TRANSITION_STATE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_LUN_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_plex_prop)

[VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop)

[VDS_VOLUME_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_plex_prop)

[VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop)

[VDS_VOLUME_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop2)