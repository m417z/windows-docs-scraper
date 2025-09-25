# _DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT structure

## Description

The **DEVICE_DSM_OUTPUT** (or DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT) structure describes output for [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) requests for some data set management actions.

## Members

### `Size`

Size of this structure, in bytes. Set this member to **sizeof**(DEVICE_DSM_OUTPUT).

### `Action`

DEVICE_DSM_ACTION value that specifies the action related to the instance of this structure. See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for a list of values and action descriptions.

### `Flags`

Flags for the data set management action. See the **Flags** member of [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes).

### `OperationStatus`

Status resulting from the operation performed for **Action**.

### `ExtendedError`

An extended error value originating from Windows or a driver.

### `TargetDetailedError`

An error value resulting from a failure execute the operation for **Action** at the target.

### `ReservedStatus`

Reserved.

### `OutputBlockOffset`

The position, after the beginning of this structure, where action-specific data is located.

### `OutputBlockLength`

The length of the action-specific data, in bytes.

## Remarks

Depending on the value of **Action**, an output block is written at an offset of **OutputBlockOffset** after the beginning of this structure. The size of the output block is specified in **OutputBlockLength**.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DATA_SET_LB_PROVISIONING_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_lb_provisioning_state)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)