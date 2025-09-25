# _DEVICE_DSM_NOTIFICATION_PARAMETERS structure

## Description

The DEVICE_DSM_NOTIFICATION_PARAMETERS structure specifies the parameters for a notification operation related to the data-set attributes for a device.

## Members

### `Size`

The total size, in bytes, of this structure. The value of this member must include the total size, in bytes, of the **FileTypeID** member.

### `Flags`

A flag that specifies the characteristics of the notification operation. The **Flags** member must be set to one of the following values:

| Flag | Meaning |
| ---- | ------- |
| DEVICE_DSM_NOTIFY_FLAG_BEGIN | The Logical Block Address (LBA) range is currently being used by the file types that are specified in the **FileTypeID** member. The LBA range is specified by the data set range within the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request. |
| DEVICE_DSM_NOTIFY_FLAG_END | The LBA range is no longer being used by the file types that are specified in the **FileTypeID** member. |

### `NumFileTypeIDs`

The number of entries in the **FileTypeID** member.

### `FileTypeID`

One or more [GUID](https://learn.microsoft.com/windows-hardware/customize/desktop/unattend/microsoft-windows-shell-setup-notificationarea-promotedicon2-guid) values that specify the file type for the notification operation. The following table describes the **FileTypeID** GUID values.

| GUID value | Description |
| ---------- | ----------- |
| FILE_TYPE_NOTIFICATION_GUID_PAGE_FILE | Specifies a notification operation for a page file. |
| FILE_TYPE_NOTIFICATION_GUID_HIBERNATION_FILE | Specifies a notification operation for the system hibernation file. |
| FILE_TYPE_NOTIFICATION_GUID_CRASHDUMP_FILE | Specifies a notification operation for a system crash dump file. |

## Remarks

The notification is specified in the parameter block within the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request. See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for a general description of the payload layout.

Starting with Windows 7, the NTFS file system notifies the storage stack when the logical block addressing (LBA) data set range changes for a specified set of files. The file system issues this notification by sending the storage stack an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request with a system buffer that contains a [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure. For the notification operation, the file system sets the members of the DEVICE_DSM_INPUT structure as follows:

* The **Action** member is set to **DeviceDsmAction_Notification**.
* The **ParameterBlockOffset** and **ParameterBlockLength** members specify the location and size of the parameter block for the notification operation. The parameter block is formatted as a DEVICE_DSM_NOTIFICATION_PARAMETERS structure.
* If the **Flags** member is set to zero, the **DataSetRangesOffset** and **DataSetRangesLength** members specify the data set range block within the IOCTL payload.
* If the **Flags** member is set to DEVICE_DSM_FLAG_ENTIRE_DATA_SET_RANGE, the **DataSetRangesOffset** and **DataSetRangesLength** members are set to zero and the notification action includes the entire data set range for the specified files.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)