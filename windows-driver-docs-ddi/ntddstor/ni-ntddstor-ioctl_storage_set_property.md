# IOCTL_STORAGE_SET_PROPERTY IOCTL

## Major Code: [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

A driver can use IOCTL_STORAGE_SET_PROPERTY to set the properties of a storage device or adapter.

> [!NOTE]
> Due to colliding IOCTL definitions in Windows 10 version 2004, existing software that uses IOCTL_STORAGE_SET_PROPERTY will need to be recompiled on Windows Server 2022.

## Parameters

### Major code

### Input buffer

Contains a [STORAGE_PROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_property_set) structure that describes the type of set being done, the property being set, and any additional parameters that a particular property set requires. A structure with additional properties can be found immediately after the STORAGE_PROPERTY_SET structure, depending on STORAGE_PROPERTY_SET's **PropertyId**. For example, if **PropertyId** is **StorageAdapterProtocolSpecificProperty**, then a [STORAGE_PROTOCOL_SPECIFIC_DATA_EXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext) structure immediately follows STORAGE_PROPERTY_SET.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= sizeof(STORAGE_PROPERTY_SET).

### Output buffer

Depends on the specified **PropertyId**. For example, if **PropertyId** is **StorageAdapterProtocolSpecificProperty**, then the output buffer contains a STORAGE_PROTOCOL_SPECIFIC_DATA_EXT structure with updated data from the miniport.

### Output buffer length

Size, in bytes, of the output buffer.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.
Otherwise, Status to the appropriate error condition as a NTSTATUS code.
For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also

[STORAGE_PROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_property_set)

[STORAGE_PROTOCOL_SPECIFIC_DATA_EXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext)

[STORAGE_SET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_set_type)