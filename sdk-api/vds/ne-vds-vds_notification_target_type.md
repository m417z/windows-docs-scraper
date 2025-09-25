# VDS_NOTIFICATION_TARGET_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of the valid target types (subjects) of a VDS notification.

## Constants

### `VDS_NTT_UNKNOWN:0`

This value is reserved.

### `VDS_NTT_PACK`

The target is a disk pack. This value corresponds to the **VDS_OT_PACK** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

### `VDS_NTT_VOLUME`

The target is a volume. This value corresponds to the **VDS_OT_VOLUME** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

### `VDS_NTT_DISK`

The target is a disk. This value corresponds to the **VDS_OT_DISK** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

### `VDS_NTT_PARTITION:60`

The target is a partition.

### `VDS_NTT_DRIVE_LETTER:61`

The target is a drive letter.

### `VDS_NTT_FILE_SYSTEM:62`

The target is a file system.

### `VDS_NTT_MOUNT_POINT:63`

The target is a drive letter or volume GUID path.

### `VDS_NTT_SUB_SYSTEM`

The target is a subsystem. This value corresponds to the **VDS_OT_SUB_SYSTEM** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

### `VDS_NTT_CONTROLLER`

The target is a controller. This value corresponds to the **VDS_OT_CONTROLLER** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

### `VDS_NTT_DRIVE`

The target is a drive. This value corresponds to the **VDS_OT_DRIVE** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

### `VDS_NTT_LUN:VDS_OT_LUN`

The target is a LUN. This value corresponds to the **VDS_OT_LUN** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

### `VDS_NTT_PORT`

The target is a controller port.
This value corresponds to the **VDS_OT_PORT** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

**Note** This value is not supported on VDS 1.0.

### `VDS_NTT_PORTAL`

The target is an iSCSI portal.
This value corresponds to the **VDS_OT_PORTAL** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

**Note** This value is not supported on VDS 1.0.

### `VDS_NTT_TARGET`

The target is a target.
This value corresponds to the **VDS_OT_TARGET** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

**Note** This value is not supported on VDS 1.0.

### `VDS_NTT_PORTAL_GROUP`

The target is an iSCSI portal group.
This value corresponds to the **VDS_PORTAL_GROUP** value in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

**Note** This value is not supported on VDS 1.0.

### `VDS_NTT_SERVICE:200`

This member is not currently used.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes a **VDS_NOTIFICATION_TARGET_TYPE**
value as a member to indicate a notification type. Some values in the **VDS_NOTIFICATION_TARGET_TYPE** correspond to values in the [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration. For the integer value of a VDS object type,
such as a volume or LUN object, see the
[VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration.

**Note** Additional constants might be added to the **VDS_NOTIFICATION_TARGET_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_NOTIFICATION_TARGET_TYPE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)

[VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type)