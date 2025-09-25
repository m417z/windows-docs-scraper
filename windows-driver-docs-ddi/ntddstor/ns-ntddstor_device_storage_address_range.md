# DEVICE_STORAGE_ADDRESS_RANGE structure

## Description

The DEVICE_STORAGE_ADDRESS_RANGE structure contains a physical address range.

## Members

### `StartAddress`

Starting address of the physical address range.

### `LengthInBytes`

Length of the physical address range, in bytes.

## Remarks

The output block in the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request is formatted as a [DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_physical_addresses_output) structure when the action is **DeviceDsmAction_GetPhysicalAddresses**. The driver returns the requested physical address ranges in an array of DEVICE_STORAGE_ADDRESS_RANGE structures. See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for more details about this action.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_physical_addresses_output)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)