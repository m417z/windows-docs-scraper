# DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS structure

## Description

The DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS structure contains caching priority information to apply to a range of logical blocks.

## Members

### `Size`

Size of this structure. Set to **sizeof**(DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS).

### `TargetPriority`

The target caching priority to apply to a range of logical blocks.

### `Reserved`

Reserved for future use; do not use.

## Remarks

The output block in the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request is formatted as a DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS structure when the action is **DeviceDsmAction_NvCache_Change_Priority**. See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for more details about this action.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)