# DeviceDsmValidateOutputLength function

## Description

The **DeviceDsmValidateOutputLength** function validates the length of an output buffer.

## Parameters

### `Definition`

Pointer to a [DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition) structure that defines the operation.

### `OutputLength`

Length, in bytes, of the output buffer.

## Return value

**DeviceDsmValidateOutputLength** returns **TRUE** when the length of the output buffer is valid; otherwise, it returns **FALSE**.

## Remarks

The output buffer includes the [DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output) structure plus the output block that immediately follows it, if any.

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for more details on handling a DSM.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition)

[DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output)