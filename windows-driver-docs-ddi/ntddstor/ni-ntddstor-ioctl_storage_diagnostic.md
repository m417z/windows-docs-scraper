## Description

**IOCTL_STORAGE_DIAGNOSTIC** is used to query diagnostic data from the storage driver stack.

## Parameters

### Major code

### Input buffer

[**Irp->AssociatedIrp.SystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) contains a [**STORAGE_DIAGNOSTIC_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_diagnostic_request) structure that describes the diagnostic request being made about the storage driver stack.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= ```sizeof(STORAGE_DIAGNOSTIC_REQUEST)```.

### Output buffer

The driver returns output to the buffer at **Irp->AssociatedIrp.SystemBuffer**. This buffer contains a [**STORAGE_DIAGNOSTIC_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_diagnostic_data) structure with diagnostic data about the storage driver stack.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= ```sizeof(STORAGE_DIAGNOSTIC_DATA)```.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** is set to the appropriate error condition as a NTSTATUS code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## See also

[**STORAGE_DIAGNOSTIC_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_diagnostic_data)

[**STORAGE_DIAGNOSTIC_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_diagnostic_request)