# DEVICE_STORAGE_RANGE_ATTRIBUTES structure

## Description

The **DEVICE_STORAGE_RANGE_ATTRIBUTES** structure contains the media error status for a logical block range.

## Members

### `LengthInBytes`

Length of the logical block range, in bytes, that the error status in *IsRangeBad* applies to.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.AllFlags`

Do not use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.IsRangeBad`

Indicates whether the logical block range contains a media error. Set to 1 when the logical block range contains an error; otherwise, set to 0.

### `Reserved`

Reserved for future use; do not use.

## Remarks

The output block in the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request is formatted as a [DEVICE_DSM_RANGE_ERROR_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_range_error_info) structure when the action is **DeviceDsmAction_GetRangeErrorInfo**. The driver returns the error status for the logical block ranges in an array of DEVICE_STORAGE_RANGE_ATTRIBUTES structures. The array elements are sorted so that their order corresponds to the order of the input ranges.

See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for more details about this action.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_RANGE_ERROR_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_range_error_info)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)