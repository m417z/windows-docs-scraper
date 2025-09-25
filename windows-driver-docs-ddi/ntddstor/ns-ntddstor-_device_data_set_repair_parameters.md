# _DEVICE_DATA_SET_REPAIR_PARAMETERS structure

## Description

The DEVICE_DATA_SET_REPAIR_PARAMETERS structure specifies the parameters of a storage spaces repair operation specified for a data set management action.

This parameter structure is used in a repair action for an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request. The **Action** member of the [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure is set to **DeviceDsmAction_Repair**, and **ParameterBlockOffset** indicates the location of DEVICE_DATA_SET_REPAIR_PARAMETERS.

## Members

### `NumberOfRepairCopies`

The total number of copies to repair.

### `SourceCopy`

The source copy number.

### `RepairCopies`

An array of copy numbers for the copies to repair.

## Remarks

The **ParameterBlockOffset** and **ParameterBlockLength** members of [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) are set to the location and length of the DEVICE_DATA_SET_REPAIR_PARAMETERS structure in the system buffer of the [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request.

The **DataSetRangesOffset** and **DataSetRangesLength** members of DEVICE_DSM_INPUT specify the [DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range) structures containing the extents of the repair copies.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)