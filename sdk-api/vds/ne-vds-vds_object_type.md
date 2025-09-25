# VDS_OBJECT_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of
valid types of a VDS object.

## Constants

### `VDS_OT_UNKNOWN:0`

This value is reserved.

### `VDS_OT_PROVIDER:1`

The object is a [provider](https://learn.microsoft.com/windows/desktop/VDS/provider-object).

### `VDS_OT_PACK:10`

The object is a [disk pack](https://learn.microsoft.com/windows/desktop/VDS/pack-object).

### `VDS_OT_VOLUME:11`

The object is a [volume](https://learn.microsoft.com/windows/desktop/VDS/volume-object).

### `VDS_OT_VOLUME_PLEX:12`

The object is a [volume plex](https://learn.microsoft.com/windows/desktop/VDS/volume-plex-object).

### `VDS_OT_DISK:13`

The object is a [disk](https://learn.microsoft.com/windows/desktop/VDS/disk-object).

### `VDS_OT_SUB_SYSTEM:30`

The object is a [subsystem](https://learn.microsoft.com/windows/desktop/VDS/subsystem-object).

### `VDS_OT_CONTROLLER:31`

The object is a [controller](https://learn.microsoft.com/windows/desktop/VDS/controller-object).

### `VDS_OT_DRIVE:32`

The object is a [drive](https://learn.microsoft.com/windows/desktop/VDS/drive-object).

### `VDS_OT_LUN:33`

The object is a [LUN](https://learn.microsoft.com/windows/desktop/VDS/lun-object).

### `VDS_OT_LUN_PLEX:34`

The object is a [LUN plex](https://learn.microsoft.com/windows/desktop/VDS/lun-plex-object).

### `VDS_OT_PORT:35`

The object is a [controller port](https://learn.microsoft.com/windows/desktop/VDS/controller-port-object).

### `VDS_OT_PORTAL:36`

The object is an [iSCSI portal](https://learn.microsoft.com/windows/desktop/VDS/portal-object).

### `VDS_OT_TARGET:37`

The object is an [iSCSI target](https://learn.microsoft.com/windows/desktop/VDS/target-object).

### `VDS_OT_PORTAL_GROUP:38`

The object is an [iSCSI portal group](https://learn.microsoft.com/windows/desktop/VDS/portal-group-object).

### `VDS_OT_STORAGE_POOL:39`

The object is a [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_OT_HBAPORT:90`

The object is an [HBA port](https://learn.microsoft.com/windows/desktop/VDS/startup-and-service-objects).

### `VDS_OT_INIT_ADAPTER:91`

The object is an [iSCSI initiator adapter](https://learn.microsoft.com/windows/desktop/VDS/startup-and-service-objects).

### `VDS_OT_INIT_PORTAL:92`

The object is an [iSCSI initiator portal](https://learn.microsoft.com/windows/desktop/VDS/startup-and-service-objects).

### `VDS_OT_ASYNC:100`

This value is reserved.

### `VDS_OT_ENUM:101`

This value is reserved.

### `VDS_OT_VDISK:200`

The object is a virtual disk.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_OT_OPEN_VDISK:201`

This value is reserved.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

## Remarks

The [IVdsProviderPrivate::GetObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsproviderprivate-getobject)
and [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) methods pass a **VDS_OBJECT_TYPE**
value as an argument to indicate an object type.

**Note** Additional constants might be added to the **VDS_OBJECT_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_OBJECT_TYPE** enumeration constant.

## See also

[IVdsProviderPrivate::GetObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsproviderprivate-getobject)

[IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)