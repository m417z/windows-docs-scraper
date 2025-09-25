# DEVICE_DSM_RANGE_ERROR_INFO structure

## Description

The **DEVICE_DSM_RANGE_ERROR_OUTPUT** (or DEVICE_DSM_RANGE_ERROR_INFO) structure stores information about whether one or more logical block ranges contain any media errors.

## Members

### `Version`

Version of this structure. Set to **sizeof**(DEVICE_DSM_RANGE_ERROR_OUTPUT).

### `Flags`

Flags associated with the range error information. Possible values are:

| Value | Meaning |
| ----- | ------- |
| DEVICE_STORAGE_NO_ERRORS | There are no media errors in any of the requested ranges. |

### `TotalNumberOfRanges`

Number of [DEVICE_STORAGE_RANGE_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor_device_storage_range_attributes) structure(s) needed to satisfy a **DeviceDsmAction_GetRangeErrorInfo** request.

### `NumberOfRangesReturned`

Number of DEVICE_STORAGE_RANGE_ATTRIBUTES structures returned in *Ranges*.

### `Ranges`

Array of DEVICE_STORAGE_RANGE_ATTRIBUTES structure(s) in which to return media error information.

## Remarks

The output block in the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request is formatted as a DEVICE_DSM_RANGE_ERROR_OUTPUT structure when the action is **DeviceDsmAction_GetRangeErrorInfo**. See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for more details about this action.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_STORAGE_RANGE_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor_device_storage_range_attributes)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)