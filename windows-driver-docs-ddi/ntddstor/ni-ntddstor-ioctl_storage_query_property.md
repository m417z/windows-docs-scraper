# IOCTL_STORAGE_QUERY_PROPERTY IOCTL

## Description

A driver can use **IOCTL_STORAGE_QUERY_PROPERTY** to return properties of a storage device or adapter. The request indicates the kind of information to retrieve, such as inquiry data for a device or capabilities and limitations of an adapter. **IOCTL_STORAGE_QUERY_PROPERTY** can also be used to determine whether the port driver supports a particular property or which fields in the property descriptor can be modified with a subsequent change-property request.

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= **sizeof**([**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)).

**Irp->AssociatedIrp.SystemBuffer** contains [**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query) data that specifies whether to query the device or the adapter, the type of query to perform, and any additional parameters required for the query, such as the page code for a particular SCSI mode sense page. Device properties must be retrieved only from a device; attempting to retrieve device properties from an adapter will cause an error.

**Parameters.DeviceIoControl.OutputBufferLength** indicates the number of bytes that can be written to **Irp->AssociatedIrp.SystemBuffer**. **OutputBufferLength** can be zero to determine whether a property exists without retrieving its data.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= **sizeof**([**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)).

### Output buffer

The driver returns query data to the buffer at **Irp->AssociatedIrp.SystemBuffer**. Varying amounts of bus-specific data can be appended to the structure.

### Output buffer length

Cast the structure returned to a [**STORAGE_DESCRIPTOR_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_descriptor_header) and check its **Size** member to determine the number of bytes the structure actually requires.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_INVALID_PARAMETER, or STATUS_NOT_SUPPORTED.

## See also

[**STORAGE_DESCRIPTOR_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_descriptor_header)

[**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)

[**STORAGE_RPMB_DATA_FRAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_rpmb_data_frame)