# VDS_PROVIDER_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
properties of a [provider object](https://learn.microsoft.com/windows/desktop/VDS/provider-object).

## Members

### `id`

The GUID of the provider object.

### `pwszName`

A string representing the name of the provider.

### `guidVersionId`

The version-specific GUID of the provider.

### `pwszVersion`

A string representing the version of the provider.

### `type`

The provider types enumerated by
[VDS_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_provider_type).

### `ulFlags`

The provider flags enumerated by
[VDS_PROVIDER_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_provider_flag).

### `ulStripeSizeFlags`

The size of a stripe to be used across multiple disks managed by a software provider. A stripe size must be
a power of 2. Each bit in the 32-bit integer represents a size, in bytes. For example, if the *n*th bit is set, then
VDS supports stripe size of 2^*n*. Thus, bits 0 through 31 can specify 2^0 through 2^31.

The basic provider sets this value to zero. The dynamic stripe size can be any power of 2 ranging from 512
to 1MB.

**Windows Server 2003:** The dynamic provider sets this value to 64k.

### `sRebuildPriority`

The rebuild priority used by software providers to specify the regeneration order when a mirrored or
striped with parity (RAID-5) volume requires rebuilding. Priority levels are 0 (lowest priority) to 15 (highest priority). VDS propagates the
priority to all new volumes created by the provider. Thus, all volumes managed by a provider have the same
rebuild priority.

This member does not apply to the basic provider and is zero for the dynamic provider.

## Remarks

The [IVdsProvider::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsprovider-getproperties) method
returns this structure to report the property details of a provider object.

## See also

[IVdsProvider::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsprovider-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_PROVIDER_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_provider_flag)

[VDS_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_provider_type)