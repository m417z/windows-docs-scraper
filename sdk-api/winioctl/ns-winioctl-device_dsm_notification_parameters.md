# DEVICE_DSM_NOTIFICATION_PARAMETERS structure

## Description

Contains parameters for the **DeviceDsmAction_Notification** action for the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `Size`

Specifies the total size, in bytes, of this structure. The value of this member must include the total
size, in bytes, of the **FileTypeIDs** member.

### `Flags`

Flags specific to the notify operation

| Value | Meaning |
| --- | --- |
| **DEVICE_DSM_NOTIFY_FLAG_BEGIN**<br><br>0x00000001 | The ranges specified in the [DEVICE_DATA_SET_RANGE](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-device_data_set_range) structures following the [DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes) structure are currently being used by the file types that are specified in the **FileTypeIDs** member. |
| **DEVICE_DSM_NOTIFY_FLAG_END**<br><br>0x00000002 | The ranges are no longer being used by the file types that are specified in the **FileTypeIDs** member. |

### `NumFileTypeIDs`

The number of entries in the **FileTypeIDs** member.

### `FileTypeID`

One or more **GUID** values that specify the file type for the notification
operation.

| Value | Meaning |
| --- | --- |
| **FILE_TYPE_NOTIFICATION_GUID_PAGE_FILE**<br><br>0d0a64a1-38fc-4db8-9fe7-3f4352cd7c5c | Specifies a notification operation for a page file. |
| **FILE_TYPE_NOTIFICATION_GUID_HIBERNATION_FILE**<br><br>b7624d64-b9a3-4cf8-8011-5b86c940e7b7 | Specifies a notification operation for the system hibernation file. |
| **FILE_TYPE_NOTIFICATION_GUID_CRASHDUMP_FILE**<br><br>9d453eb7-d2a6-4dbd-a2e3-fbd0ed9109a9 | Specifies a notification operation for a system crash dump file. |

## See also

[DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)