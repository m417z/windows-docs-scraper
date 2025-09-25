# VDS_VOLUME_PLEX_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a [volume plex object](https://learn.microsoft.com/windows/desktop/VDS/volume-plex-object).

## Members

### `id`

The GUID of the plex object.

### `type`

The plex type enumerated by [VDS_VOLUME_PLEX_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_plex_type). The type of the plex is not required to match the type of the volume to which the plex belongs.

### `status`

The status of the plex object enumerated by [VDS_VOLUME_PLEX_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_plex_status). The status of the plex is not required to match the status of the volume to which the plex belongs.

### `health`

A [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) enumeration value that specifies the health state of the plex. The health state of the plex is not required to match the health state of the volume to which the plex belongs.

### `TransitionState`

A [VDS_TRANSITION_STATE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_transition_state) enumeration value that specifies the transition state of the plex.

### `ullSize`

The size of the plex, in bytes. The size of the plex must be greater than or equal to that of the volume to which the plex belongs. The plex cannot be smaller than the volume.

### `ulStripeSize`

The stripe interleave size, in bytes. This member is valid only for plexes of type **VDS_VPT_STRIPE** (striped) and **VDS_VPT_PARITY** (striped with parity). For other plex types, this member should be zero.

### `ulNumberOfMembers`

The number of members in the volume plex. A plex member is a collection of concatenated disk extents contained on one more disks.

## Remarks

The [IVdsVolumePlex::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeplex-getproperties) method returns this structure to report the properties of a [volume plex object](https://learn.microsoft.com/windows/desktop/VDS/volume-plex-object).

## See also

[IVdsVolumePlex::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeplex-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)

[VDS_TRANSITION_STATE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_transition_state)

[VDS_VOLUME_PLEX_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_plex_status)

[VDS_VOLUME_PLEX_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_plex_type)