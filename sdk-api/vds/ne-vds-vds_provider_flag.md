# VDS_PROVIDER_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set
of valid flags for a provider object.

## Constants

### `VDS_PF_DYNAMIC:0x1`

The provider is a dynamic provider. If this flag is set for the provider of a disk, the disk is dynamic.

### `VDS_PF_INTERNAL_HARDWARE_PROVIDER:0x2`

The operating system supplies this hardware provider to manage an internal hardware controller.

### `VDS_PF_ONE_DISK_ONLY_PER_PACK:0x4`

The provider supports single-disk packs only. Typically, the basic provider sets this flag to
simulate a pack with one disk.

### `VDS_PF_ONE_PACK_ONLINE_ONLY:0x8`

The provider is a dynamic provider that supports online status for only one pack at a time.

**Windows Server 2003:** Only applies to this release.

### `VDS_PF_VOLUME_SPACE_MUST_BE_CONTIGUOUS:0x10`

All volumes managed by this provider must have contiguous space. This flag applies to basic
providers only.

### `VDS_PF_SUPPORT_DYNAMIC:0x80000000`

If this flag is set, VDS sets the **VDS_SVF_SUPPORT_DYNAMIC** flag in the [VDS_SERVICE_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_service_prop) structure.

### `VDS_PF_SUPPORT_FAULT_TOLERANT:0x40000000`

If this flag is set, VDS sets the **VDS_SVF_SUPPORT_FAULT_TOLERANT**
flag in the [VDS_SERVICE_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_service_prop) structure.

### `VDS_PF_SUPPORT_DYNAMIC_1394:0x20000000`

If this flag is set, VDS sets the **VDS_SVF_SUPPORT_DYNAMIC_1394**
flag in the [VDS_SERVICE_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_service_prop) structure.

### `VDS_PF_SUPPORT_MIRROR:0x20`

If this flag is set, VDS sets the **VDS_SVF_SUPPORT_MIRROR** flag in the [VDS_SERVICE_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_service_prop) structure.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_PF_SUPPORT_RAID5:0x40`

If this flag is set, VDS sets the **VDS_SVF_SUPPORT_RAID5** flag in the [VDS_SERVICE_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_service_prop) structure.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

## Remarks

This enumeration provides the values for the *ulFlags* member of the
[VDS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_provider_prop) structure.

**Note** Additional constants might be added to the **VDS_PROVIDER_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_PROVIDER_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_provider_prop)