# DeviceDsmInitializeOutput function

## Description

The **DeviceDsmInitializeOutput** function initializes a [DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output) structure.

## Parameters

### `Definition`

Pointer to a [DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition) structure that defines the data set management (DSM) operation.

### `Output`

Pointer to the [DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output) structure to be initialized.

### `OutputLength`

The length, in bytes, of the entire output buffer.

### `Flags`

Flags for the DSM action in the DEVICE_DSM_OUTPUT structure.

## Remarks

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for information on how to process a DSM.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition)

[DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output)