# DeviceDsmParameterBlock function

## Description

The **DeviceDsmParameterBlock** function gets the parameter block for a data set management (DSM) operation.

## Parameters

### `Input`

Pointer to a [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure.

## Return value

**DeviceDsmParameterBlock** returns a pointer to the parameter block that immediately follows the DEVICE_DSM_INPUT structure.

## Remarks

The DSM handler calls this function only if the members of *Input* indicate that the operation has a parameter block. See [Data Set Management](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for details on how to process a DSM.

## See also

[Data Set Management](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)