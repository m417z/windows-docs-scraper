# VDS_VERSION_SUPPORT_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Used to
indicate which versions of the VDS interfaces are supported.

## Constants

### `VDS_VSF_1_0:0x1`

Indicates that the VDS 1.0 interfaces are supported. VDS 1.0 is supported on
Windows Server 2003 and later.

### `VDS_VSF_1_1:0x2`

Indicates that the VDS 1.1 interfaces are supported. VDS 1.1 is supported on
Windows Server 2003 R2 and later.

### `VDS_VSF_2_0:0x4`

Indicates that the VDS 2.0 interfaces are supported. VDS 2.0 is supported on Windows Vista and
later.

**Windows Server 2008, Windows Vista and Windows Server 2003 R2:** This value is not supported.

### `VDS_VSF_2_1:0x8`

Indicates that the VDS 2.1 interfaces are supported. VDS 2.1 is supported on Windows Vista with SP1,
Windows Server 2008, and later.

**Windows Server 2008, Windows Vista and Windows Server 2003 R2:** This value is not supported.

### `VDS_VSF_3_0:0x10`

Indicates that the VDS 3.0 interfaces are supported. VDS 3.0 is supported on Windows 7,
Windows Server 2008 R2, and later.

**Windows Server 2008, Windows Vista and Windows Server 2003 R2:** This value is not supported.

## Remarks

**Note** Additional constants might be added to the
**VDS_VERSION_SUPPORT_FLAG** enumeration in future
Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized
**VDS_VERSION_SUPPORT_FLAG** enumeration
constant.

## See also

[IVdsProviderSupport::GetVersionSupport](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsprovidersupport-getversionsupport)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)