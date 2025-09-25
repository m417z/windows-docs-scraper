# DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT structure

## Description

The DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT structure stores physical address ranges that correspond with one or more logical block ranges.

## Members

### `Version`

Version of this structure. Set to **sizeof**(DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT).

### `Flags`

Reserved for future use; do not use.

### `TotalNumberOfRanges`

Number of [DEVICE_STORAGE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor_device_storage_address_range) structure(s) needed to satisfy a **DeviceDsmAction_GetPhysicalAddresses** request.

### `NumberOfRangesReturned`

Number of physical address ranges returned in *Ranges*.

### `Ranges`

Array of DEVICE_STORAGE_ADDRESS_RANGE structure(s) in which to return physical address ranges.

## Remarks

The output block in the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request is formatted as a DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT structure when the action is **DeviceDsmAction_GetPhysicalAddresses**. See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for more details about this action.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_STORAGE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor_device_storage_address_range)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)