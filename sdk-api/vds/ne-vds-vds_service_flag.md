# VDS_SERVICE_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set
of valid flags for the service object.

## Constants

### `VDS_SVF_SUPPORT_DYNAMIC:0x1`

If set, the service supports dynamic disks.

### `VDS_SVF_SUPPORT_FAULT_TOLERANT:0x2`

If set, the service supports fault-tolerant volumes.

### `VDS_SVF_SUPPORT_GPT:0x4`

If set, the service supports GPT disks.

### `VDS_SVF_SUPPORT_DYNAMIC_1394:0x8`

If set, the service supports dynamic 1394 disks.

### `VDS_SVF_CLUSTER_SERVICE_CONFIGURED:0x10`

If set, the host has the cluster service installed and configured, but not necessarily running.

### `VDS_SVF_AUTO_MOUNT_OFF:0x20`

If set, the auto-mount operation is turned off for the computer to prevent the operating system from
automatically mounting new partitions.

**Note** Beginning with Windows 8 and Windows Server 2012, this flag is deprecated. Instead, use the [VDS_SAN_POLICY](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_san_policy) enumeration to control default disk mounting behavior.

### `VDS_SVF_OS_UNINSTALL_VALID:0x40`

If set, configuration changes to VDS have occurred. After a successful installation, the uninstall
operation is valid only if the configuration changes.

### `VDS_SVF_EFI:0x80`

If set, the machine boots from an EFI partition on a GPT disk.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 with SP1.

### `VDS_SVF_SUPPORT_MIRROR:0x100L`

The service supports mirrored volumes.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_SVF_SUPPORT_RAID5:0x200L`

The service supports RAID-5 volumes.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_SVF_SUPPORT_REFS:0x400L`

## Remarks

This enumeration provides the values for the *ulFlags* member of the
[VDS_SERVICE_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_service_prop) structure. The
[IVdsService::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-setflags) method passes the value as an
argument to set the **VDS_SVF_AUTO_MOUNT_OFF** flag.

**Windows Server 2003:** Many of these enumerators are specific to the Windows Server 2003 platform, which supports
both 1394 and USB devices.

**Note** Additional constants might be added to the **VDS_SERVICE_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_SERVICE_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_SERVICE_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_service_prop)