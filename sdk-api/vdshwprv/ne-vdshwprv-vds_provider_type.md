# VDS_PROVIDER_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set
of valid types for a provider.

## Constants

### `VDS_PT_UNKNOWN:0`

The provider type is unknown.

### `VDS_PT_SOFTWARE:1`

The provider is a software provider.

### `VDS_PT_HARDWARE:2`

The provider is a hardware provider.

### `VDS_PT_VIRTUALDISK:3`

The provider is a virtual disk provider.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_PT_MAX:4`

This value is reserved for system use.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

## Remarks

The [VDS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_provider_prop) structure includes a **VDS_PROVIDER_TYPE**
value as a member to report the provider type. The
[IVdsAdmin::RegisterProvider](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsadmin-registerprovider) method passes
a **VDS_PROVIDER_TYPE** value as an argument to indicate the provider type during registration with VDS.

**Note** Additional constants might be added to the **VDS_PROVIDER_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_PROVIDER_TYPE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_provider_prop)