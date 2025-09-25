# IOCTL_EHSTOR_DEVICE_ENUMERATE_PDOS IOCTL

## Description

This IOCTL returns a result set containing the enumeration of all active storage Physical Device Objects (PDOs) associated with the given Addressable Command Target (ACT). The client may first probe for the required buffer size by issuing this IOCTL in the following manner:

```
DeviceIoControl(
    hDevice,
    IOCTL_EHSTOR_DEVICE_ENUMERATE_PDOS,
    &pdoType,
    sizeof(PDO_TYPE),
    NULL,
    0,
    &dwBytesRequired,
    NULL );
```

With the output buffer parameter set to **NULL**, the I/O manager clears the IRP_INPUT_OPERATION bit in the IRP flags. Upon detecting this, the storage silo driver can safely set IoStatus.Information to the required buffer size, thus indicating it to the client.

This only works because STATUS_BUFFER_OVERFLOW (0x80000005) is an NT_WARNING() value for which I/O manager copies IoStatus.Information into the lpBytesReturned parameter, returning that value to the client.

Caution is required here because IOCTL_EHSTOR_DEVICE_ENUMERATE_PDOS is defined with METHOD_BUFFERED, therefore I/O manager will attempt to copy this number of bytes into the output buffer.

## Parameters

### Major code

### Input buffer

The input buffer at Irp->AssociatedIrp.SystemBuffer must contain a ULONG value as defined in [PDO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ne-ehstorioctl-_pdo_type),

where either all of the PDOs, just the disk PDO, just the control PDO or all silo PDOs are enumerated respectively according to the provided PDO_TYPE input value.

### Input buffer length

The length of a ULONG.

### Output buffer

Irp->AssociatedIrp.SystemBuffer points to the buffer that will receive the PDO enumeration results. If the client supplied a non-**NULL** buffer with the issued IOCTL, then the driver fills it with the result set only if the Parameters.DeviceIoControl.The return value is STATUS_SUCCESS if the buffer size is sufficient and the results have been copied to the buffer. Otherwise STATUS_INVALID_BUFFER_SIZE is returned and the output buffer is unmodified.

The returned enumeration buffer contains a result set structured according to the following rules. The leading structure in the buffer, [ENUM_PDO_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_enum_pdo_results), consists of a structure count and an array of [ENUM_PDO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_enum_pdo_entry) structures.

### Output buffer length

OutputBufferLength indicates a buffer size of sufficient length to include the entire result set.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values may be returned in the Status field:

STATUS_SUCCESS - The output buffer contains the enumeration of the requested PDOs.

STATUS_BUFFER_OVERFLOW - The Information field is set to the required buffer size to contain the entire enumeration result set output.

STATUS_INVALID_BUFFER_SIZE - The output buffer length supplied is insufficient to contain the entire enumeration result set output.