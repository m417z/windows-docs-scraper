# DeviceDsmOutputBlock function

## Description

The **DeviceDsmOutputBlock** function gets the output block from the output buffer.

## Parameters

### `Output`

Pointer to the [DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output) structure.

## Return value

Returns a pointer to the output block that immediately follows the DEVICE_DSM_OUTPUT structure that *Output* points to.

## Remarks

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for information on how to set up and process a DSM action.

## See also

[DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output)