# VDS_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the VDS
notification structures specific to each notification target type (subject).

## Members

### `objectType`

 Discriminant for the union enumerated by
[VDS_NOTIFICATION_TARGET_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_notification_target_type).

| Value | Meaning |
| --- | --- |
| **VDS_NTT_PACK**<br><br>10 | The subject of the notification is a disk pack. Use the **Pack** member structure. |
| **VDS_NTT_DISK**<br><br>13 | The subject of the notification is a disk. Use the **Disk** member structure. |
| **VDS_NTT_VOLUME**<br><br>11 | The subject of the notification is a volume. Use the **Volume** member structure. |
| **VDS_NTT_PARTITION**<br><br>60 | The subject of the notification is a partition. Use the **Partition** member structure. |
| **VDS_NTT_DRIVE_LETTER**<br><br>61 | The subject of the notification is a drive letter. Use the **Letter** member structure. |
| **VDS_NTT_FILE_SYSTEM**<br><br>62 | The subject of the notification is a file system. Use the **FileSystem** member structure. |
| **VDS_NTT_MOUNT_POINT**<br><br>63 | The subject of the notification is a drive letter or volume GUID path. Use the **MountPoint** member structure. |
| **VDS_NTT_SUB_SYSTEM**<br><br>30 | Used by hardware providers. The subject of the notification is a subsystem. Use the **SubSystem** member structure. |
| **VDS_NTT_CONTROLLER**<br><br>31 | Used by hardware providers. The subject of the notification is a controller. Use the **Controller** member structure. |
| **VDS_NTT_DRIVE**<br><br>32 | Used by hardware providers. The subject of the notification is a drive. Use the **Drive** member structure. |
| **VDS_NTT_LUN**<br><br>33 | Used by hardware providers. The subject of the notification is a LUN. Use the **Lun** member structure. |
| **VDS_NTT_PORT**<br><br>35 | The subject of the notification is a controller port. Use the **Port** member structure. |
| **VDS_NTT_PORTAL**<br><br>36 | The subject of the notification is an iSCSI portal. Use the **Portal** member structure. |
| **VDS_NTT_TARGET**<br><br>37 | The subject of the notification is an iSCSI target. Use the **Target** member structure. |
| **VDS_NTT_PORTAL_GROUP**<br><br>38 | The subject of the notification is an iSCSI portal group. Use the **PortalGroup** member structure. |

### `Pack`

Valid if **objectType** is **VDS_NTT_PACK**. See the
[VDS_PACK_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pack_notification)
structure.

### `Disk`

Valid if **objectType** is **VDS_NTT_DISK**. See the
[VDS_DISK_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_disk_notification)
structure.

### `Volume`

Valid if **objectType** is **VDS_NTT_VOLUME**. See the
[VDS_VOLUME_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_volume_notification)
structure.

### `Partition`

Valid if **objectType** is **VDS_NTT_PARTITION**. See the
[VDS_PARTITION_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_partition_notification)
structure.

### `Letter`

Valid if **objectType** is **VDS_NTT_DRIVE_LETTER**. See the
[VDS_DRIVE_LETTER_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_letter_notification)
structure.

### `FileSystem`

Valid if **objectType** is **VDS_NTT_FILE_SYSTEM**. See the
[VDS_FILE_SYSTEM_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_file_system_notification)
structure.

### `MountPoint`

Valid if **objectType** is **VDS_NTT_MOUNT_POINT**. See the
[VDS_MOUNT_POINT_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_mount_point_notification)
structure.

### `SubSystem`

Valid if **objectType** is **VDS_NTT_SUB_SYSTEM**. See the
[VDS_SUB_SYSTEM_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_notification)
structure.

### `Controller`

Valid if **objectType** is **VDS_NTT_CONTROLLER**. See the
[VDS_CONTROLLER_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_controller_notification)
structure.

### `Drive`

Valid if **objectType** is **VDS_NTT_DRIVE**. See the
[VDS_DRIVE_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_notification)
structure.

### `Lun`

Valid if **objectType** is **VDS_NTT_LUN**. See the
[VDS_LUN_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_notification)
structure.

### `Port`

Valid if **objectType** is **VDS_NTT_PORT**. See the
[VDS_PORT_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_port_notification)
structure.

**Note** This is not supported on VDS 1.0

### `Portal`

Valid if **objectType** is **VDS_NTT_PORTAL**. See the
[VDS_PORTAL_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_portal_notification)
structure.

**Note** This is not supported on VDS 1.0

### `Target`

Valid if **objectType** is **VDS_NTT_TARGET**. See the
[VDS_TARGET_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_target_notification)
structure.

**Note** This is not supported on VDS 1.0

### `PortalGroup`

Valid if **objectType** is **VDS_NTT_PORTAL_GROUP**. See the
[VDS_PORTAL_GROUP_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_portal_group_notification)
structure.

**Note** This is not supported on VDS 1.0

### `Service`

## Remarks

Applications pass this structure in the *pNotificationArray* parameter of the
[IVdsAdviseSink::OnNotify](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsadvisesink-onnotify) method.

The members of this structure are aligned on an 8-byte boundary.

## See also

[IVdsAdviseSink::OnNotify](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsadvisesink-onnotify)

[VDS_NOTIFICATION_TARGET_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_notification_target_type)