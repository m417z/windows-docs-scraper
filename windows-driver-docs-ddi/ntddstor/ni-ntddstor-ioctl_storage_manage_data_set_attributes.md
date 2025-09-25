# IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES IOCTL

## Description

This **IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES** request is used to send a data set management request to a storage device.

## Parameters

### Major code

### Input buffer

The buffer at *Irp->AssociatedIrp.SystemBuffer* contains a [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure. Depending on the **Action** member of this structure, the input buffer might additionally include a parameter block and block of data set ranges. See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for descriptions of all possible actions.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be at least **sizeof**([DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)).

### Output buffer

Depending on the value set in the **Action** member of DEVICE_DSM_INPUT, the request may return data in the buffer at *Irp->AssociatedIrp.SystemBuffer*. The system buffer will contain valid [DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output) data if the DSM operation returns output and *Parameters.DeviceIoControl.OutputBufferLength* > 0. Depending on **Action**, the output buffer might additionally include an output block.

### Output buffer length

The length in bytes of the output buffer, if any. If output is returned, the output buffer must be at least **sizeof**([DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output)).

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_BUFFER_TOO_SMALL, STATUS_BUFFER_OVERFLOW, or some other error status.

## Remarks

Due to memory pool requirements by the storage driver stack, completion of the IRP containing this IOCTL must be at IRQL < DISPATCH_LEVEL.

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for more information.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output)