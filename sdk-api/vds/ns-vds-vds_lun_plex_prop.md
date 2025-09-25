# VDS_LUN_PLEX_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a [LUN plex object](https://learn.microsoft.com/windows/desktop/VDS/lun-plex-object).

## Members

### `id`

The GUID of the plex object.

### `ullSize`

The size of the plex, in bytes. The size of the plex can be equal to or greater than that of the LUN to which the plex belongs. The plex cannot be smaller than the LUN.

### `type`

A [VDS_LUN_PLEX_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_lun_plex_type) enumeration value that specifies the type of the plex. The type of the plex is not required to match the type of the LUN to which it belongs.

### `status`

A [VDS_LUN_PLEX_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_lun_plex_status) enumeration value that specifies the status of the plex. The status of the plex is not required to match the status of the LUN to which it belongs.

### `health`

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)

#### VDS_H_UNKNOWN (0)

#### VDS_H_HEALTHY (1)

#### VDS_H_REBUILDING (2)

#### VDS_H_FAILING (4)

#### VDS_H_FAILING_REDUNDANCY (5)

#### VDS_H_FAILED_REDUNDANCY (6)

#### VDS_H_FAILED_REDUNDANCY_FAILING (7)

#### VDS_H_FAILED (8)

### `TransitionState`

A [VDS_TRANSITION_STATE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_transition_state) enumeration value that specifies the transition state of the plex. The transition state of the plex is not required to match that of the LUN to which the plex belongs.

### `ulFlags`

A bitmask of [VDS_LUN_PLEX_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_lun_plex_flag) enumeration values that describe the plex.

### `ulStripeSize`

The stripe interleave size, in bytes. This member is valid only for plexes of type **VDS_LPT_STRIPE** (striped) and **VDS_LPT_PARITY** (striped with parity). For other plex types, this member should be zero.

### `sRebuildPriority`

The rebuild priority of the plex. This value must be greater than or equal to 0 (lowest priority) and less than or equal to 15 (highest priority).

## Remarks

The [IVdsLunPlex::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-getproperties) method returns this structure to report the properties of a [LUN plex object](https://learn.microsoft.com/windows/desktop/VDS/lun-plex-object).

## See also

[IVdsLunPlex::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)

[VDS_LUN_PLEX_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_lun_plex_flag)

[VDS_LUN_PLEX_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_lun_plex_status)

[VDS_LUN_PLEX_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_lun_plex_type)

[VDS_TRANSITION_STATE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_transition_state)